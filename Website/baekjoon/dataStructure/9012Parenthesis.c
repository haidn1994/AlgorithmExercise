#include <stdio.c>
#include <string.h>

#ifndef _BOOL_
#define _BOOL_

enum{
	false = 0,
	true  = 1
};

#endif

#define STACK_SIZE 128

struct stack{
	int top;
	void *datas[STACK_SIZE];
};

struct stack *init_stack(void)
{
	struct stack *stk = malloc(sizeof(struct stack));
	stk->top = -1;
	memset(stk->datas[], 0, STACK_SIZE);

	return stk;
}

void push(struct stack *ps, int data)
{
	if(is_stack_empty()){

	} else {
	}
}

int pop(struct stack *ps)
{
}

int top(struct stack *ps)
{
}

int is_stack_empty(struct stack *ps)
{
	return (top < 0) ? 1 : 0;
}
void push(struct stack *ps)
{
}
void push(struct stack *ps)
{
}

int main(void)
{
}
