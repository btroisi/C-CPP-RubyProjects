/**
*Encoder: Shift any character in a-z or A-Z 13 spaces forward in the alphabet with 
*wraparound from z back to a
*/



%%

[A-Z]	{if(yytext[0]<78){
			printf("%c",(char)(yytext[0]+13));} //Shift any character A-Z 13 spaces forward in the alphabet
			
		
		else{
			printf("%c",(char)(65+(yytext[0])-78));} //Shift any character A-Z 13 spaces forward in the alphabet and wraps around z back to a
			
			
		}

[a-z]	{if(yytext[0]<110){
			printf("%c",(char)(yytext[0]+13));} //Shift any character a-z 13 spaces forward in the alphabet
		
		else{
			printf("%c",(char)(97+(yytext[0]-110)));} //Shift character a-z 13 spaces forward in the alphabet and wraps around from z back to a	
		
		}


%%

int main( int argc, char *argv[] ) {

	yylex();
 
 	return 0;
}