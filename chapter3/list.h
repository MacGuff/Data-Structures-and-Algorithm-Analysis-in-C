#ifndef LIST_H
#define LIST_H

#include <stddef.h>

struct node;

int is_empty(struct node *list);

struct node *find(struct node *list, int x);
/**************insert********************/
void push(struct node **list, int x);
void insert_after(struct node *list, struct node *pos, int x);
void append(struct node **list, int x);
/**************delete********************/
void delete(struct node **list, int x);
void delete_list(struct node *list);
void print_list(struct node *list);

#endif