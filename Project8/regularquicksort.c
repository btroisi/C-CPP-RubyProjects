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
#include <sys/time.h>

//Gets the current time stamp
double get_time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}


/* the comparator funciton used in qsort */
int comparator (const void *p, const void *q) {
	
	int m=*(const int *)p;
	int n=*(const int *)q;

	return m-n;
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
    
    double t1=get_time_sec();
	qsort((void *) ary, size, sizeof(int), comparator);
	double t2=get_time_sec();
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	printf("Time it takes to sort array: %f\n", t2-t1);
	return 0;
}