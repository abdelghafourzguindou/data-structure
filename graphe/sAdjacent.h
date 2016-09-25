#include "sNode.h"

typedef struct _Adjacent
{
	Node_t* DestinationNode;
	int Value;
	struct _Adjacent* NextAdjacent;

} Adjacent_t;

Adjacent_t* Get_Adjacent();
Adjacent_t* Add_Adjacent();
Adjacent_t* Update_Adjacent(Adjacent_t*);

void Remove_Adjacent(Adjacent_t*);
void Print_Adjacent(Adjacent_t*);