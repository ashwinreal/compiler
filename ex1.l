%{
	#include <stdio.h>
	int global_variable;
	char *file1;
%}
number [0-9]+
op [-|+|*|/|^|=]

%%
{number} {
	//return atoi(yytext);
			if(atoi(yytext)%2==0)
				printf(" number found : %d is even ",atoi(yytext));
			else
				printf(" number found : %d is odd ",atoi(yytext));
		} 
{op} {printf(" operator");}
%%

int yywrap()
{
  	FILE *newfile_pointer;
  	char *file2="in2.l";
  	newfile_pointer = fopen("in2.l","r");
  	if(strcmp(file1,file2)!=0)
  	{
  		file1=file2;  
  		yyin = newfile_pointer;
    		return 0;
  	}
  	else
  		return 1;
}

int main(int argc,char *argv[])
{

	file1="in.l";
	FILE *fp = fopen(file1, "r");
	yyin = fp; 
	
	
	yylex();
	
	return 1;
}
