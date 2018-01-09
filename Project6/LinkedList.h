

#include <stdio.h>
#include <stdlib.h>



typedef struct{
/*Defines struct for node which represents a word*/ 
	void * next; //Pointer to the next node
	void * data; //Pointer to the word 
	int printed; //Integer for whether word has been printed
	int count; //The number of times word appears
	
} Node;

typedef struct{
/*Defines struct for linked list*/
	Node * head; //head pointer
	Node * tail; //tail pointer
	int size; //Size of linked list
	 
} LinkedList;

LinkedList *ll_create(); //Creates new LinkedList struct, initializes it and returns it

void ll_push(LinkedList *l, void *data,int (*compfunc)(void *, void *)); //Adds node to front of list, storing data in new node 

void *ll_mapfreqtouniqueword(LinkedList *l, void *freq,int (*compfunc)(void *, void *)); //Returns a unique word in lnked list according to the number of times it appears

int ll_size(LinkedList *l); //Returns size of list




