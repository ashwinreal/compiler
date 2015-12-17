%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtbl.h"
#include "astree.h"
#define MAX_SYMBOLS 100
tbl *symtbl[MAX_SYMBOLS];
int id_count=0;

void free_ptr(ast *yylval);
void evaluate_ast(ast *root);
void print_symbols();
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
%token PLUS
%token MINUS
%token MUL
%token DIV
%token SLIST
%token EQ


%left EQEQ NEQ
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
pgm : pgmdecl pgmbody {printf("complete\n");print_symbols();exit(1);};
pgmdecl : DECL dlist ENDDECL {};
dlist : dstmt dlist | dstmt {};
dstmt : BOOLEAN  ID ';' {
						int index_id=check_exist($2);
						if(index_id!=-1)
							printf("error : name %s already exists\n", $2->name);
						tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
						strcpy(temp_symb->var_name,$2->name);
						temp_symb->size=0;
					  strcpy(temp_symb->data_type,"boolean");
						temp_symb->store.f=(bool *)malloc(sizeof(bool));
						*(temp_symb->store.f)=false;
						symtbl[id_count++]=temp_symb;
						free_ptr($2);
						//printf("declaration %s",yylval->data_type);
					}
		| INTEGER  ID ';' {
				int index_id=check_exist($2);
				if(index_id!=-1)
					printf("error : name %s already exists\n", $2->name);
				tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
				strcpy(temp_symb->var_name,$2->name);
				temp_symb->size=0;
				strcpy(temp_symb->data_type,"integer");

				temp_symb->store.i=(int *)malloc(sizeof(int));
				*(temp_symb->store.i)=0;
				symtbl[id_count++]=temp_symb;
				free_ptr($2);
				//	printf("declaration %s",yylval->data_type);
		}
		| INTEGER ID '[' expr ']' ';' {
		//	printf("array of integer\n" );
			int index_id=check_exist($2);
			if(index_id!=-1)
				printf("error : name %s already exists\n", $2->name);
			if(strcmp($4->data_type,"boolean")==0)
				printf("error: inside [] must be an int\n" );

				tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
				strcpy(temp_symb->var_name,$2->name);
				temp_symb->size=$4->int_value;
				strcpy(temp_symb->data_type,"integer");

				temp_symb->store.i=(int *)malloc($4->int_value*sizeof(int));
				memset(temp_symb->store.i,0,$4->int_value);
				symtbl[id_count++]=temp_symb;
				free_ptr($2);

		}
		| BOOLEAN ID '[' expr ']' ';'{
			//printf("array of bool\n" );
			int index_id=check_exist($2);
			if(index_id!=-1)
				printf("error : name %s already exists\n", $2->name);
			if(strcmp($4->data_type,"boolean")==0)
				printf("error: inside [] must be an int\n" );
			tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
			strcpy(temp_symb->var_name,$2->name);
			temp_symb->size=$4->int_value;
			strcpy(temp_symb->data_type,"boolean");

			temp_symb->store.f=(bool *)malloc($4->int_value*sizeof(bool));
			memset(temp_symb->store.f,false,$4->int_value);
			symtbl[id_count++]=temp_symb;
			free_ptr($2);

		}

		;

pgmbody : BEG stmtlist END {
															printf("evaluating the ast\n");
															evaluate_ast($2);
		};
stmtlist :  stmt stmtlist{
													ast *temp = (ast *)malloc(sizeof(ast));
													$$=temp;
													strcpy(temp->data_type,"void");
													$$->node_type = SLIST;

													$$->ptr1 = $1;
													$$->ptr2 = $2;





}
			| stmt {

												$$=$1;



			};
stmt : assign {
												$$=$1;


}
	|	cond {
												$$=$1;
	}
	|  loop {
												$$=$1;
	}
	| r { $$ = $1; }
	| w { $$= $1; }
	;

r : READ ID '[' expr ']' ';'{
		int index_id=check_exist($2);
		if( index_id !=-1)
			{

				$$=(ast*)malloc(sizeof(ast));
				strcpy($$->data_type,symtbl[index_id]->data_type);
				strcpy($2->name, "read_array");
				$$->entry = index_id;
				$$->node_type=READ;
				if(strcmp($4->data_type,"boolean")==0)
					printf("error: inside [] must be an int\n" );



					$$->ptr1=$4;


			}
			else
					printf("error not declared\n" );

	}
	| 	 READ ID ';'{
			int index_id=check_exist($2);
			if( index_id !=-1)
				{

					$$=(ast*)malloc(sizeof(ast));
					strcpy($$->data_type,symtbl[index_id]->data_type);
					strcpy($$->name, "read");
					$$->entry = index_id;
					$$->node_type=READ;

					$$->ptr1=NULL;


				}
				else
						printf("error not declared\n" );

		}
	;
w : WRITE expr ';'{
			$$=(ast*)malloc(sizeof(ast));
			strcpy($$->data_type,$2->data_type);
			strcpy($$->name, "write");
			$$->node_type=WRITE;
			$$->ptr1=$2;
};
assign : ID  '=' expr ';'  {
													//	printf("in id = expr\n");
														$$ = (ast*)malloc(sizeof(ast));
														strcpy($$->name,"assign");

														$$->node_type = EQ;
														strcpy($$->data_type,"boolean");
														int index_id=check_exist($1);

														printf("%d\n",index_id );

														//printf("%s\n",$3->data_type );
														//printf("%s %s\n",symtbl[index_id]->data_type,symtbl[index_id]->var_name);
														//printf("%d\n",check_dtype(symtbl[index_id],$3->data_type) );
														if( index_id !=-1 && strcmp(symtbl[index_id]->data_type,$3->data_type)==0)
															{

/*

																if(strcmp(symtbl[index_id]->data_type,"boolean"))
																{
																	printf("expr evaluated to %d \n",$3->int_value);
																	*(symtbl[index_id]->store.f)=$3->bool_value;


																}
																else
																{
																		printf("expr evaluated to %d \n",$3->bool_value);
																		*(symtbl[index_id]->store.i)=$3->int_value;

																}
*/
																$$->bool_value = true;




															}
														else
															{
																printf("kya error  cannot evaluate unmatching dtypes %s ... %s\n",symtbl[index_id]->data_type,$3->data_type);
																$$->bool_value = false;
														}

														$$->ptr1= $1;
														$$->ptr1->entry = index_id;               //we need this
														strcpy($$->ptr1->data_type,$3->data_type);
														$$->ptr2= $3;


													}
					| ID '[' expr ']' '=' expr ';' {

					//	printf("in id = expr[]\n");
						$$ = (ast*)malloc(sizeof(ast));
						strcpy($$->name,"assign");

						if(strcmp($3->data_type,"boolean")==0)
							printf("error: inside [] must be an int\n" );
						$$->node_type = EQ;

						strcpy($$->data_type,"boolean");
						int index_id=check_exist($1);
					//	printf("%d\n",index_id );
						$$->entry = index_id;
					//printf("the datatype is %s\n", $6->data_type);
						if( index_id !=-1 && strcmp(symtbl[index_id]->data_type,$6->data_type)==0)
							{
/*
								if(strcmp(symtbl[index_id]->data_type,"boolean"))
								{
									printf("expr evaluated to %d \n",$6->bool_value);
									*(symtbl[index_id]->store.f  + ($3->int_value))=($6->bool_value );
								}
								else{
									printf("expr evaluated to %d \n",$6->int_value);
									*(symtbl[index_id]->store.i + ($3->int_value))=($6->int_value);

								}
*/

								($$->bool_value) = true;


							}
						else
							{printf("kya error  cannot evaluate2!\n");

							($$->bool_value) = false;
						}

						$$->ptr1= $1;
						$$->ptr1->entry = index_id;               //we need this
						strcpy($$->ptr1->data_type,$3->data_type);
						$$->ptr2= $3;
						$$->ptr3= $6;


					}

					;
expr : expr '+' expr {
												if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
												{
													$$ = (ast*)malloc(sizeof(ast));
													strcpy($$->name,"plus");

													$$->node_type=PLUS;
													strcpy($$->data_type,"integer");

												}else printf("error: conflicting data types or not integer data types %s %s\n",$1->data_type,$3->data_type);

												$$->ptr1=$1;
												$$->ptr2=$3;




}
	| expr '-' expr {
		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (ast*)malloc(sizeof(ast));
			strcpy($$->name,"minus");

			$$->node_type=MINUS;
			strcpy($$->data_type,"integer");

		}else printf("error: conflicting data types or not integer data types\n");

		$$->ptr1=$1;
		$$->ptr2=$3;


	}
	| expr '*' expr {

		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (ast*)malloc(sizeof(ast));
			strcpy($$->name,"mul");

			$$->node_type=MUL;
			strcpy($$->data_type,"integer");

		}else printf("error: conflicting data types or not integer data types\n");

		$$->ptr1=$1;
		$$->ptr2=$3;

	}
	| expr '/' expr {

		if(strcmp($1->data_type,$3->data_type)==0 && check_dtype($1,"integer"))
		{
			$$ = (ast*)malloc(sizeof(ast));
			strcpy($$->name,"div");

			$$->node_type=DIV;
			strcpy($$->data_type,"integer");

		}else printf("error: conflicting data types or not integer data types\n");

		$$->ptr1=$1;
		$$->ptr2=$3;
	}
	| expr EQEQ expr {

		if(strcmp($1->data_type,$3->data_type)==0)
		{
			$$ = (ast*)malloc(sizeof(ast));
			strcpy($$->name,"eqeq");

			$$->node_type=EQEQ;
			strcpy($$->data_type,"boolean");


		}else printf("error: conflicting data types\n");
		$$->ptr1=$1;
		$$->ptr2=$3;


	}
	| expr NEQ expr {
		if(strcmp($1->data_type,$3->data_type)==0)
		{
			$$ = (ast*)malloc(sizeof(ast));
			strcpy($$->name,"neq");

			$$->node_type=NEQ;
			strcpy($$->data_type,"boolean");


		}else printf("error: conflicting data types\n");
		$$->ptr1=$1;
		$$->ptr2=$3;

	}
	| ID '[' expr ']' {
	//	printf("id[]\n");
		int index_id=check_exist($1);
		if( index_id !=-1)
			{


				strcpy($1->data_type,symtbl[index_id]->data_type);
				strcpy($1->name, "id_array");
				$1->entry = index_id;
				$1->node_type=ID;
				if(strcmp($3->data_type,"boolean")==0)
					printf("error: inside [] must be an int\n" );


					$$=$1;
					$$->ptr1=$3;


			}
			else
					printf("error not declared\n" );


	//	printf("the datatype is %s name is %s\n",$1->data_type,$1->name );


	//	free_ptr($3);


	}
	| '(' expr ')' {$$=$2;}
	| ID {
		//	printf("id\n");
			int index_id=check_exist($1);
			if( index_id !=-1)
				{


					strcpy($1->data_type,symtbl[index_id]->data_type);
					strcpy($1->name, "id");
					$1->entry = index_id;
					$1->node_type=ID;

					$1->ptr1 = NULL;

						$$=$1;


				}
				else
						printf("error not declared\n" );


		//	printf("id :the datatype is %s name is %s\n",$1->data_type,$1->name );

		}
	| NUM {
		$$=$1;
	}
	| T {$$=$1;}
	| F {$$=$1;}
	;


cond : IF expr THEN stmtlist ENDIF{

				$$=(ast*)malloc(sizeof(ast));
				strcpy($$->name,"if");
				$$->node_type=IF;
				$$->ptr1=$2;
				$$->ptr2=$4;
				$$->ptr3=NULL;

}
	| IF expr THEN stmtlist ELSE stmtlist ENDIF{
		$$=(ast*)malloc(sizeof(ast));
		strcpy($$->name,"ifelse");
		$$->node_type=IF;
		$$->ptr1=$2;
		$$->ptr2=$4;
		$$->ptr3=$6;

	}
;
loop : WHILE expr DO stmtlist ENDWHILE{
	$$=(ast*)malloc(sizeof(ast));
	strcpy($$->name,"while");
	$$->node_type=WHILE;
	$$->ptr1=$2;
	$$->ptr2=$4;
	$$->ptr3=NULL;



}
;



%%

int check_exist(ast *yylval)
{
	int i;
	for(i=0;i<id_count;i++ )
		if(strcmp(symtbl[i]->var_name,yylval->name)==0)
			break;

	if(i!=id_count )
		return i;
	return -1;

}
int check_dtype(ast *yylval,char *b)
{
//	printf("yoyoy...%s %s\n",yylval->data_type ,yylval->name);
	//printf("%s\n", b);
	if( strcmp(yylval->data_type,b)==0)
		return 1;
	return 0;

}
void free_ptr(ast *yylval)
{
	if(yylval==NULL)
	{
		printf("cannot free NULL ptr\n");
		return;
	}
	free(yylval);
	yylval =NULL;
}
yyerror()
{
	printf("yyerror\n");
	return;
}
void evaluate_ast(ast *root)
{
	if(root==NULL)
		{printf("should not print its NULLLLLLLLLL\n");return;}
	if(root->node_type==SLIST)
	{
		printf("SLIST\n" );
		evaluate_ast(root->ptr1); // stmnt
		evaluate_ast(root->ptr2); // slist
	}
	else if(root->node_type== EQ)
	{
		printf("EQ\n" );
		evaluate_ast(root->ptr2);
		printf("id_ind : %d  name: %s rhs: %d  dt: %s\n ",root->ptr1->entry,root->ptr1->name,root->ptr2->int_value,root->ptr1->data_type );

		if(symtbl[root->ptr1->entry]->size==0)
		{
			printf("in eq not array\n" );

			if(strcmp(root->ptr1->data_type,"integer")==0)
			{

					*(symtbl[root->ptr1->entry]->store.i)= root->ptr2->int_value;
				//	print_symbols();
			}
			else
				*(symtbl[root->ptr1->entry]->store.f)= root->ptr2->bool_value;
		}else // array
		{

			evaluate_ast(root->ptr3);
			if(strcmp(root->ptr1->data_type,"integer")==0)
				*(symtbl[root->ptr1->entry]->store.i + root->ptr2->int_value )= root->ptr3->int_value;
			else
				*(symtbl[root->ptr1->entry]->store.f + root->ptr2->int_value )= root->ptr3->bool_value;
		}
		//print_symbols();
	}
	else if(root->node_type== PLUS)
	{
		printf("PLUS\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value + root->ptr2->int_value;
	}
	else if(root->node_type== MINUS)
	{
		printf("MINUS\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== MUL)
	{
		printf("MUL\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== DIV)
	{
		printf("DIV\n");
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value / root->ptr2->int_value;
	}
	else if(root->node_type== EQEQ)
	{
		printf("EQEQ\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		if(strcmp(root->ptr1->data_type,"integer")==0)
			root->bool_value=root->ptr1->int_value == root->ptr2->int_value;
		else
			root->bool_value=root->ptr1->bool_value == root->ptr2->bool_value;
	}
	else if(root->node_type== NEQ)
	{
		printf("NEQ\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		if(strcmp(root->ptr1->data_type,"integer")==0)
			root->bool_value=root->ptr1->int_value != root->ptr2->int_value;
		else
			root->bool_value=root->ptr1->bool_value != root->ptr2->bool_value;
	}
	else if(root->node_type== ID)
	{
		printf("ID\n" );
		if(root->ptr1==NULL) // not array
		{
			printf("not array id_ind: %d\n",root->entry);
			if(strcmp(root->data_type,"integer")==0)
				root->int_value = *(symtbl[root->entry]->store.i);
			else
				root->bool_value = *(symtbl[root->entry]->store.f);
		}
		else //array
		{
			printf("array id_ind: %d\n",root->entry );
			evaluate_ast(root->ptr1);
			if(strcmp(root->data_type,"integer")==0)
				{
					printf("yes int\n" );
					root->int_value = *(symtbl[root->entry]->store.i + root->ptr1->int_value);
				}
			else
				root->bool_value = *(symtbl[root->entry]->store.f + root->ptr1->int_value);
		}

	}
	else if(root->node_type== IF)
	{
		printf("IF\n");
		evaluate_ast(root->ptr1);
		printf("bool val: %d\n",root->ptr1->bool_value );
		if(root->ptr1->bool_value)
			evaluate_ast(root->ptr2);
		else
			{
				if(root->ptr3!=NULL)  // else
				evaluate_ast(root->ptr3);
			}
	}
	else if(root->node_type == WHILE)
	{
		printf("WHILE\n" );
		while(1)
		{
			evaluate_ast(root->ptr1);
			if(root->ptr1->bool_value==false)
				break;
			evaluate_ast(root->ptr2);
		}
	}
	else if(root->node_type == NUM || root->node_type == T || root->node_type == F)
	{
		printf("NUM/T/F %d\n",root->int_value );
			return;
	}
	else if(root->node_type == READ)
	{
		printf("READ\n" );
		if(symtbl[root->entry]->size==0)
		{
			scanf("%d\n",symtbl[root->entry]->store.i );
		}
		else
		{
			evaluate_ast(root->ptr1);
			scanf("%d\n",symtbl[root->entry]->store.i + root->ptr1->int_value );
		}
		printf("read over\n" );
	}
	else if(root->node_type == WRITE)
	{
		printf("WRITE\n");
		evaluate_ast(root->ptr1);
		printf("writing %d %d\n",root->ptr1->int_value ,root->ptr1->entry);

	}
	else
	{
		printf("shit...%s!! \n", root->name );
	}

}

void print_symbols()
{
	int i;
	printf("\n");
	for(i=0;i<id_count;i++)
	{
		if(symtbl[i]->size == 0){
		printf("%s   ", symtbl[i]->var_name);
		printf("%d\n", *(symtbl[i]->store.i));
	}
	else{
		printf("%s   ", symtbl[i]->var_name);
		int j;
		for(j=0;j<symtbl[i]->size;j++)
			printf("%d ", *(symtbl[i]->store.i + j));
		printf("\n");
	}
	}
}

main()
{
	yyparse();
	return 1;
}
