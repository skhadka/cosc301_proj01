#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* your list function definitions */

struct node {
	int integer;
	struct node *next;
};

void list_insert(int num, struct node **head) {
	struct node * newnode = malloc(sizeof(Struct node));
	newnode->integer = num;
	newnode->next = *head;
	*head = newnode;
}

void list_print(struct node **head) {
	struct node * current = *head;
	while(current!=NULL) {
		printf("%d", current->integer);
		current = current->next;
	}
}

