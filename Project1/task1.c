/**
 * Task1 project 1
 * 
 * In this program we declare a variable of each of the basic types
 * (string, short, int, long, float) and loop through each data type
 * and see how it's stored in memory 
 *
 * Brandon Troisi
 * 9/18/17 
 */

#include <stdio.h>
#include <stdlib.h>


int main (int arg, char *argv[]) {
	
  //Variable declaration for each type of basic variable. 	
  char string1[] = "ab"; 
  short s = 6;
  int i = 9;
  long l = 23; 
  float f = 4.0; 
  
  //Create pointers for each type of variable we declared
  unsigned char *strptr;
  strptr = (unsigned char *)&(i);
  
  unsigned char *intptr;
  intptr = (unsigned char *)&(i);
  
  unsigned char *shortptr;
  shortptr = (unsigned char *)&(s);
  
  unsigned char *longptr;
  longptr = (unsigned char *)&(l);
  
  unsigned char *floatptr;
  floatptr = (unsigned char *)&(f);
  
  //Loop through string string1 with stringptr to see how it's stored in memory 
  int a = sizeof(string1)/sizeof(char);
  printf("string");
  for(int t=0; t<a; t++){
  	
  	printf("%u",strptr[t]);
  }	
  printf("\n");
  
  //Loop through integer i with intptr to look at how it's stored in memory 
  printf("int");
  for(int j=0; j<sizeof(i); j++){
  	
  	printf("%u",intptr[j]);
  }	
  printf("\n");
 
  //Loop through short s with shortptr to look at how it's stored in memory 
  printf("short");
  
  for(int k=0; k<sizeof(s); k++){
  	
  	printf("%u",shortptr[k]);
  }	
  
  
  //Loop through long l with longptr to look at how it's stored in memory 
  printf("\n");
  printf("long");
  for(int m=0; m<sizeof(l); m++){
  	
  	printf("%u",longptr[m]);
  }	
  
  
 //Loop through float f with floatptr to look at how it's stored in memory 
  printf("\n");
  printf("float");
  for(int n=0; n<sizeof(f); n++){
  	
  	printf("%u",floatptr[n]);
  }	
  printf("\n");
			
  return 0;
}  