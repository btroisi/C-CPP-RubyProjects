/*
Brandon Troisi
CS333 Project 8 mutexlock.c
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_THREADS 4

int counter=0;
pthread_mutex_t lock;

typedef struct{
    int tnum;
}threadNum;
 
void* workerfunc(void *arg){

    //threadNum *tn = (threadNum *)arg; 
    pthread_mutex_lock(&lock);
    counter+=1;
    int i;
     
    printf("Thread %d has begun its process\n", counter);   
    printf("Thread %d has been executed\n", counter);

    pthread_mutex_unlock(&lock);
 
    return NULL;
}
 
int main(void){

    int i;
    
    threadNum tn[NUM_THREADS];
    pthread_t thread[NUM_THREADS];

    for(i=0;i<NUM_THREADS;i++){
        tn[i].tnum=i;
    }

    counter=0;
    pthread_mutex_init(&lock,NULL);


    for(i=0;i<NUM_THREADS;i++){
        pthread_create((&thread[i]),NULL,workerfunc,&(tn[i]));
    }

    for(i=0; i<NUM_THREADS;i++){
        pthread_join(thread[i],NULL);
    }
    pthread_mutex_destroy(&lock);
 
    return 0;
}