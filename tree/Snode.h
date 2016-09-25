#include <stdio.h>
#include <stdlib.h>

static int i = 0;

typedef struct _node
{
	int vNode;
	char* LabelNode;

} node_t;

node_t* Get_Node();

void Print_Node(node_t);