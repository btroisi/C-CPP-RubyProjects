

#include <stdio.h>
#include <stdlib.h>



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

LinkedList *ll_create(); //Creates new LinkedList struct, initializes it and returns it

void ll_push(LinkedList *l, void *data); //Adds node to front of list, storing data in new node 

void *ll_pop(LinkedList *l); //Removes node at front of list and returns data from removed node

void ll_append(LinkedList *l, void *data); //Adds node to end of list, storing data in new node

void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)); //removes the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data.

int ll_size(LinkedList *l); //Returns size of list

void ll_clear(LinkedList *l, void (*freefunc)(void *)); //Removes all of nodes from list, freeinga associated data using given funciton

void ll_map(LinkedList *l, void (*mapfunc)(void *)); //Traverses list and applies given function to data at each node

void *ll_deleteAtIndex(LinkedList *l, int index); //Removes node at particular index



