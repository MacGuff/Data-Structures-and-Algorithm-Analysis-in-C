#ifndef STACK_H
#define STACK_H

struct _stack;
typedef struct _stack stack;

void init(stack **s);
int is_empty(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int peek(stack *s);

#endif