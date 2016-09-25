#include "Scase.h"

case_t* get_case()
{
	case_t* this_case = (case_t*)malloc(sizeof(case_t));

	this_case->value  = i++;
	this_case->p_Next = NULL;

	return this_case;
}