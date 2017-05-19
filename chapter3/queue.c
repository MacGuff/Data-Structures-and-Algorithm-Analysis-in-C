#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*队列的数组实现*/

#define CAPACITY 1024
struct _queue {
	int size;
	int front;
	int rear;
	int a[CAPACITY];
};

queue *create_queue()
{
	queue *q = (queue *)malloc(sizeof(queue));
	q->size = 0;
	q->front = 0;
	q->rear = -1;
}

int is_full(queue *q)
{
	return q->size == CAPACITY;
}

int is_empty(queue *q)
{
	return q->size == 0;
}

void enqueue(queue *q, int item)
{
	if (is_full(q)) {
		printf("queue overflow!\n");
		exit(EXIT_FAILURE);
	} else {
		q->rear = (q->rear + 1) % CAPACITY;
		q->a[q->rear] = item;
		q->size++;
	}
}

int dequeue(queue *q)
{
	int item;
	if (is_empty(q)) {
		printf("queue underflow!\n");
		exit(EXIT_FAILURE);
	} else {
		item = q->a[q->front];
		q->front = (q->front + 1) % CAPACITY;
		q->size--;
		return item;
	}
}

int front(queue *q)
{
	return q->a[q->front];
}

int rear(queue *q)
{
	return q->a[q->rear];
}