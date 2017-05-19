#ifndef STACK_H
#define STACK_H

struct _stack;
typedef struct _stack stack;

stack *create_stack();
int is_empty(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int peek(stack *s);

#endif