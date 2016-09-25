#include "sAdjacentList.h"

typedef struct _Graphe
{
	node_t* GrapheNode;
	AdjacentList_t* AdjacentList;

} Graphe_t;

Graphe_t* Get_Graphe();
Graphe_t* Update_Graphe(Graphe_t*);

void Free_Graphe(Graphe_t**);
void Print_Graphe(Graphe_t*);

int Graphe_isIt_Empty(Graphe_t*);