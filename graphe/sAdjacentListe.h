#include "sAdjacent.h"

typedef struct _AdjacentListe
{
	Adjacent_t* p_Head;
	Adjacent_t* p_Queue;
	int AdjacentNumber;
	
} AdjacentListe_t;

AdjacentListe_t* Get_AjacentList();
AdjacentListe_t* Update_AdjacentList(AdjacentListe_t*);

void Free_AdjacentList(AdjacentList_t*);
void Remove_AdjacentList(AdjacentListe_t*);
void Print_AdjacentList(Adjacent_t*);