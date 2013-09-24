#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_insert(int num, struct node **head) {
	//put num in head in sorted order
	struct node * newnode = malloc(sizeof(struct node));
	newnode->integer = num;

	if (*head==NULL) {//empty initialize
			newnode->next = *head;
			*head = newnode;
			return;
	} 
	struct node *previous;
	struct node *trial = *head;
	while(trial!=NULL) {
		//previous = NULL;
		if ((num < (trial->integer)) && previous==NULL) {//add least no. to the beginning of the list so update head
			newnode->next = trial;
			*head = newnode;
			return;
		}
		
		if (num < (trial->integer)) {//add lesser number to the left
			newnode->next = trial;
			previous->next = newnode;
			return;
		}
	previous = trial;
	trial = trial->next;
	}

	if (trial==NULL) previous->next = newnode; //have to append to the end
}

void list_print(struct node **head) {
	struct node * current = *head;
	while(current!=NULL) {
		printf("\n%d", current->integer);
		current = current->next;
	}
}

void list_clear(struct node * head) {
	while(head!=NULL) {
		struct node * trial = head;
		head = head->next;
		free(trial);	
	}
}


