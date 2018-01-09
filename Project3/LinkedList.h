
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{
/*Defines type for node*/ 
	void * next;
	void * data;
} Node;

typedef struct{
/*Defines type for linked list*/
	Node * head;
	Node * tail; 
	int size;
} LinkedList;

LinkedList *ll_create();

void ll_push(LinkedList *l, void *data);

void *ll_pop(Linked List *l);

void ll_append(LinkedList *l, void *data);

void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

int ll_size(LinkedList *l);

void ll_clear(LinkedList *l, void (*freefunc)(void *));

void ll_map(LinkedList *l, void (*mapfunc)(void *));

void delete(LinkedList *l, int index);



