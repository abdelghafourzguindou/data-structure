#include "Sfile.h"

int f_itIs_empty(file_t* file)
{
	if(file->f_Head == NULL && file->f_Queue == NULL) return 1;
	else return 0;
}

file_t* f_empty(file_t* file)
{
	if(!f_itIs_empty(file))
	{
		case_t* f_Corsor = file->f_Head;
		case_t* f_pred   = NULL;

		while(f_Corsor != NULL)
		{
			f_pred   = f_Corsor;
			f_Corsor = f_Corsor->p_Next;
			free(f_pred);
		}
	}
	file->f_Head = file->f_Queue = NULL;
	return file;
}

file_t* get_file()
{
	file_t* file = (file_t*)malloc(sizeof(file_t));
	file->f_Head = file->f_Queue = NULL;
}

file_t* f_emflier(file_t* file)
{
	case_t* new_case = get_case();

	new_case->p_Next    = file->f_Head;
	file->f_Head		= new_case;

	if(file->f_Queue == NULL) file->f_Queue = new_case;

	return file;
}

file_t* f_defiler(file_t* file)
{
	if(file->f_Queue != NULL)
	{
		case_t* this_case = file->f_Head;
		case_t* pred_case = NULL;

		while(this_case->p_Next != NULL)
		{
			pred_case = this_case;
			this_case = this_case->p_Next;
		}

		file->f_Queue = pred_case;
		free(this_case);

		if(file->f_Head == file->f_Queue)
		{
			free(file->f_Head);
			free(file->f_Queue);
		}
	}
	file->f_Head = file->f_Queue = NULL;

	return file;
}