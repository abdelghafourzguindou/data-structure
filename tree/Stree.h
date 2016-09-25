#include "Snode.h"

typedef struct _tree
{
	node_t* p_Root;
	struct _tree* p_SUBright_tree; 
	struct _tree* p_SUBleft_tree;

} tree_t;

tree_t* Get_Tree();
tree_t* Push_Node(tree_t*);
tree_t* Concatinate_Tree(tree_t*, tree_t*);

int Serch_Node(tree_t*);
int tree_IsIt_empty(tree_t*);

void Free_Tree(tree_t**);
void Print_Tree(tree_t*);