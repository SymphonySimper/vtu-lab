%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%

inputs:s'\n' {printf(" \nSuccessful grammar\n");exit(0);}
s:A s1 B|B
s1:; |A s1
;
%%

int main(){
	printf("Enter a string: ");
	yyparse();
}

int yyerror(){
	printf("\nError\n");
	exit(0);
}
