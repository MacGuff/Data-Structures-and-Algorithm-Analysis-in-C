#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue queue;

queue *create_queue();
int is_full(queue *q);
int is_empty(queue *q);

void enqueue(queue *q, int item);
int dequeue(queue *q);

int front(queue *q);
int rear(queue *q);
#endif