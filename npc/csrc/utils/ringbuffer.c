#include <stdlib.h>
#include <string.h>
#include <ringbuffer.h>

static inline size_t min(size_t a, size_t b) {
    return a > b ? b : a; 
}

RingBuffer *RingBuffer_create(int power_of_two){
    RingBuffer *buffer = (RingBuffer*)calloc(1,sizeof(RingBuffer));
    buffer->mask = power_of_two-1;
    buffer->buffer = (char*)calloc(buffer->mask,1);
    memset(buffer->buffer,0,buffer->mask);
    buffer->start = buffer->end = 0;
    return buffer;
}

void RingBuffer_destroy(RingBuffer * buffer){
    if(buffer){
        free(buffer->buffer);
        free(buffer);
    }
}

int RingBuffer_write(RingBuffer *buffer,char *data,int length){
    if (RingBuffer_length(buffer) == 0){
        buffer->start = buffer->end = 0;
    }
    length = min(length,RingBuffer_available(buffer));
    size_t l = min(length,RingBuffer_capacity(buffer)-buffer->end);
    memcpy(RingBuffer_ends_at(buffer),data,l);
    memcpy(buffer->buffer,data+l,length-l);
    return length;
}

int RingBuffer_put(RingBuffer *buffer,char *data,int length){
    length = RingBuffer_write(buffer,data,length);
    RingBuffer_commit_write(buffer,length);
    return length;
}

int RingBuffer_read(RingBuffer *buffer,char *target,int length){
    if (RingBuffer_length(buffer) == 0){
        return 0;
    }
    length = min(length,RingBuffer_length(buffer));
    size_t l = min(length,RingBuffer_capacity(buffer)-buffer->start);
    memcpy(target,RingBuffer_starts_at(buffer),l);
    memcpy(target+l,buffer->buffer,length-l);
    return length;
}

int RingBuffer_get(RingBuffer *buffer,char *target,int length){
    length = RingBuffer_read(buffer,target,length);
    RingBuffer_commit_read(buffer,length);
    return length;
}