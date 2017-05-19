#include <stdio.h>

#include "queue.h"

int main()
{
	int k;
	char c;
	queue *q = create_queue();

	while (scanf("%1s", &c)) {
		switch (c) {
		case 'e':
			scanf("%d", &k);
			enqueue(q, k);
			printf("%d enqueued to queue\n", k);
			break;
		case 'd':
			printf("%d dequeued to queue\n", dequeue(q));
			break;
		case 'f':
			printf("front item is %d\n", front(q));
			break;
		case 'r':
			printf("rear itrem is %d\n", rear(q));
			break;
		default:
			printf("unknown command: %c\n", c);
			break;
		}
	}


	return 0;
}