%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symtbl.h"
#include "y.tab.h"

%}

%%

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
	yylval=(tbl*)malloc(sizeof(tbl));
	strcpy(yylval->var_name,yytext);
	strcpy(yylval->data_type,"integer");
	yylval->store.i=atoi(yytext);
	return NUM;}
"true" {
	yylval=(tbl*)malloc(sizeof(tbl));
	strcpy(yylval->var_name,yytext);
	strcpy(yylval->data_type,"boolean");
	yylval->store.f=true;
	return T;}
"false" {
	yylval=(tbl*)malloc(sizeof(tbl));
	strcpy(yylval->var_name,yytext);
	strcpy(yylval->data_type,"boolean");
	yylval->store.f=false;
	return F;}
[_a-zA-Z][_0-9a-zA-Z]* {
												yylval=(tbl*)malloc(sizeof(tbl));
												strcpy(yylval->var_name,yytext);
												return ID;}
"\n" {}
. {return *yytext;}



%%
yywrap(){
	return 1;
}
