%{
#include <stdio.h>
#include <stdlib.h>
//#define YYSTYPE char*
%}
%token ALPHANUM
%left '+' '-'
%left '*' '/'

%%
start : expr '\n' {exit(1);}
	;

expr : expr '+' expr {printf(" + ");}
		| expr '-' expr {printf(" - ");}
		| expr '*' expr {printf(" * ");}
		| expr '/' expr {printf(" / ");}
		| '(' expr ')' {}
		| ALPHANUM {printf(" %s ",$1);}
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
