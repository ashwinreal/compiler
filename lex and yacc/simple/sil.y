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
int label_ctr=0;
int reg_ctr=0;
int var_mem=0;
void free_ptr(ast *yylval);
int evaluate_ast(ast *root);
void print_symbols();
int allocate_mem(int size);
int get_reg();
void free_reg();
int get_label();
FILE *fp;

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
%token DLIST

%left EQEQ NEQ
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
pgm : pgmdecl pgmbody {
											printf("complete ast\n");

											evaluate_ast($1);       // declaration
											print_symbols();
											fprintf(fp, "START\n" );
											evaluate_ast($2);				// body
											fprintf(fp, "HALT\n" );

											fclose(fp);

											exit(1);
										};
pgmdecl : DECL dlist ENDDECL {
								$$=$2;

};
dlist : dstmt dlist{

										$$=(ast *) malloc(sizeof(ast));
										$$->node_type = DLIST;
										strcpy($$->name,"dlist");
										$$->ptr1=$1;
										$$->ptr2=$2;
										}
 			| dstmt {$$=$1;
				//printf("yoyoy %d\n",$$->node_type );
			};
dstmt : BOOLEAN  ID ';' {
						int index_id=check_exist($2);
						if(index_id!=-1)
							printf("error : name %s already exists\n", $2->name);
						tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
						strcpy(temp_symb->var_name,$2->name);
						temp_symb->size=0;
					  strcpy(temp_symb->data_type,"boolean");
						symtbl[id_count++]=temp_symb;
						free_ptr($2);
						//printf("declaration %s",yylval->data_type);

						$$=(ast *) malloc(sizeof(ast));
						$$->node_type=BOOLEAN;
						$$->entry = id_count-1;




					}
		| INTEGER  ID ';' {

				int index_id=check_exist($2);
				if(index_id!=-1)
					printf("error : name %s already exists\n", $2->name);
				tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
				strcpy(temp_symb->var_name,$2->name);
				temp_symb->size=0;
				strcpy(temp_symb->data_type,"integer");
				symtbl[id_count++]=temp_symb;
				free_ptr($2);
				//	printf("declaration %s",yylval->data_type);


				$$=(ast *) malloc(sizeof(ast));
				$$->node_type= INTEGER;
				$$->entry = id_count-1;
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
				symtbl[id_count++]=temp_symb;
				free_ptr($2);

				$$=(ast *) malloc(sizeof(ast));
				$$->node_type= INTEGER;
				$$->entry = id_count-1;
				$$->ptr1 = $4;

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
			symtbl[id_count++]=temp_symb;
			free_ptr($2);

			$$=(ast *) malloc(sizeof(ast));
			$$->node_type= BOOLEAN;
			$$->entry = id_count-1;
			$$->ptr1 = $4;
		}

		;

pgmbody : BEG stmtlist END {
														$$=$2;
														//	printf("evaluating the ast\n");
														//	evaluate_ast($2);
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









int evaluate_ast(ast *root)
{

	if(root==NULL)
		{

			printf("should not print its NULLLLLLLLLL\n");
			return -1;
		}
	if(root->node_type==SLIST)
	{
		printf("SLIST\n" );
		fprintf(fp, "\n");
		int p1= evaluate_ast(root->ptr1); // stmnt
		int p2 = evaluate_ast(root->ptr2); // slist
		return -1;
	}
	else if(root->node_type == EQ)
	{
		fprintf(fp, "\n");
		printf("EQ\n" );
		printf("%d\n",root->ptr2->node_type );
		int p2 = evaluate_ast(root->ptr2);
		//printf("%d\n",p2);

		if(symtbl[root->ptr1->entry]->size==0)
		{
		//	printf("in eq not array\n" );


				int id_add = symtbl[root->ptr1->entry]->store;
				int reg = get_reg();
				fprintf(fp, "MOV R%d, %d\n",reg,id_add );
				fprintf(fp, "MOV [R%d], R%d\n",reg,p2 );

				free_reg();
				free_reg();

					//*(symtbl[root->ptr1->entry]->store.i)= root->ptr2->int_value;
				//	print_symbols();

		}else // array
		{

				int p3=evaluate_ast(root->ptr3);

				//int id_add = symtbl[root->ptr1->entry]->store + root->ptr2->int_value  ; wrong
				int reg = get_reg();
				fprintf(fp, "MOV R%d, %d\n",reg,symtbl[root->ptr1->entry]->store);
				fprintf(fp, "ADD R%d, R%d\n",reg,p2 );
				fprintf(fp, "MOV [R%d], R%d\n",reg,p3);

				free_reg();
				free_reg();
				free_reg();


		}
		//print_symbols();

		return -1;
	}
	else if(root->node_type== PLUS)
	{
		fprintf(fp, "\n");
		printf("PLUS\n" );
		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);



		fprintf(fp, "ADD R%d, R%d\n",p1,p2 );
		free_reg();
		return p1;


		//root->int_value=root->ptr1->int_value + root->ptr2->int_value;
	}
	else if(root->node_type== MINUS)
	{
		fprintf(fp, "\n");
		printf("MINUS\n" );
		int p1 =evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);



	//	root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== MUL)
	{
		fprintf(fp, "\n");
		printf("MUL\n" );
		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);


	//	root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== DIV)
	{
		fprintf(fp, "\n");
		printf("DIV\n");
		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);



	//	root->int_value=root->ptr1->int_value / root->ptr2->int_value;
	}
	else if(root->node_type== EQEQ)
	{
		fprintf(fp, "\n");
		printf("EQEQ\n" );
		int r1=evaluate_ast(root->ptr1);
		int r2=evaluate_ast(root->ptr2);





				fprintf(fp, "EQ R%d, R%d\n",r1,r2 );
				free_reg();  // free r2
				return r1;



	}
	else if(root->node_type== NEQ)
	{
		fprintf(fp, "\n");
		printf("NEQ\n" );
		int r1=evaluate_ast(root->ptr1);
		int r2=evaluate_ast(root->ptr2);



				fprintf(fp, "NE R%d, R%d\n",r1,r2 );
				free_reg();  // free r2
				return r1;


	}
	else if(root->node_type== ID)
	{
		fprintf(fp, "\n");
		printf("ID\n" );
		if(root->ptr1==NULL) // not array
		{
			printf("not array id_ind: %d\n",root->entry);

			int r1 = get_reg();
			int r2 = get_reg();
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store );
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r2 );
			free_reg();
			return r1;
		}
		else //array
		{
		//	printf("array id_ind: %d\n",root->entry );

			int r1 = get_reg();
			int r2 = get_reg();
			int p1 =evaluate_ast(root->ptr1);
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store);
			fprintf(fp, "ADD R%d, R%d\n",r2,p1 );
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r2 );
			free_reg();
			free_reg();


			return r1;
		}

	}
	else if(root->node_type== IF)
	{
		fprintf(fp, "\n");
		printf("IF\n");
		int p1=evaluate_ast(root->ptr1);


		int l1=get_label();
		fprintf(fp, "IF%d:\n",l1);
		fprintf(fp, "JZ R%d, ELSE%d\n",p1,l1 );
		int p2=evaluate_ast(root->ptr2);
		fprintf(fp, "JMP ENDIF%d\n",l1 );
		fprintf(fp, "ELSE%d:\n",l1 );
		int p3 = evaluate_ast(root->ptr3);

		fprintf(fp, "ENDIF%d:\n",l1);
	}
	else if(root->node_type == WHILE)
	{
		fprintf(fp, "\n");
		printf("WHILE\n" );

		int l1=get_label();
		fprintf(fp, "LOOP%d:\n",l1);
			int p1=evaluate_ast(root->ptr1);
			fprintf(fp, "JZ R%d, ENDLOOP%d\n",p1,l1 );

			int p3=evaluate_ast(root->ptr2);
		fprintf(fp, "JMP LOOP%d\n",l1 );

		fprintf(fp, "ENDLOOP%d:\n",l1);


	}
	else if(root->node_type == NUM || root->node_type == T || root->node_type == F)
	{
		fprintf(fp, "\n");
		printf("NUM/T/F %d\n",root->int_value );
			int r=get_reg();
			fprintf(fp, "MOV R%d,%d\n",r,root->int_value );
			return r;
	}
	else if(root->node_type == READ)
	{
		fprintf(fp, "\n");
		printf("READ\n" );
		int r1 = get_reg();
		fprintf(fp, "IN R%d\n",r1 );
		int r2= get_reg();

		if(symtbl[root->entry]->size==0)
		{
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store );
			fprintf(fp, "MOV [R%d], R%d\n",r2,r1 );

			free_reg();
			free_reg();


		}
		else
		{
			int p1=evaluate_ast(root->ptr1);
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store );
			fprintf(fp, "ADD R%d, R%d\n",r2,p1 );
			fprintf(fp, "MOV [R%d], R%d\n",r2,r1 );

			free_reg();
			free_reg();
			free_reg();

		}

		printf("read over\n" );
	}
	else if(root->node_type == WRITE)
	{
		fprintf(fp, "\n");
		printf("WRITE\n");
		int p1=evaluate_ast(root->ptr1);

		fprintf(fp, "OUT R%d\n",p1 );
		free_reg();

	}
	else if(root->node_type == DLIST)
	{
		printf("..DLIST\n");
		printf("%s\n",root->name );
		printf("%d %d\n",root->ptr1->node_type, root->ptr1->entry );
		printf("%d \n",root->ptr2->node_type );

		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);
	}
	else if(root->node_type == INTEGER ||  root->node_type == BOOLEAN)
	{
		printf("INTEGER\n");
		if(symtbl[root->entry]->size==0)
		{
			symtbl[root->entry]->store=allocate_mem(1);
		//	fprintf(fp,"%s\n", );

		}
		else{
			symtbl[root->entry]->store=allocate_mem(symtbl[root->entry]->size);
		}
	}
	else
	{
		printf("shit...%s!! \n", root->name );
	}

}










void print_symbols()
{
	int i;
	for(i=0;i<id_count;i++)
		printf("%s %d\n",symtbl[i]->var_name,symtbl[i]->store);
}
int get_reg()
{
	return reg_ctr++;
}
void free_reg()
{
	reg_ctr--;
}
int get_label()
{
	return label_ctr++;
}
int allocate_mem(int size)
{
	int r=var_mem;
	var_mem = var_mem + size;
	return r;
}
main()
{
	fp=fopen("op.sil","w+");
	yyparse();
	return 1;
}
