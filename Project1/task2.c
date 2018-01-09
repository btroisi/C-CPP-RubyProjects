/**
 * Task 2 project 1
 *
 * In this program we use an infinite loop to look at how
 * an unsigned character is stored in memory
 *
 * Brandon Troisi
 * 9/18/17 
 */

#include <stdio.h>
#include <stdlib.h>

int main (int arg, char *argv[]) {
	int a=3;
	char string1[]="ran";
	unsigned char *ptr;
	ptr = (unsigned char *)&ptr;
	
	//Infinitely loop through unsigned ptr character to see how it's stored in memory
	for(int i=0;;i++){
		printf("Index: %i %u \n",i, ptr[i]); //Print current index and address of each element in unsigned char ptr
		
		
	}
	return 0;
}