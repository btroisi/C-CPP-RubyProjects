
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <iostream>

#define NUM_THREADS 2
using namespace std; 

//Gets the current time stamp
double get_time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

//Struct to define a section of an array that you want to sort with parallelism 
typedef struct {
    int* sec;
    int size;
    int start;  
} arraySection;

/* the comparator funciton used in qsort orders values from least to greatest */
int comparator (const void *p, const void *q) {
	int m=*(const int *)p;
	int n=*(const int *)q;
    return m-n; 
}

//Worker function for using quicksort to sort arrays 
void *split_array(void *arraysec){

    arraySection *as = (arraySection *) arraysec; 

    //If the size of the array is as big as the number of threds apply quicksort 
    //to just the array
    if(as->size<=NUM_THREADS){
        qsort((void *) as->sec, as->size, sizeof(int), comparator);
    }
    
    else{
        arraySection asleftInfo;
        arraySection asrightInfo; 
       
        //Split array into left section
        asleftInfo.sec=as->sec;
        asleftInfo.size=(as->size)/2;
        asleftInfo.start=as->start; 

        //Split array into right section 
        asrightInfo.sec=as->sec;
        asrightInfo.size=(as->size)/2;
        asrightInfo.start=as->start+asleftInfo.size; 

        //Initialize thread for left and right side
        pthread_t leftthread;
        pthread_t rightthread; 

         //Initialize thread for left and right side
        pthread_create(&leftthread,NULL,split_array,&asleftInfo);
        pthread_create(&rightthread,NULL,split_array,&asrightInfo);

        //Join left and right thread
        pthread_join(leftthread,NULL);
        pthread_join(rightthread,NULL);

        //Apply qsort to both right and left threads 
        qsort((void *) as->sec, as->size, sizeof(int), comparator);
    }

    pthread_exit(NULL);
}


int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
    int size = sizeof(ary) / sizeof(int);
    
    //Initialize thread for whole array
    arraySection whole;
    pthread_t thread; 

    whole.sec=ary;
    whole.size=size;
    whole.start=ary[0]; 

    //Time before sorting
    double t1=get_time_sec();

    //Create and join thread for whole array 
    pthread_create(&thread,NULL,split_array,&whole);
    pthread_join(thread,NULL);
    
    //Time after sorting 
    double t2=get_time_sec();
    
    cout<<"Sorted array: "<<endl;
    for(int i=0; i<size;i++){
        cout<<" "<<ary[i]<<" ";
    }
    
    cout<<"Time it takes using " << NUM_THREADS<< " threads: " << t2-t1 <<endl;
	return 0;
}