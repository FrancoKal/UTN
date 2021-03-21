#include "func_long.h"
#include "func_calc.h"

//-----------------------------------------------------------------

int longitud (int oper1)
{
	int i=1;

	while (oper1>BASE)
	{
		oper1 = oper1/BASE;
		i++;
	}

	return i;
}

//-----------------------------------------------------------------



