#include "recursion.h"

int recursion::program()
{
	declaration_list();
	return 0;
}

int recursion::declaration_list()
{
	if (token == INT || token == VOID)
	{ 
		declaration();
		declaration_list();
	}
	else
		return 0;
}
