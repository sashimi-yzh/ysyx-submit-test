#include "ringbuffer.h"

void init_ringbuffer(ringbuffer* rb){
    rb->count = 0;
    rb->head = NULL;
    rb->tail = NULL;
}

void pop_ringbuffer(ringbuffer* rb){
    if (rb->head == NULL) return;

    Node* tmp;
    tmp = rb->head;
    rb->head = (rb->head)->next;

    if (rb->head == NULL) {
		rb->tail = NULL;
	}

    rb->count--;
    free(tmp);
}

void push_ringbuffer(ringbuffer* rb, char* s){
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->next = NULL;

    strncpy(new_node->message, s, sizeof(new_node->message)-1);
    new_node->message[sizeof(new_node->message) - 1] = '\0';
    if(rb->count == BUFFER_SIZE){
        pop_ringbuffer(rb);
    }
    if(rb->count == 0){
        rb->head = new_node;
        rb->tail = new_node;
    }else{
        rb->tail->next = new_node;
        rb->tail = new_node;
    }
    rb->count++;
}

void destroy_ringbuffer(ringbuffer *rb){
	while( rb->count > 0 ) {
		pop_ringbuffer(rb);
	}
}

void print_ringbuffer(ringbuffer *rb){
	Node *temp = rb->head;
	for (int i = 0; i < rb->count; i++) {
		if(i == rb->count - 1) {
			printf(" ---> ");
		} else {
			printf("      ");
		}
 
		printf("%s\n", temp->message);
		temp = temp->next;	
	}
}
