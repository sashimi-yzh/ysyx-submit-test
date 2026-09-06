#include "isa.h"
#include "memory/paddr.h"
#include "stdio.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "sdb.h"

const char *default_file_name = "nemu-snapshot";

// in the case of use img different version
enum { SNAPSHOT_VERSION = 1 };

typedef struct {
  char magic[8];
  uint32_t version;
  uint32_t cpu_state_size;
  uint64_t mem_base;
  uint64_t mem_size;
} snapshot_header_t;

static void set_snapshot_header(snapshot_header_t *header) {
  memcpy(header->magic, "NEMUSNAP", sizeof(header->magic));
  header->version = SNAPSHOT_VERSION;
  header->cpu_state_size = sizeof(CPU_state);
  header->mem_base = CONFIG_MBASE;
  header->mem_size = CONFIG_MSIZE;
}

static bool check_snapshot_header(const snapshot_header_t *header) {
  if (memcmp(header->magic, "NEMUSNAP", sizeof(header->magic)) != 0) {
    printf("[Error] snap_load: unsupported legacy snapshot format; "
           "please create a new snapshot\n");
    return false;
  }

  if (header->version != SNAPSHOT_VERSION) {
    printf("[Error] snap_load: unsupported snapshot version %u\n",
           header->version);
    return false;
  }

  if (header->cpu_state_size != sizeof(CPU_state)) {
    printf("[Error] snap_load: CPU state size mismatch, file = %u, "
           "current = %zu\n",
           header->cpu_state_size, sizeof(CPU_state));
    return false;
  }

  if (header->mem_base != CONFIG_MBASE || header->mem_size != CONFIG_MSIZE) {
    printf("[Error] snap_load: memory layout mismatch, file = [0x%llx, "
           "0x%llx), current = [0x%llx, 0x%llx)\n",
           (unsigned long long)header->mem_base,
           (unsigned long long)(header->mem_base + header->mem_size),
           (unsigned long long)CONFIG_MBASE,
           (unsigned long long)(CONFIG_MBASE + CONFIG_MSIZE));
    return false;
  }

  return true;
}

static char *get_fin_filename(const char *filename) {
  if (filename == NULL || *filename == '\0') {
    char *buf = malloc(strlen(default_file_name) + 4);
    return buf ? (sprintf(buf, "./%s", default_file_name), buf) : NULL;
  }

  struct stat st;
  if (stat(filename, &st) != 0) {
    perror("stat");
    return NULL;
  }

  if (S_ISDIR(st.st_mode)) {
    size_t n = strlen(filename) + strlen(default_file_name) + 3;
    char *buf = malloc(n);
    return buf && snprintf(buf, n, "%s/%s", filename, default_file_name) > 0
               ? buf
               : (free(buf), NULL);
  }
  if (S_ISREG(st.st_mode)) {
    return strdup(filename);
  }

  fprintf(stderr, "[Error] %s: neither file nor directory\n", filename);
  return NULL;
}

int snap_store(const char *filename) {
  char *final_name = get_fin_filename(filename);
  if (final_name == NULL) {
    printf("[Error] snap store cannot get the final name\n");
    return 1;
  }
  printf("Snapshot file name: %s\n", final_name);

  FILE *fd = fopen(final_name, "wb");
  if (fd == NULL) {
    printf("[Error] snapshot cannot open file %s\n", final_name);
    free(final_name);
    return 1;
  }

  snapshot_header_t header = {};
  set_snapshot_header(&header);
  if (fwrite(&header, sizeof(header), 1, fd) != 1) {
    printf("[Error] snapshot: failed to write snapshot header\n");
    fclose(fd);
    free(final_name);
    return 1;
  }

  if (fwrite(&cpu, sizeof(CPU_state), 1, fd) != 1) {
    printf("[Error] snapshot: failed to write CPU state\n");
    fclose(fd);
    free(final_name);
    return 1;
  }

  if (fwrite(guest_to_host(CONFIG_MBASE), 1, CONFIG_MSIZE, fd) !=
      CONFIG_MSIZE) {
    printf("[Error] snapshot: failed to write memory\n");
    fclose(fd);
    free(final_name);
    return 1;
  }

  fclose(fd);
  free(final_name);
  return 0;
}

int snap_load(const char *filename) {
  char *final_name = get_fin_filename(filename);
  if (final_name == NULL) {
    printf("[Error] snap load cannot get the final name\n");
    return 1;
  }

  FILE *fd = fopen(final_name, "rb");
  if (fd == NULL) {
    fprintf(stderr, "[Error] snap_load: cannot open file %s\n", final_name);
    free(final_name);
    return 1;
  }

  snapshot_header_t header = {};
  if (fread(&header, sizeof(header), 1, fd) != 1) {
    printf("[Error] snap_load: failed to read snapshot header\n");
    fclose(fd);
    free(final_name);
    return 1;
  }

  if (!check_snapshot_header(&header)) {
    fclose(fd);
    free(final_name);
    return 1;
  }

  CPU_state loaded_cpu = {};
  if (fread(&loaded_cpu, sizeof(CPU_state), 1, fd) != 1) {
    printf("[Error] snap_load: failed to read CPU state\n");
    fclose(fd);
    free(final_name);
    return 1;
  }

  /* 2. 读入内存 */
  if (fread(guest_to_host(CONFIG_MBASE), 1, CONFIG_MSIZE, fd) != CONFIG_MSIZE) {
    printf("[Error] snap_load: failed to read memory\n");
    fclose(fd);
    free(final_name);
    return 1;
  }

  cpu = loaded_cpu;

  fclose(fd);
  free(final_name);
  return 0;
}
