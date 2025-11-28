#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__

#define LOG_BUFSIZE 1024
#define ITRACE_SIZE 64
typedef struct 
{
   char *buffer;
   int start;
   int end;
   int mask;
} RingBuffer;

extern RingBuffer *log_buff;

// length must be power of 2
RingBuffer *RingBuffer_create(int power_of_two);
void RingBuffer_destroy (RingBuffer* rb);

// without move start 
int RingBuffer_read(RingBuffer *buffer, char* target, int amount);
// without move end
int RingBuffer_write(RingBuffer *buffer, char* data, int length);

int RingBuffer_put(RingBuffer *buffer, char* data, int length);
int RingBuffer_get(RingBuffer *buffer, char* target, int length);

int RingBuffer_empty(RingBuffer *buffer);
int RingBuffer_full(RingBuffer *buffer);
int RingBuffer_capacity(RingBuffer *buffer);
int RingBuffer_length(RingBuffer *buffer);
int RingBuffer_available(RingBuffer *buffer);

#define RingBuffer_capacity(B) ((B)->mask+1)
#define RingBuffer_length(B) ((((B)->end - (B)->start) & (B)->mask)+1) 

#define RingBuffer_available(B) (\
    (B)->mask -  RingBuffer_length((B)))

#define RingBuffer_full(B) (RingBuffer_length((B))\
    == RingBuffer_capacity(B))

#define RingBuffer_empty(B) (RingBuffer_length((B))==0)

/* #define RingBuffer_puts(B,D,L) RingBuffer_write( \
     (B), bdata((D)), blength((D)))

 #define RingBuffer_get_all(B) RingBuffer_gets( \
     (B), RingBuffer_available_data((B))) */

#define RingBuffer_starts_at(B) (\
    (B)->buffer + (B)->start)

#define RingBuffer_ends_at(B) (\
    (B)->buffer + (B)->end)

#define RingBuffer_commit_read(B, A) (\
    (B)->start = ((B)->start+(A))&(B)->mask)

#define RingBuffer_commit_write(B, A) (\
    (B)->end = ((B)->end+(A))&(B)->mask)
      
#endif
