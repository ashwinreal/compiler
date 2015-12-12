%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#define YYSTYPE char*
%}

%%
[0-9a-zA-Z]+ {char *ptr=(char *)malloc(100);strcpy(ptr,yytext);yylval=ptr;return ALPHANUM;}
.      {char *ptr=(char *)malloc(100);strcpy(ptr,yytext);yylval=ptr;return *yytext;}
"\n" {yylval=*yytext;return *yytext;}
%%
yywrap(){
	return 1;
}
