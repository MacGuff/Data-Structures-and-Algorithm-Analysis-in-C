#include <stdio.h>
#include "list.h"

#define MAXSIZE 1000
static struct node *a[MAXSIZE];
int top = 0;

void push(struct node *n)
{
	a[++top] = n;
}

struct node *pop()
{
	return a[top--];
}

/*O(n)时间反转单链表，需要额外O(n)空间的栈*/
void reverse_list_v1(struct node **head)
{
	struct node *cur, *prev;
	prev = NULL;
	cur = *head;

	while (cur != NULL) {
		push(prev);
		prev = cur;
		cur = cur->next;
	}

	*head = cur = prev;
	while (cur != NULL ) {
		cur->next = pop();
		cur = cur->next;
	}
}

/*O(n)时间反转单链表，需要常数空间*/
void reverse_list_v2(struct node **head)
{
	struct node *prev, *cur, *next;

	prev = NULL;
	cur = *head;
	next = cur->next;

	while (next != NULL) {
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}
	cur->next = prev;
	*head = cur;

}

int main()
{
	struct node *head = NULL;

	for (int i = 0; i < 20; ++i) {
		append(&head, i);
	}

	printf("created list:");
	print_list(head);
	printf("\n");

	reverse_list_v2(&head);
	printf("\nreversed list:");
	print_list(head);
	printf("\n");

	reverse_list_v2(&head);
	printf("\nreversed list:");
	print_list(head);
	printf("\n");

	return 0;
}