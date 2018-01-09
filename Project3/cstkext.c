/**
 * Test code for Stack 
 *
 * Ying Li
 * 08/01/2016
 */

#include "cstk.h"

int main (int argc, char **argv) {
	Stack *s = stk_create(CSTK_MAX);
	
	int i;
	for(i = 0; i < 10; i++) {
		stk_push(s, i);
	} 

	prinf("The list is empty: ");
	printf(is_empty(s))
	
	printf("Top value of the list: ");
	printf(peek(s));
	
	printf("The original list: ");
	stk_display(s, 0);
	
	printf("The reversed list: ");
	stk_display(s, 1);

	prinf("The list is empty: ");
	printf(is_empty(s));
	
	stk_destroy(s);

	printf("The list is empty now: ")
	printf(is_empty(s))
	
	return 0;
}