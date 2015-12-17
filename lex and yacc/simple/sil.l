%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symtbl.h"
#include "y.tab.h"
#include "astree.h"
#define YYSTYPE ast*
ast *ptr;
%}

%%
"\n" {}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"begin" {return BEG;}
"end" {return END;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"read" {return READ;}
"write" {return WRITE;}
"==" {return EQEQ;}
"!=" {return NEQ;}
[ \t] {}
"boolean" {return BOOLEAN;}
"integer" {return INTEGER;}
[0-9]+ {
	ptr=(ast *)malloc(sizeof(ast));
	ptr->int_value=atoi(yytext);
	ptr->node_type=NUM;
	strcpy(ptr->data_type,"integer");
	yylval=ptr;
	return NUM;}
"true" {
	ptr=(ast*)malloc(sizeof(ast));
	ptr->bool_value=true;
	ptr->node_type=T;
	strcpy(ptr->data_type,"boolean");
	yylval=ptr;
	return T;}
"false" {
	ptr=(ast*)malloc(sizeof(ast));
	ptr->bool_value=false;
	ptr->node_type=F;
	strcpy(ptr->data_type,"boolean");
	yylval=ptr;
	return F;}
[_a-zA-Z][_0-9a-zA-Z]* {
												ptr=(ast*)malloc(sizeof(ast));
												strcpy(ptr->name,yytext);
												yylval=ptr;
												return ID;}

. {return *yytext;}



%%
yywrap(){
	return 1;
}
