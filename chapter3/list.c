#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/*
*不含头结点的list
*/
struct node {
	int data;
	struct node *next;
};

int is_empty(struct node *list)
{
	return list == NULL;
}

/*查找值为x的节点，找到返回对应位置的指针，否则返回NULL*/
struct node *find(struct node *list, int x)
{
	struct node *pos;

	pos = list;
	while (pos != NULL && pos->data != x)
		pos = pos->next;

	return pos;
}
/*假设pos不是头结点*/
static struct node *find_pre(struct node *list, struct node *pos)
{
	struct node *cur;

	assert(pos != list);
	cur = list;
	while (cur->next != pos)
		cur = cur->next;

	return cur;
}

/*inserts a new node on the front of the list*/
void push(struct node **list, int x)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));

	new->data = x;
	new->next = *list;
	*list = new;
}

/* Given a node pos, insert a new node after the given
  pos node */
void insert_after(struct node *list, struct node *pos, int x)
{
	assert(pos != NULL);
	struct node *new = malloc(sizeof(struct node));

	new->data = x;
	new->next = pos->next;
	pos->next = new;
}

void append(struct node **list, int x)
{
	struct node *last, *new;

	new = (struct node *)malloc(sizeof(struct node));
	new->data = x;
	new->next = NULL;
	if (*list == NULL) {
		*list = new;
		return;
	}

	last = *list;
	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new;
}

void delete(struct node **list, int x)
{
	struct node *pos, *prev;

	pos = find(*list, x);
	if (pos) { /*找到节点*/
		if (pos != *list) { /*不是头结点*/
			prev = find_pre(*list, pos);
			prev->next = pos->next;
		} else
			*list = pos->next;
		free(pos);
	}

}

void delete_list(struct node *list)
{
	struct node *p, *tmp;
	p = list;
	while (p != NULL) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}

void print_list(struct node *list)
{
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
}

int main(void)
{
	struct node *head = NULL;
	append(&head, 5);
	append(&head, 6);

	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insert_after(head, head, 8);
	printf("\nCreated Linked list is: ");
	print_list(head);

	delete(&head, 6);

	delete(&head, 1);
	delete(&head, 10);
	printf("\nDeleted Linked list is: ");
	print_list(head);
	return 0;
}
