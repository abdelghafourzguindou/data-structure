#include "Snode.h"


node_t* Get_Node()
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t));

	new_node->vNode  = i++;
	new_node->LabelNode = "I'm node of your tree";

	return new_node;
}