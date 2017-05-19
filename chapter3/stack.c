#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/* 栈的数组实现*/
#define MAXSIZE 1024
struct _stack {
	int top;
	int a[MAXSIZE];
};

stack *create_stack()
{
	stack *s;
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;

	return s;
}

int is_empty(stack *s)
{
	return s->top == -1;
}

void push(stack *s, int x)
{
	if (s->top == MAXSIZE - 1) {
		printf("stack overflow!\n");
		exit(EXIT_FAILURE);
	} else
		s->a[++s->top] = x;
}

int pop(stack *s)
{
	if (s->top < 0) {
		printf("stack underflow!\n");
		exit(EXIT_FAILURE);
	} else
		return s->a[s->top--];
}

int peek(stack *s)
{
	return s->a[s->top];
}