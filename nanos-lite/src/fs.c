#include <fs.h>
#include "strace.h"
typedef size_t (*ReadFn)(void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn)(const void *buf, size_t offset, size_t len);
extern size_t ramdisk_read(void *buf, size_t offset, size_t len);
extern size_t ramdisk_write(const void *buf, size_t offset, size_t len);
typedef struct
{
	char *name;
	size_t size;
	size_t disk_offset;
	ReadFn read;
	WriteFn write;
	size_t cursor;
	// Current position in the file
} Finfo;

enum
{
	FD_STDIN,
	FD_STDOUT,
	FD_STDERR,
	FD_EVENTS,
	FD_FBCTL,
	FD_FB,
	FD_DISPINFO,
};
size_t invalid_read(void *buf, size_t offset, size_t len)
{
	panic("should not reach here");
	return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len)
{
	panic("should not reach here");
	return 0;
}

extern size_t serial_write(const void *buf, size_t offset, size_t len);
extern size_t fb_write(const void *buf, size_t offset, size_t len);
extern size_t events_read(void *buf, size_t offset, size_t len);
extern size_t dispinfo_read(void *buf, size_t offset, size_t len);
/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
	[FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
	[FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
	[FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
	[FD_EVENTS] = {"/dev/events", 0, 0, events_read, invalid_write},
	[FD_FB] = {"/dev/fb", 0, 0, invalid_read, fb_write},
	[FD_FBCTL] = {"/dev/fbctl", 0, 0, invalid_read, invalid_write},
	[FD_DISPINFO] = {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write},
#include "files.h"
};

int fs_open(const char *pathname, int flags, int mode)
{
	for (int i = 0; i < sizeof(file_table) / sizeof(Finfo); i++)
	{
		if (strcmp(pathname, file_table[i].name) == 0)
		{
			return i; // Return the index as the file descriptor
		}
	}
	// return -1;
	// if want to enable file finding, please uncomment this line
	// for the convenience of debugging, we will panic here
	panic("open: file '%s' at address %p not found,memory coverage may be wrong", pathname, pathname);
	return -1; // File not found
}
size_t fs_read(int fd, void *buf, size_t len)
{
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("read: invalid file descriptor");
	}
	if (file_table[fd].read == invalid_read)
	{
		return 0;
	}
	CASE_LOG("read: reading %u bytes from file descriptor %d", len, fd);
	if (fd > 6)
	{
		if (file_table[fd].cursor + len > file_table[fd].size)
		{
			len = file_table[fd].size - file_table[fd].cursor; // Adjust length if it exceeds file size
		}
		if (len == 0)
		{
			return 0; // No more data to read
		}
	}
	size_t bytes_read = file_table[fd].read(buf, file_table[fd].disk_offset + file_table[fd].cursor, len);
	file_table[fd].cursor += len; // Update cursor position
	return bytes_read;			  // Return the number of bytes read
}
size_t fs_write(int fd, const void *buf, size_t len)
{
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("write: invalid file descriptor");
	}
	if (file_table[fd].write == invalid_write)
	{
		return 0;
	}
	CASE_LOG("write: writing %u bytes to file descriptor %d", len, fd);
	if (fd > 6)
	{
		if (file_table[fd].cursor + len > file_table[fd].size)
		{
			len = file_table[fd].size - file_table[fd].cursor; // Adjust length if it exceeds file size
		}
		if (len == 0)
		{
			return 0; // No more data to read
		}
	}
	size_t bytes_written = file_table[fd].write(buf, file_table[fd].disk_offset + file_table[fd].cursor, len);
	file_table[fd].cursor += len;
	return bytes_written; // Return the number of bytes written
}
size_t fs_lseek(int fd, size_t offset, int whence)
{

	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("lseek: invalid file descriptor");
	}
	if (fd <= 2) // stdin, stdout, stderr
	{
		return 0; // No seek for stdin/stdout/stderr
	}
	CASE_LOG("lseek: seeking in file descriptor %d with offset %u and whence %d", fd, offset, whence);
	switch (whence)
	{
	case SEEK_SET:
		file_table[fd].cursor = offset; // Set cursor to the specified offset
		return offset;					// Return the new position
		break;
	case SEEK_CUR:
		file_table[fd].cursor += offset; // Move cursor by the specified offset
		return file_table[fd].cursor;	 // Return the new position
		break;
	case SEEK_END:
		file_table[fd].cursor = file_table[fd].size + offset; // Set cursor to the end plus offset
		return file_table[fd].cursor;						  // Return the new position
		break;
	default:
		panic("lseek: invalid whence");
		return -1;
		break;
	}
}
int fs_close(int fd)
{
	CASE_LOG("close: closing file descriptor %d", fd);
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("close: invalid file descriptor");
	}
	file_table[fd].cursor = 0; // Reset cursor to 0
	return 0;
}
void init_fs()
{
	// TODO: initialize the size of /dev/fb
	Log("Initializing file system...");
	for (int i = 0; i < sizeof(file_table) / sizeof(Finfo); i++)
	{
		file_table[i].cursor = 0; // Initialize cursor to 0
		if (file_table[i].read == NULL)
		{
			file_table[i].read = ramdisk_read;
		}
		if (file_table[i].write == NULL)
		{
			file_table[i].write = ramdisk_write;
		}
	}
}
