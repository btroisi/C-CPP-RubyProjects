
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


LinkedList *ll_create(){
//Creates new LinkedList struct, initializes it and returns it
	LinkedList *ll = malloc(sizeof(LinkedList));
	ll->size=0;
	ll->head = NULL;
	ll->tail=NULL;
	return ll; 

}

void ll_push(LinkedList *l, void *data){
//Adds node to front of list, storing data in new node 

	Node * new_node = malloc(sizeof(Node));
	new_node->data=data;
	new_node->next=l->head;
	l->head=new_node; 
	l->size++;
	

}

void *ll_pop(LinkedList *l){
//Removes node at front of list and returns data from removed node

	//If head is null(empty list) return null
	if(l->head==NULL){
		return NULL;
	}

	//Free and return data at head
	void* retval = l->head->data;
	Node * removed_node = l->head;
	l->head = removed_node->next;

	free(removed_node);
	l->size--;
	return retval;


}


void ll_append(LinkedList *l, void *data){
//Adds node to end of list, storing data in new node

	//If list is empty
	if (l->head == NULL) {
		Node* new_node = malloc(sizeof(Node));
		new_node->data=data;
		new_node->next=NULL; 
		
		
		l->head = new_node;
		l->tail = new_node;
	}

	//If list is not empty
	else {
		Node * cur = l->head;
	
		//Traverse through linked list
		while(cur->next!=NULL){
			cur=cur->next;
		}

		//Create new node after traversing through list, storing data in new node
		Node* new_node = malloc(sizeof(Node));
		new_node->data=data;
		new_node->next=NULL; 
		cur->next=new_node;
		l->tail = new_node;
	}
	l->size++; 
}



void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
 //removes the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data.

	//If head is null return null
	if(l->head==NULL){
		return NULL;
	}

	Node * cur=l->head; 
	void * retval=NULL; 

	//If the first node in the list whose data matches target given the comparison function is the head.
	//Free and return data at the head
	if(compfunc(cur->data,target)==1){
		retval=cur->data;
		l->head=cur->next;
		free(cur);
		l->size--;
		return retval; 

	}

	Node *next_node=cur->next;

	//while we are not at the node before the one we are looking for
	while(compfunc(next_node->data,target)!=1){
		if(next_node->next != NULL){
			//If next node from node we want to delete is not null
			//Keep traversing through list 
			cur=cur->next;
			next_node = next_node -> next; 	
		}
		else{
			//If data we are looking for is not in list return null
			return NULL;
		}
	}

	//If the node we are looking for is in the middle of the list
	retval=next_node->data;
	if(next_node->next!=NULL){
		cur->next=next_node->next; 
		free(next_node);
		l->size--;
		return retval;

	}
	//If the node we are looking for is at the end of the list
	else if(next_node->next==NULL){

		free(next_node);
		cur->next=NULL;
		l->size--; 
		return retval; 
	}
return retval; 
}

int ll_size(LinkedList *l){
//Returns size of list
	return l->size; 
}


void ll_clear(LinkedList *l, void (*freefunc)(void *)){
//Removes all of nodes from list, freeing associated data using given funciton

	if(l->head!=NULL){
		Node* cur=l->head;
		while(cur!=NULL){
			Node *temp = cur;
			cur=cur->next;
			freefunc(temp->data);	
			free(temp);
		}
		l->head = NULL;
		l->tail = NULL;
		l->size = 0;

	}
	
	return; 
}

void ll_map(LinkedList *l, void (*mapfunc)(void *)){
//Traverses list and applies given function to data at each node
	if(l->head!=NULL){
		Node * cur=l->head;
		while(cur!=NULL){
			mapfunc(cur->data);
			if(cur->next!=NULL){
				cur=cur->next;
			}
			else{
				return; 
			}
		}

	}
	return; 
}

void *ll_deleteAtIndex(LinkedList *l, int index){
	//Deletes node at a particular index of the list and returns value associated with that node
	
	//If head is null return null
	if(l->head==NULL){
		return NULL;
	}

	Node * cur=l->head; 
	void * retval=NULL; 

	//If index we want to delete is first index
	//Free and return data associated with node at this index 
	if(index==0){
		retval=cur->data;
		l->head=cur->next;
		free(cur);
		l->size--;
		return retval; 
	}

	Node *next_node=cur->next;

	//Otherwise keep traversing through list until you get to node
	//before the node at the index which you would like to delete
	for(int i=0;i<index-1;i++){
		if(next_node->next != NULL){
			cur=cur->next;
			next_node = next_node -> next; 	
		}
		else{
			return NULL;
		}
	}

	//If the node we are looking for is in the middle of the list
	retval=next_node->data;
	if(next_node->next!=NULL){
		cur->next=next_node->next; 
		free(next_node);
		l->size--;
		return retval;

	}
	//If the node we are looking for is at the end of the list
	else if(next_node->next==NULL){

		free(next_node);
		cur->next=NULL;
		l->size--; 
		return retval; 
	}
return retval; 


}



