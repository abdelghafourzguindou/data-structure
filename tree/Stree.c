#include "Stree.h"

tree_t* Get_Tree()
{
	tree_t* new_tree = (tree_t*)malloc(sizeof(tree_t));

	new_tree->p_Root          = NULL;
	new_tree->p_SUBright_tree = NULL;
	new_tree->p_SUBleft_tree  = NULL;

	return new_tree;
}

tree_t* Push_Node(tree_t* root)
{
	node_t* newNode = Get_Node();

	if(root->p_Root == NULL) root->p_Root = newNode;
	else if(newNode->vNode <= root->p_Root->vNode) Push_Node(root->p_SUBleft_tree);
	else Push_Node(root->p_SUBright_tree);

	return root;
}