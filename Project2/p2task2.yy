/**
*Task 2: Read in text file tells you number of rows, characters, and
*number of occurrences of each vowel.
*/

	int num_lines=0; /*Initializes number of lines in text to 0 */
	int num_chars=0; /*Initializes number of characters in text to 0 */
	int num_a=0; /*Initializes number of a's in text to 0 */
	int num_e=0; /*Initializes number of e's in text to 0 */
	int num_i=0; /*Initializes number of i's in text to 0 */
	int num_o=0; /*Initializes number of o's in text to 0 */
	int num_u=0; /*Initializes number of u's in text to 0 */
	int total_vowels=0; /*Initializes total number of vowels */
	
 

%%

\n		num_lines++; num_chars++; /*Every time it reads a new line char increase # of lines and # of characters by 1 */
a		num_a++; num_chars++; /*Every time it reads an a increase #a's in text by 1 */
e		num_e++; num_chars++; /*Every time it reads an e increase #e's in text by 1 */
i		num_i++; num_chars++; /*Every time it reads an a increase #i's in text by 1 */
o		num_o++; num_chars++; /*Every time it reads an a increase #o's in text by 1 */
u		num_u++; num_chars++; /*Every time it reads an a increase #u's in text by 1 */
.		++num_chars; /*Every time it comes across any character increase character count by 1 */


%%


int main( int argc, char *argv[] ) {

	if (argc > 1){
		yyin = fopen( argv[1], "r" ); /*where yylex reads its input */
 	}
 	yylex(); /* a function of flex that read input till it is exhausted */
 	
 	total_vowels=num_a+num_e+num_i+num_o+num_u;
 	float percent_a=((float)num_a)/num_chars*100; /*Calculates percentage of a's out of all chars */
	float percent_e=((float)num_e)/num_chars*100; /*Calculates percentage of e's out of all chars */
 	float percent_i=((float)num_i)/num_chars*100; /*Calculates percentage of i's out of all chars */
  	float percent_o=((float)num_o)/num_chars*100; /*Calculates percentage of o's out of all chars */
  	float percent_u=((float)num_u)/num_chars*100; /*Calculates percentage of u's out of all chars */
 	
 	//print number of lines,number of chars and number of each type of vowel (a,e,i,o,u) in file that's read in.
 	printf( "Number of lines: %i\nNumber of chars: %i\nNumber of a's: %i\nNumber of e's: %i\nNumber of i's: %i\nNumber of o's: %i\nNumber of u's: %i\n", num_lines,num_chars,num_a,num_e,num_i,num_o,num_u);
 	//print percentage of each vowel in textfile being read
 	printf( "Percentage of each vowel in textfile\n Percent of a's: %f\n Percent of e's: %f\n Percent of i's: %f\n Percent of o's: %f\n Percent of u's: %f\n", percent_a,percent_e,percent_i,percent_o,percent_u);
 	//print total number of vowels in textfile being read
 	printf("Total number of vowels: %d\n",total_vowels);
 	
 	
 	return 0;
}	