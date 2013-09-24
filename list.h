#ifndef __LIST_H__
#define __LIST_H__

/* your list data structure declarations */

struct node{
	int integer;
	struct node *next;
};

/* your function declarations associated with the list */

void list_insert(int, struct node **);
void list_print(struct node **);
void list_clear(struct node*);

#endif // __LIST_H__
