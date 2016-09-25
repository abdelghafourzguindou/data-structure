#include "sNode.h"

Node_t* Get_Node() {
	
	Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));

	newNode->NodeLabel = getchar();
	newNode->NodeIndex = thisINDEX++;

	return newNode;
}

