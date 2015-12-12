%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE char*
char p[]="+";
char mi[]="-";
char mu[]="*";
char d[]="/";
char s[]="";
char n[]="";
%}
%token ALPHANUM
%left '+' '-'
%left '*' '/'

%%
start : expr '\n' {printf("\n %s \n",$1);exit(1);}
	;

expr : expr '+' expr   	{
						
						$$=strcat(strcat($2,$1), $3); 
			
						 }
		
		
		| expr '-' expr {$$=strcat(strcat($2,$1), $3);  }
		| expr '*' expr {$$=strcat(strcat($2,$1), $3);  }
		| expr '/' expr {$$=strcat(strcat($2,$1), $3);  }
		| '(' expr ')' {$$=$2;}
		| ALPHANUM {$$=$1;}
	;
	
%%

/*

printf("\nnew\n");
						printf("\n%s ,%s ,%s\n",$1,$3,$$);
						char yo[100]="";
						printf("\n%s ,%s ,%s\n",$1,$3,$$);
						char p[100]="+";
						printf("\n%s ,%s ,%s\n",$1,$3,$$);
						char s[100]=" ";
						printf("\n%s ,%s ,%s\n",$1,$3,$$);
						char one[100];strcpy(one,$1);
						char three[100];strcpy(three,$3);
						strcpy(yo,p);
						printf("\n%s %s %s\n",yo,one,three);
						$$=strcat(strcat(strcat(yo,one),s), strcat(three,s)); 
						 printf("\n%s ,%s ,%s\n",$1,$3,$$);
*/
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
