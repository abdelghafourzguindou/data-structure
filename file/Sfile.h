#include "Scase.h"

typedef struct _file {
	case_t* f_Head;
	case_t* f_Queue;
} file_t;

file_t* get_file();
file_t* f_emfiler(file_t*);
file_t* f_defiler(file_t*);
file_t* f_empty(file_t*);
int f_itIs_empty(file_t*);