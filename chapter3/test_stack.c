#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
	int k;
	char c;
	stack *s;
	init(&s);

	while (scanf("%1s", &c)) {
		switch (c) {
		case 'p': // push
			scanf("%d", &k);
			push(s, k);
			printf("push %d to stack\n", k);
			break;
		case 'P': //pop
			printf("pop %d from stack\n", pop(s));
			break;
		case 't': //peek
			printf("top item is %d\n", peek(s));
			break;
		default:
			printf("unknown word:%c\n", c);
			break;
		}
	}

	return 0;
}