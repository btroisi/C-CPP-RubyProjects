/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator funciton used in qsort */
int comparator (const void *p, const void *q) {
	
	int m=*(const int *)p;
	int n=*(const int *)q;

	//If m and n are odd put lesser value first
	if ((m&1) && (n&1)){
		return (m-n);
	}

	//If m and n are even, put greater value first
	if (!(m&1) && !(n&1)){
		return (n-m);
	}

	//If m is odd and n is even put n first 
	if((m&1)){

		return 1;
	}

	//m is even put m first
	return -1; 
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}