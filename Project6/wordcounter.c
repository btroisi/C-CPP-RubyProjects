 /* formatted file I/O
 * formatIO.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"


int charsequal(void *c, void *d){
	//Compare function that shows whether two strings are equal
	char *a = (char *)c;
	char *b = (char *)d;
	return strcmp(a, b);
}

int compNum(void *i, void *j) {
	//Compare funciton that shows whether two numbers are equal
	int *a = (int *)i;
	int *b = (int *)j;
	
	return(*a == *b);
	}

int compFreq(const void *i, const void *j) {
	//Compare funciton that returns the difference between the first and second frequency
	//Returns values in descending order
	int a = *(const int *)i;
	int b = *(const int *)j;
	return b-a;
	
}
//Convert all chars in a word to lowercase and removes punctuation
void reformat(char *p){

    char *src = p, *dst = p;

    while (*src)
    {
       if (ispunct((unsigned char)*src)){
          //If the char is a punctuation mark skip this character when reading it
          src++; 
       }
       else if (isupper((unsigned char)*src)){
          //If char is uppercase make it lowercase
          *dst++ = tolower((unsigned char)*src);  
          src++;
       }
       else if (src == dst){
          //Increment both pointers without copying 
          src++;
          dst++;
       }
       else{
          *dst++ = *src++; //Copy character from src to dst
       }
    }

    *dst = 0;
}

int main () {
	FILE *fp;
	LinkedList *wordlist;
	int value;
	char fname[50]; 
	char word1[1000];
	char *word2; 
	wordlist=ll_create(); //Initialze wordlist, a linkedlist
	
	//Prompts user to put in file name for which to run word counter program on and reads it in
	printf("What file would you like to test the word counter for: ");
	scanf("%s", fname);
 	fp = fopen(fname, "r");

	//If the file name does not exist, print "Not a valid file...exiting now" and exit program
 	if(fp==NULL){
 		printf("Not a valid file...exiting now");
 		exit(1);
 	}

	//Otherwise if file does exist, read each word in line while there is a word to read in
 	while(fscanf(fp, "%s", word1)==1) {
		reformat(word1); //Remove punctuation marks for each word and make each character in each word lowercase 
		word2=(char*)malloc(strlen(word1)); 
		strcpy(word2,word1); 
		ll_push(wordlist,word2,charsequal);	//Push each word onto wordlist
	}

	//Create array to put frequencies of each word in wordlist into
	int freq[ll_size(wordlist)]; 
	int i=0;
	Node * cur = wordlist->head; 
	while (cur != NULL) {
		freq[i]=cur->count; 
		cur = cur->next;
		i++; 	
	}
	
	//Sort array of frequencies using qsort
	qsort((void*)freq, wordlist->size, sizeof(int),
	 compFreq);

	//Print top 20 words in descending order with word and frequency
	int * curcount=malloc(sizeof(int));
	for(int i=0;i<20;i++){
		*curcount=freq[i];
		printf("%s : %d\n", ll_mapfreqtouniqueword(wordlist,curcount,compNum), freq[i]);
	}

 	fclose(fp); //close the file
	return 0;
	}