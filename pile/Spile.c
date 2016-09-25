#include "Spile.h"

int p_itIs_empty(pile_t* stack)
{
	if(stack->p_Head == NULL && stack->p_Queue == NULL) return 1;
	else return 0;
}

pile_t* p_empty(pile_t* stack)
{
	if(!p_itIs_empty(stack))
	{
		case_t* p_Corsor = stack->p_Head;
		case_t* p_Pred   = NULL;

		while(p_Corsor != NULL)
		{
			p_Pred   = p_Corsor;
			p_Corsor = p_Corsor->p_Next;
			free(p_Pred);
		}
	}
	stack->p_Head = stack->p_Queue = NULL;
	return stack;
}

pile_t* get_pile()
{
	pile_t* stack = (pile_t*)malloc(sizeof(pile_t));
	stack->p_Head = stack->p_Queue = NULL;
}

pile_t* p_emplier(pile_t* stack)
{
	case_t* new_case = get_case();

	new_case->p_Next    = stack->p_Head;
	stack->p_Head		= new_case;

	if(stack->p_Queue == NULL) stack->p_Queue = new_case;

	return stack;
}

pile_t* p_depiler(pile_t* stack)
{
	if(stack->p_Queue != NULL)
	{
		case_t* this_case = stack->p_Head;
		stack->p_Head = this_case->p_Next;
		free(this_case);

		if(stack->p_Head == stack->p_Queue)
		{
			free(stack->p_Head);
			free(stack->p_Queue);
		}
	}
	stack->p_Head = stack->p_Queue = NULL;

	return stack;
}