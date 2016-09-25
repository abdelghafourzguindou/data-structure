#include <stdio.h>
#include <stdlib.h>

static int thisINDEX = 0;

typedef struct _Node
{
	char* NodeLabel;
	int   NodeIndex;

} Node_t;

Node_t* Get_Node();
Node_t* Add_Node();
Node_t* Update_Node(Node_t*);

void Remove_Node(Node_t*);
void Print_Node(Node_t*);