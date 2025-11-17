#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 16 

typedef struct Node {
    char message[128];
    struct Node* next; 
} Node;

typedef struct ringbuffer {
    Node* head;
    Node* tail;
    int count;
} ringbuffer;

void init_ringbuffer(ringbuffer* rb);
void pop_ringbuffer(ringbuffer* rb);
void push_ringbuffer(ringbuffer* rb, char* s);
void destroy_ringbuffer(ringbuffer *rb);
void print_ringbuffer(ringbuffer *rb);
