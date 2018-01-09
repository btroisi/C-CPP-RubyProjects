/*
Brandon Troisi
CS333 Project 8 Colorize.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "ppmIO.h"
#include <pthread.h>
#include <sys/time.h>

#define NUM_THREADS 4

//Gets the current time stamp
double get_time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

typedef struct{
	int start;
	int end; 
	Pixel *im; 
}ImageSection;

void *colorize(void * imagepart){

	ImageSection *is = (ImageSection *) imagepart; 
	
	//Process image
	for(int i=is->start;i<is->end;i++) {
		is->im[i].r = is->im[i].r > 128 ? (220+is->im[i].r)/2 : (30+is->im[i].r)/2;
		is->im[i].g = is->im[i].g > 128 ? (220+is->im[i].g)/2 : (30+is->im[i].g)/2;
		is->im[i].b = is->im[i].b > 128 ? (220+is->im[i].b)/2 : (30+is->im[i].b)/2;
	}
}
int main(int argc, char *argv[]) {
	Pixel *src;
	int rows, cols, colors;

	// check usage
	if( argc < 2 ) {
		printf("Usage: %s <image filename>\n", argv[0]);
		exit(-1);
	}

	// read image and check for errors
	src = ppm_read( &rows, &cols, &colors, argv[1] );
	if( !src ) {
		printf("Unable to read file %s\n", argv[1]);
		exit(-1);
	}

	int num_pixels=rows*cols; 
	
	pthread_t threads[NUM_THREADS];
	ImageSection structures[NUM_THREADS];

	int start=0;
	int end=num_pixels/NUM_THREADS;
	int ctr=num_pixels/NUM_THREADS; 

	for(int i=0; i<NUM_THREADS;i++){

		structures[i].im=src;
		structures[i].start=start;
		structures[i].end=end;

		pthread_create(&threads[i],NULL,colorize,&structures[i]);

		start=end;
		end=end+ctr; 

	}
	
	double t1=get_time_sec();

	for(int i=0;i<NUM_THREADS;i++){
		pthread_join(threads[i],NULL);
	}

	double t2=get_time_sec();
	// write out the image
	ppm_write( src, rows, cols, colors, "bold.ppm" );

	free(src);
	printf("Total time to process image with %d threads: %f\n",NUM_THREADS,t2-t1);
	return(0);
}

	
