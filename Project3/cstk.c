#include "cstk.h"
#include <stdio.h>
#include <stdlib.h>



CSTK_MAX=50; 


Stack *stk_create(int n){
/*Creates stack of size n*/

	Stack *s = malloc(sizeof(Stack));
	s->stack= (int *)malloc(sizeof(int)*n);
	s->top=-1;
	return s;

}


void stk_destroy(Stack* stk){
/*Recycles a stack*/
	free(stk->stack);
	free(stk);
	stk->top=-1;

}

void stk_push(Stack* stk,int val){
/*Adds a new value to the top of the stack*/
	if(stk->top>=CSTK_MAX-1){

		printf("Stack overflow");
	}
	stk->top++;
	stk->stack[stk->top]=val; 
	 	
	

}

int stk_pop(Stack* stk){
	/*Removes value from the top of the stack*/
	
	if(stk->top<=-1){

		printf("Stack underflow");
	}
	else{
		int retVal;
		stk->top--; 
		retVal=*(stk->stack+stk->top);
		return retVal; 
	} 
}
	

int get_size(Stack* stk){
/*Return the size of the stack*/
	return stk->top+1; 
}

int peek(Stack* stk){
/*Return the top value of the stack*/
	return stk->stack[stk->top];
}

int is_empty(Stack* stk){
/*Returns 1 if the stack is empty, otherwise return 0*/

	if(stk->top<0){
		return 1;
	}
	return 0;
}



void stk_display(Stack* stk,int i){
/*If the int value is 1 print stack in reverse order otherwise print in original order */
	if(i ==1){
		for(int j=stk->top;j>=0;j--){
			printf("%d ", stk->stack[j]);
			
		}
		
	}

	else if(stk->top==-1){

		printf("Empty stack");
		
	}
	
	else{
		for(int k=0;k<=stk->top;k++){
			printf("%d ", stk->stack[k]);
		} 
		
	}
	printf("\n");
}