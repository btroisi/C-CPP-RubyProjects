/*
Brandon Troisi
LinkedList.c
10/7/17
*/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


//Creates new LinkedList struct, initializes it and returns it
LinkedList *ll_create(){
	LinkedList *ll = malloc(sizeof(LinkedList));
	ll->size=0;
	ll->head = NULL;
	ll->tail=NULL;
	return ll; 

}

/*Adds new word to list if we haven't encountered word yet
Otherwise, increases count by 1 of word we have seen*/
void ll_push(LinkedList *l, void *newword,int (*compfunc)(void *, void *)){

	if(l->head==NULL){
		//If there is no word in the list
		//Create a new node to represent that set its count to 1 and printed to 0
		Node * new_node = malloc(sizeof(Node));
		new_node->data=newword;
		new_node->count=1;
		new_node->printed=0;
		new_node->next=NULL;
		l->head=new_node; 
		l->size++;
		
	}
	else{
		//Otherwise if there are one or more words on the list
		Node * cur = l->head;
		while(cur!=NULL){
			if(compfunc(cur->data,newword)!=0){
				//If the word we are adding to the list is not already there
				//Keep traversing through the list until we reach the end
				cur=cur->next;
			}
			
			else {
				//Otherwise if the word we are adding to the list is already there
				//Increment the count of the word already in the list by 1
				//Do not create a new node for the word
				cur->count++;
				return;
			}
			
		}
		
		//For a new word in the list
		//Create a new node to represent the word and set count to 1
		Node * new_node = malloc(sizeof(Node));
		new_node->count=1;
		new_node->printed=0;
		new_node->data=newword;
		new_node->next=l->head;
		l->head=new_node; 
		l->size++;

	}
		
}

/*Returns a unique word associated with a particular frequncy */
void *ll_mapfreqtouniqueword(LinkedList *l, void* freq, int (*compfunc)(void *, void *)){
	
	//If head is null return null
	if(l->head==NULL){
		return NULL;
	}
	
	Node * cur=l->head; 
	void * retval; 
	
	
	int curwordfreq=cur->count;
	int *current=&curwordfreq;
	while(cur != NULL){
		//While the current node is not null get the count associated with that word and the reference to that count
		curwordfreq=cur->count;
		current=&curwordfreq;
		if(compfunc(current,freq)==1 && cur->printed == 0 ){
			//If we are at the word we are looking for according to its count and it hasn't been printed yet
			//Return this word
			//and set its printed value to 1 to show that it's been printed 
			//so we return a unique word every time this function is called
			retval=cur->data;
			cur->printed=1;
			return retval; 
		}
		
		else{
			//Otherwise keep traversing through the list to see if that frequency appears in the list
			cur =cur->next;
		}
		
	}
	return NULL;
}

int ll_size(LinkedList *l){
//Returns size of list
	return l->size; 
}


