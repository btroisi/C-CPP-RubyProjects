/**
*Parser for Clite
*/

%%

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]  /*Skips multi-line comments */
\/\/ /* Skips single line comments */
[0-9]+	printf("Integer- %s\n",yytext); /*If it reads in integer prints integer and value of integer */
[0-9]+\.[0-9]+	printf("Float- %s\n", yytext); /*If it reads in float prints float and value of float */
if|else|while|for|int|float   printf( "Keyword- %s\n", yytext); /*If it reads in keyword(if,else,while,for,int,float) prints keyword and value of keyword */
[a-zA-Z0-9_]+	printf("Identifier- %s\n", yytext); /*If it reads in keyword(if,else,while,for,int,float) prints keyword and value of keyword */
=	printf("Assignment\n"); /*If it reads in = print assignment */
==|\<|\>|\<=|\>=	printf("Comparison- %s\n", yytext); /*If it reads in comparison symbol(==,<,>,<=,>=) prints operator and prints value of comparison */
\+|-|\*|\/   printf( "Operator- %s\n", yytext); /*If it reads in operator symbol(+,-*,/) prints operator and prints value of comparison */
\{	printf("Open-bracket\n"); /*If it reads in open bracket prints Open-bracket */
\}	printf("Close-bracket\n"); /*If it reads in close bracket prints Close-bracket */
\(	printf("Open-paren\n"); /*If it reads in open parenthesis prints Open-paren*/
\)	printf("Close-paren\n"); /*If it reads in close parenthesis prints Close-paren*/
\n	
.	
%%


int main( int argc, char *argv[] ) {

	if (argc > 1){
		yyin = fopen( argv[1], "r" ); //where yylex reads its input
	}
	yylex(); // a function of flex that read input till it is exhausted 
 
 	return 0;
}