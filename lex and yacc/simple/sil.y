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
						int index_id=check_exist($2);
						if(index_id!=-1)
							printf("error : name %s already exists\n", $2->var_name);
					  $2->size=1;
					  strcpy($2->data_type,"boolean");
						$2->store.f=(bool *)malloc(sizeof(bool));
						*($2->store.f)=false;
						symtbl[id_count++]=$2;
						//printf("declaration %s",yylval->data_type);
					}
		| INTEGER  ID ';' {
				int index_id=check_exist($2);
				if(index_id!=-1)
				printf("error : name %s already exists\n", $2->var_name);
				$2->size=1;
				strcpy($2->data_type,"integer");
				$2->store.i=(int *)malloc(sizeof(int));
				*($2->store.i)=0;
				symtbl[id_count++]=$2;
				//	printf("declaration %s",yylval->data_type);
		}
		| INTEGER ID '[' expr ']' ';' {
			printf("array of integer\n" );
			int index_id=check_exist($2);
			if(index_id!=-1)
			printf("error : name %s already exists\n", $2->var_name);
			if(strcmp($4->data_type,"boolean")==0)
				printf("error: inside [] must be an int\n" );
			$2->size=*($4->store.i);
			strcpy($2->data_type,"integer");
			$2->store.i=(int *)malloc($2->size*sizeof(int));
			memset($2->store.i,0,$2->size);
			symtbl[id_count++]=$2;


		}
		| BOOLEAN ID '[' expr ']' ';'{
			printf("array of bool\n" );
			int index_id=check_exist($2);
			if(index_id!=-1)
			printf("error : name %s already exists\n", $2->var_name);
			if(strcmp($4->data_type,"boolean")==0)
				printf("error: inside [] must be an int\n" );
			$2->size=*($4->store.i);
			strcpy($2->data_type,"boolean");
			$2->store.f=(bool *)malloc($2->size*sizeof(bool));
			memset($2->store.f,false,$2->size);
			symtbl[id_count++]=$2;


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
																printf("expr evaluated to %d \n",*$3->store.i);
																if(strcmp(symtbl[index_id]->data_type,"boolean"))
																{
																	*(symtbl[index_id]->store.f)=*($3->store.f);
																}
																else
																	*(symtbl[index_id]->store.i)=*($3->store.i);

																$$->store.f = (bool *) malloc(sizeof(bool));
																*($$->store.f) = true;


															}
														else
															{printf("kya error  cannot evaluate!\n");
															$$->store.f = (bool *) malloc(sizeof(bool));
															*($$->store.f) = false;
														}

													}
					| ID '[' expr ']' '=' expr ';' {

						printf("in id = expr[]\n");
						$$ = (tbl*)malloc(sizeof(tbl));
						strcpy($$->var_name,"default");

						if(strcmp($3->data_type,"boolean")==0)
							printf("error: inside [] must be an int\n" );

						$$->size =1;
						strcpy($$->data_type,"boolean");
						int index_id=check_exist($1);
						printf("%d\n",index_id );
					if(symtbl[index_id]->size <= *($3->store.i))
						printf("illegal mem. ref out of index\n");
					printf("the datatyp is %s\n", $6->data_type);
						if( index_id !=-1 && check_dtype(symtbl[index_id],$6->data_type))
							{
								printf("expr evaluated to %d \n",*($6->store.i));
								if(strcmp(symtbl[index_id]->data_type,"boolean"))
								{
									*(symtbl[index_id]->store.f  + *($3->store.i))=*($6->store.f );
								}
								else
									*(symtbl[index_id]->store.i + *($3->store.i))=*($6->store.i);

								$$->store.f = (bool *) malloc(sizeof(bool));
								*($$->store.f) = true;


							}
						else
							{printf("kya error  cannot evaluate2!\n");
							$$->store.f = (bool *) malloc(sizeof(bool));
							*($$->store.f) = false;
						}



					}

					;
expr : expr '+' expr {
												if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
												{
													$$ = (tbl*)malloc(sizeof(tbl));
													strcpy($$->var_name,"default");
													$$->size =1;
													strcpy($$->data_type,"integer");
													$$->store.i = (int *) malloc(sizeof(int));
												*($$->store.i)=*($1->store.i)+*($3->store.i);
												}else printf("error: conflicting data types or not integer data types\n");




}
	| expr '-' expr {
		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"integer");
			$$->store.i = (int *) malloc(sizeof(int));
		*($$->store.i)=*($1->store.i) = *($3->store.i);
		}else printf("error: conflicting data types or not integer data types\n");




	}
	| expr '*' expr {

		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"integer");
			$$->store.i = (int *) malloc(sizeof(int));
		*($$->store.i)=*($1->store.i) * *($3->store.i);
		}else printf("error: conflicting data types or not integer data types\n");



	}
	| expr '/' expr {

		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"integer");
			$$->store.i = (int *) malloc(sizeof(int));
		*($$->store.i)=*($1->store.i) / *($3->store.i);
		}else printf("error: conflicting data types or not integer data types\n");

	}
	| expr EQEQ expr {

		if(strcmp($1->data_type,$3->data_type)==0)
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"boolean");
			$$->store.f = (bool *) malloc(sizeof(bool));
			if(strcmp($1->data_type,"integer")==0)
				*($$->store.f)=*($1->store.i) == *($3->store.i);
			else
				*($$->store.f)=*($1->store.f) == *($3->store.f);
		}else printf("error: conflicting data types\n");


	}
	| expr NEQ expr {
		if(strcmp($1->data_type,$3->data_type)==0 )
		{
			$$ = (tbl*)malloc(sizeof(tbl));
			strcpy($$->var_name,"default");
			$$->size =1;
			strcpy($$->data_type,"boolean");
			$$->store.f = (bool *) malloc(sizeof(bool));
			if(strcmp($1->data_type,"integer")==0)
				*($$->store.f)=*($1->store.i) != *($3->store.i);
			else
				*($$->store.f)=*($1->store.f) != *($3->store.f);
		}else printf("error: conflicting data types or not integer data types\n");


	}
	| ID '[' expr ']' {
		printf("id[]\n");
		int index_id=check_exist($1);
		if( index_id !=-1)
			{


				strcpy($1->data_type,symtbl[index_id]->data_type);
				strcpy($1->var_name, "default_array");
				$1->size = symtbl[index_id]->size;

				if(strcmp($3->data_type,"boolean")==0)
					printf("error: inside [] must be an int\n" );
				if($1->size <= *($3->store.i))
					printf("in id[expr] illegal mem. ref out of index max= %d expr=%d\n",$1->size,*($3->store.i));

				if(strcmp(symtbl[index_id]->data_type,"boolean"))
				{
					$1->store.f = (bool *)malloc(sizeof(bool));
					*($1->store.f) =*(symtbl[index_id]->store.f + *($3->store.i) );
				}
				else
				{
					$1->store.i = (int *)malloc(sizeof(int));
					*($1->store.i) =*(symtbl[index_id]->store.i + *($3->store.i));

				}
					$$=$1;


			}
			else
					printf("error not declared\n" );


		printf("the datatype is %s name is %s\n",$1->data_type,$1->var_name );



	}
	| '(' expr ')' {$$=$2;}
	| ID {
			printf("id\n");
			int index_id=check_exist($1);
			if( index_id !=-1)
				{


					strcpy($1->data_type,symtbl[index_id]->data_type);
					strcpy($1->var_name,symtbl[index_id]->var_name);
					$1->size = symtbl[index_id]->size;
					if(strcmp(symtbl[index_id]->data_type,"boolean"))
					{
						$1->store.f = (bool *)malloc(sizeof(bool));
						*($1->store.f) =*(symtbl[index_id]->store.f);
					}
					else
					{
						$1->store.i = (int *)malloc(sizeof(int));
						*($1->store.i) =*(symtbl[index_id]->store.i);

					}
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
