#include <stdio.h>

#include "list.h"
int main()
{
	struct node *head = NULL;
	int item;
	char c;
	while (scanf("%1s %d", &c, &item) == 2) {
		switch (c) {
		case 'p':
			push(&head, item);
			printf("add %d at head\n", item);
			break;
		case 'a':
			append(&head, item);
			printf("add %d at tail\n", item);
			break;
		case 'd':
			if (find(head, item)) {
				delete(&head, item);
				printf("delete %d from list\n", item);
			}
			break;
		case 'f':
			if (find(head, item))
				printf("%d founed in list\n", item);
			else
				printf("%d not founed in list\n", item);
			break;
		case 'P':
			print_list(head);
			break;
		default:
			printf("unrecognized cmmand: %c\n", c);
			break;
		}
	}

	return 0;
}