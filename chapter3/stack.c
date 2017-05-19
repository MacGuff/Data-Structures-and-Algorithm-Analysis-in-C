#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/* 栈的数组实现*/
#define MAXSIZE 1024
struct _stack {
	int top;
	int a[MAXSIZE];
};

void init(stack **s)
{
	*s = (struct _stack*)malloc(sizeof(struct _stack));
	(*s)->top = 0;
}

int is_empty(stack *s)
{
	return s->top == 0;
}

void push(stack *s, int x)
{
	if (s->top >= MAXSIZE) {
		printf("stack overflow!\n");
		exit(EXIT_FAILURE);
	} else
		s->a[s->top++] = x;
}

int pop(stack *s)
{
	if (s->top <= 0) {
		printf("stack underflow!\n");
		exit(EXIT_FAILURE);
	} else
		return s->a[--s->top];
}

int peek(stack *s)
{
	return s->a[s->top - 1];
}