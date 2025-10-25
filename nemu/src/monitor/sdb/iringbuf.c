#ifndef IRINGBUF_H
#define IRINGBUF_H
#define MAX_INSTS 32
#define INST_STR_SIZE 64
#include <common.h>
struct iringbuf
{
	int head;
	int tail;
	char **buf;
} typedef iringbuf;
static iringbuf *irb = NULL;
void init_iringbuf()
{
	irb = (iringbuf *)malloc(sizeof(struct iringbuf));
	irb->head = 0;
	irb->tail = 0;
	irb->buf = (char **)malloc(sizeof(char *) * (MAX_INSTS + 1));
	for (int i = 0; i < MAX_INSTS + 1; i++)
	{
		irb->buf[i] = (char *)malloc(INST_STR_SIZE);
	}
}
void push_iringbuf(char *str)
{
	assert(irb != NULL);
	strcpy(irb->buf[irb->tail], str);
	irb->tail = (irb->tail + 1) % (MAX_INSTS + 1);
	if (irb->tail == irb->head)
		irb->head = (irb->head + 1) % (MAX_INSTS + 1);
}
void print_iringbuf()
{
	assert(irb != NULL);
	int head = irb->head;
	int tail = irb->tail;
	for (; head != tail; head = (head + 1) % (MAX_INSTS + 1))
	{
		if ((head + 1) % (MAX_INSTS + 1) == tail)
			printf("last inst: ");
		else
			printf("     inst: ");
		printf("%s\n", irb->buf[head]);
	}
}

#endif