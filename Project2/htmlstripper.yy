/**
*HTML stripper: Strips file of all HTML tags, comments, and whitespace
*except for a blank line where there used to be a p tag. 
*/

%%


\<p\>	printf("\n"); //Replace <p> tage with blank line
(\<[^<>]+\>)	printf(" "); //Strips html file of all tags and comments except for <p>
[ \t\n]+  //Strips white space from html 

%%


int main( int argc, char *argv[] ) {

 if (argc > 1){
 yyin = fopen( argv[1], "r" ); //where yylex reads its input
 }
 yylex(); // a function of flex that read input till it is exhausted
 
 return 0;
}