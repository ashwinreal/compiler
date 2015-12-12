%{
#include <stdio.h>
#include <stdlib.h>

void op_print(char op);

int pos=0;
%}

%token DIGIT
%token '0'
%token '1'
%token '2'
%token '3'
%token '4'
%token '5'
%token '6'
%token '7'
%token '8'
%token '9'
%left '+' '-'
%left '*' '/'


%%

start : expr '\n' {printf("%d\n",$1);exit(1);}
	;

expr : expr '+' expr {$$=$1+$3;}
		| expr '-' expr {$$=$1-$3;}
		| expr '*' expr {$$=$1*$3;}
		| expr '/' expr {$$=$1/$3;}
		| '(' expr ')' {$$=$2;}
		| DIGIT {$$=$1;}
	;
	
%%



yyerror()
{
	printf("error");
	return;
}

main()
{
	yyparse();
	return 1;
}
