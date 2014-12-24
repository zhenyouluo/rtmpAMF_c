
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	//V_BOOL,
	V_CHAR,
	V_INT,
	V_DOUBLE,
	V_NULL
}variant_type;

typedef struct 
{
	variant_type	type;
	void*			value;
}variant;

void 
alloc_variant(variant *var, variant_type type)
{
	switch(type)
	{
		case V_CHAR:
			var->value = malloc(sizeof(char));
			break;	
		case V_INT:
			var->value = malloc(sizeof(int));
			break;
		case V_DOUBLE:
			var->value = malloc(sizeof(int));
			break;
		default:
			var->value = NULL;
	}
	return;
}
