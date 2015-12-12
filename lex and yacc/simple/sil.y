%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtbl.h"
#define MAX_SYMBOLS 100
tbl *symtbl[MAX_SYMBOLS];
int id_count=0;

%}

%token ID
%token OPERATOR
%token DECL
%token ENDDECL
%token BEG
%token END
%token IF
%token THEN
%token ELSE
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token READ
%token WRITE
%token EQEQ
%token BOOLEAN
%token INTEGER
%token NUM
%token T
%token F




%left EQEQ NEQ
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
pgm : pgmdecl pgmbody {printf("complete\n");exit(1);};
pgmdecl : DECL dlist ENDDECL {};
dlist : dstmt dlist | dstmt {};
dstmt : BOOLEAN  ID ';' {
					  $2->size=1;
					  strcpy($2->data_type,"boolean");
						$2->store.i=0;
						symtbl[id_count++]=$2;
						//printf("declaration %s",yylval->data_type);
					}
		| INTEGER  ID ';' {
				$2->size=1;
				strcpy($2->data_type,"integer");
				$2->store.i=false;
				symtbl[id_count++]=$2;
				//	printf("declaration %s",yylval->data_type);
		}
		;

pgmbody : BEG stmtlist END {};
stmtlist :  stmt stmtlist{}
			| stmt {};
stmt : assign {}
	|	cond {}
	|  loop {}
	;

assign : ID  '=' expr ';'  {
														printf("in id = expr\n");
														$$ = (tbl*)malloc(sizeof(tbl));
														strcpy($$->var_name,"default");
														$$->size =1;
														strcpy($$->data_type,"boolean");
														int index_id=check_exist($1);
														printf("%d\n",index_id );
														if( index_id !=-1 && check_dtype(symtbl[index_id],$3->data_type))
															{
																printf("expr evaluated to %d \n",$3->store.i);
																if(strcmp(symtbl[index_id]->data_type,"boolean"))
																{
																	symtbl[index_id]->store.f=$3->store.f;
																}
																else
																	symtbl[index_id]->store.i=$3->store.i;

																$$->store.f = true;


															}
														else
															{printf("kya error  cannot evaluate!\n");
															$$->store.f = false;
														}

													};
expr : expr '+' expr {
												if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
												{
													$$ = (tbl*)malloc(sizeof(tbl));
													strcpy($$->var_name,"default");
													$$->size =1;
													strcpy($$->data_type,"integer");
													$$->store.i=$1->store.i+$3->store.i;
												}else printf("error: conflicting data types or not integer data types\n");




}
	| expr '-' expr {
		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"integer");
			$$->store.i=$1->store.i-$3->store.i;
		}else printf("error: conflicting data types or not integer data types\n");




	}
	| expr '*' expr {

		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"integer");
			$$->store.i=$1->store.i*$3->store.i;
		}else printf("error: conflicting data types or not integer data types\n");



	}
	| expr '/' expr {

		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"integer");
			$$->store.i=$1->store.i/$3->store.i;
		}else printf("error: conflicting data types or not integer data types\n");

	}
	| expr EQEQ expr {

		if(strcmp($1->data_type,$3->data_type)==0)
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"boolean");
			$$->store.i=$1->store.i==$3->store.i;
		}else printf("error: conflicting data types or not integer data types\n");


	}
	| expr NEQ expr {
		if(strcmp($1->data_type,$3->data_type)==0 )
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"boolean");
			$$->store.i=$1->store.i!=$3->store.i;
		}else printf("error: conflicting data types or not integer data types\n");


	}
	| '(' expr ')' {$$=$2;}
	| ID {
			int index_id=check_exist($1);
			if( index_id !=-1)
				{


					strcpy($1->data_type,symtbl[index_id]->data_type);
					strcpy($1->var_name,symtbl[index_id]->var_name);
					if(strcmp(symtbl[index_id]->data_type,"boolean"))
					{
						$1->store.f =symtbl[index_id]->store.f;
					}
					else
						$1->store.i=symtbl[index_id]->store.i;
				   	$$=$1;


				}
				else
						printf("error not declared\n" );


			printf("the datatype is %s name is %s\n",$1->data_type,$1->var_name );


		}
	| NUM {
		$$=$1;
	}
	| T {$$=$1;}
	| F {$$=$1;}
	;


cond : IF expr THEN stmtlist ENDIF{}
	| IF expr THEN stmtlist ELSE stmtlist ENDIF{}
;
loop : WHILE expr DO stmtlist ENDWHILE{}
;



%%

int check_exist(tbl *yylval)
{
	int i;
	for(i=0;i<id_count;i++ )
		if(strcmp(symtbl[i]->var_name,yylval->var_name)==0)
			break;

	if(i!=id_count )
		return i;
	return -1;

}
int check_dtype(tbl *yylval,char *a)
{
	if( strcmp(yylval->data_type,a)==0)
		return 1;
	return 0;

}
yyerror()
{
	printf("error\n");
	return;
}

main()
{
	yyparse();
	return 1;
}
