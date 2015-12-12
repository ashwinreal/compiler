%{
#include <stdio.h>
#include <stdlib.h>

void op_print(char op);

int pos=0;
%}

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
%left '+'
%left '*'


%%

start : expr '\n' {exit(1);}
	;

expr : expr '+' expr {op_print('+');}
		| expr '*' expr {op_print('*');}
		| '(' expr ')'
		|  '0'  {printf("%d ",yylval);}
		|  '1'  {printf("NUM%d ",pos);}
		|  '2'  {printf("NUM%d ",pos);}
		|  '3'  {printf("NUM%d ",pos);}
		|  '4'  {printf("NUM%d ",pos);}
		|  '5'  {printf("NUM%d ",pos);}
		|  '6'  {printf("NUM%d ",pos);}
		|  '7'  {printf("NUM%d ",pos);}
		|  '8'  {printf("NUM%d ",pos);}
		|  '9'  {printf("NUM%d ",pos);}
	;
	
%%

void op_print(char op)
{
	if(op == '+')
		printf("PLUS");
	else if(op == '*')
		printf("MUL");
}


yyerror()
{
	printf("error");
	return;
}

yylex()
{
	int c;
	c = getchar();
	if(isdigit(c))
	{
		pos++;
		yylval=c-'0';
		return c;
	}
	else
		return c;
}

main()
{
	yyparse();
	return 1;
}
