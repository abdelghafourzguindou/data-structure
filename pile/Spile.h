#include "Scase.h"

typedef struct _pile {
	case_t* p_Head;
	case_t* p_Queue;
} pile_t;

pile_t* get_pile();
pile_t* p_empiler(pile_t*);
pile_t* p_depiler(pile_t*);
pile_t* p_empty(pile_t*);
int p_itIs_empty(pile_t*);