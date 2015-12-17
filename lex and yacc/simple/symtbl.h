// for symbols
#include <stdbool.h>
union type{
	bool *f;
	int *i;

	};
typedef struct ttbl{
	char var_name[32];
	int size;
	char data_type[32];
	union type store;
} tbl;


/*
decl integer a; enddecl begin if a==b then a=b; endif end
decl integer a; enddecl begin while a==b do a=b; endwhile end*/
