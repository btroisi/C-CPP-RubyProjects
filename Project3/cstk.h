#ifndef cstk
#define cstk

#include<stdio.h>
#include <stdlib.h>


extern int CSTK_MAX;  

typedef struct stack{
/*Defines type for stack*/
	int* stack;
	int top;

} Stack;


Stack *stk_create(int n);
/*Creates stack of size int*/

void stk_destroy(Stack* stk);
/*Recycles a stack*/

void stk_push(Stack* stk,int val);
/*Adds a new value to the top of the stack*/

int stk_pop(Stack* stk);
/*Removes value from the top of the stack*/	

int get_size(Stack* stk);
/*Returns size of the stack*/

int peek(Stack* stk);
/*Returns top value of the stack*/

int is_empty(Stack* stk);	
/*Returns 1 if the stack is empty, otherwise return 0*/

void stk_display(Stack* stk,int i);
/*If the int value is 1 print stack in reverse order otherwise print in original order */	


#endif