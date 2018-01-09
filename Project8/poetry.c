#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

pthread_mutex_t lock;
pthread_mutex_lock(&lock);
printf("This is protected");
printf("Threads run in the right order");
pthread_mutex_unlock(&lock);c
printf("This part is unprotected");