/**
 * Test code for Stack Extension
 *
 * Brandon Troisi
 * 10/3/17
 */

#include "cstk.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv) {
	Stack *s = stk_create(CSTK_MAX);
	
	int i;
	for(i = 0; i < 10; i++) {
		stk_push(s, i);
	} 
	
	
	printf("The list: ");
	stk_display(s, 0);

	printf("Size of the list: %d\n",get_size(s));

	printf("The list is empty: %d\n",is_empty(s));
	
	
	printf("The value of the top of the stack is: %d\n", peek(s));
	
	stk_destroy(s);

	printf("The stack has been destroyed...");

	printf("The list is empty: %d\n",is_empty(s));
	


	
	
	return 0;
}