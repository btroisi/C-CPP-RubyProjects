/*
	Bruce Maxwell
	Fall 2012
	CS 333

	Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// function that prints an integer
void printInt(void *i) {
	int *a = (int *)i;

	printf("value: %d\n", *a);
}

// function that prints a char
void printChar(void *c){
	char *b= (char *)c;
	printf("char value: %c\n",*b);
}

// function that squares an integer
void squareInt(void *i) {
	int *a = (int *)i;
	*a = *a * *a;
}

// function that compares two integers and returns 1 if they are equal
int compInt(void *i, void *j) {
	int *a = (int *)i;
	int *b = (int *)j;
	return(*a == *b);
}

// function that compares two strings and returns 1 if they are equal
int compChar(void *c, void *d){
	char *a = (char *)c;
	char *b = (char *)d;
	return(*a == *b);
}

// test function for the various linked list functions
// tests linked list functions for ints and char types
int main(int argc, char *argv[]) {
	LinkedList *l;
	LinkedList *lc;
	int *a;
	int *target;
	char *target1;
	char *target2;
	int i;
	char *b;
	char *firstchar; 
	char *c1;
	char *c2;
	char *c3; 
	char *removedchar;
	int *index; 

	// create a list
	l = ll_create();

	// push data on the list
	for(i=0;i<20;i+=2) {
		a = malloc(sizeof(int));
		*a = i;

		ll_push(l, a);
	}

	// printing the list and testing map
	printf("After initialization\n");
	ll_map(l, printInt);
	
	ll_map(l, squareInt);

	printf("\nAfter squaring\n");
	ll_map(l, printInt);

	// testing removing data
	target = malloc(sizeof(int));

	*target = 16;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	*target = 11;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);


	printf("\nAfter removals\n");
	ll_map(l, printInt);

	// testing appending data
	ll_append(l, target);

	printf("\nAfter append\n");
	ll_map(l, printInt);
	
	printf("\nAfter deleting at index 4\n");
	ll_deleteAtIndex(l,4);
	ll_map(l, printInt);

	// test clearing
	ll_clear(l, free);

	printf("\nAfter clear\n");
	ll_map(l, printInt);
	printf("Is really cleared? Yes");

	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		a = malloc(sizeof(int));
		*a = i;
		ll_append(l, a);
	}

	printf("\nAfter appending\n");
	ll_map(l, printInt);

	a = ll_pop(l);
	printf("\npopped: %d\n", *a);
	free(a);

	a = ll_pop(l);
	printf("popped: %d\n", *a);
	free(a);

	printf("\nAfter popping\n");
	ll_map(l, printInt);

	printf("\nList size: %d\n", ll_size(l) );


	printf("Clearing int list\n");
	ll_clear(l, free);
	
	printf("Int list now clear\nNow creating char list...\n");
	lc=ll_create();



	

	// push 3 bs on the list
	for(i=0;i<4;i++) {
		b = malloc(sizeof(char));
		*b = 'b';
		ll_push(lc, b);
	}

	firstchar=malloc(sizeof(char));
	*firstchar='a';
	ll_push(lc,firstchar);

	printf("After initializing list of bs and one a\n");
	ll_map(lc,printChar);

	printf("\nAfter popping a off the list\n");

	b = ll_pop(lc);
	printf("\npopped: %c\n", *b);
	free(b);

	

	

	printf("\nAfter popping\n");
	ll_map(lc, printChar);

	c1=malloc(sizeof(char));
	*c1='c';
	c2=malloc(sizeof(char));
	*c2='a';
	c3=malloc(sizeof(char));
	*c3='d';
	ll_append(lc,c1); 
	ll_append(lc,c2);
	ll_append(lc,c3);


	printf("\nAfter appending c, a, and d\n");
	ll_map(lc, printChar);

	
	target1=malloc(sizeof(char));
	target2=malloc(sizeof(char));
	


	*target1 = 'a';
	c3 = ll_remove(lc, target1, compChar);
	if(c3 != NULL)
		printf("\nremoved: %c\n", *c3);
	else
		printf("\nNo instance of %c\n", *target1);

	*target2 = 'e';
	c3 = ll_remove(lc, target2, compChar);
	if(c3 != NULL)
		printf("\nremoved: %c\n", *c3);
	else
		printf("\nNo instance of %c\n", *target2);

	printf("List after removing a\n");
	ll_map(lc,printChar);


	printf("\nAfter deleting at index 4\n");
	ll_deleteAtIndex(lc,4);
	ll_map(lc, printChar);

	printf("After clearing\n");
	ll_clear(lc,free);
	ll_map(lc,printChar);
	printf("The char list is clear, we're done!\n");

	return(0);
}