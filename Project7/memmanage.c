#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_timing.h"

/**
 * my_timing.c
 * Return the time in seconds
 * Note: it doesn't work to return a float - it must be a double.
 */

 //Returns current time 
double get_time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;

}

//Return difference between two doubles d2 and d1
double diff(double d1, double d2){
    return d2-d1;
}

//Dynamically allocate memory for int array 10000 times
//Determine average time it takes to allocate memory for int array 10000 times
void allocate_mem(int i){

    double sum;
    double avg; 
    for(int j=0; j<10000;j++){
        double t1=get_time_sec();
        int *a1=malloc(i*sizeof(int));
        free(a1);
        double t2=get_time_sec();
        sum+=diff(t1,t2);

        if(j%1000==0){
            //Time memory management call by timing
            //malloc and free calls at 1000 step intervals
            double t3=get_time_sec();
            printf("\nTime for section call: %.10f\n", diff(t1,t3)); 

        }
    }

    //Calculate average time to make 10000 calls for memory (a/dea)llocation
    avg=sum/10000; 
    printf("\nAverage time per call to allocate memory: %.10f\n", avg);  
}


int main(){
    //Test memory allocation calls for small, medium, and large sizes of memory
    printf("\nSmall\n");
    allocate_mem(1);
    printf("\nMedium\n");
    allocate_mem(100000);
    printf("\nLarge\n");
    allocate_mem(100000000);
    
    return 0;
}