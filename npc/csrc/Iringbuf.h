#ifndef IRINGBUF_H
#define IRINGBUF_H
#define MAX_INSTS 32
#define INST_STR_SIZE 64
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
class Iringbuf
{
public:
	void push_iringbuf(char *str)
	{
		strcpy(buf[tail], str);
		tail = (tail + 1) % (MAX_INSTS + 1);
		if (tail == head)
			head = (head + 1) % (MAX_INSTS + 1);
	}
	void print_iringbuf()
	{
		int temp_head = head;
		int temp_tail = tail;
		for (; temp_head != temp_tail; temp_head = (temp_head + 1) % (MAX_INSTS + 1))
		{
			if ((temp_head + 1) % (MAX_INSTS + 1) == temp_tail)
				printf("last inst: ");
			else
				printf("     inst: ");
			printf("%s", buf[temp_head]);
		}
	}

private:
	int head = 0;
	int tail = 0;
	char buf[MAX_INSTS + 1][INST_STR_SIZE];
};

#endif