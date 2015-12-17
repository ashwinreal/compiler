
#include <stdio.h>
typedef struct astre
{
	char data_type[32];  // boolean , integer or void(for statements)
	int node_type; // use the #define values in y.tab.h

	char name[32]; // for identifiers and functions

	int int_value;   // if a constant
	bool bool_value;

	int entry;

	struct astre *ptr1,*ptr2,*ptr3; // max 3 children (in if)

} ast;
#define YYSTYPE ast*
