#include "Stree.h"



main()
{
	int stop = 1;

	tree_t* myTree = Get_Tree();

	while(stop)
	{
		myTree = Push_Node(myTree);

		printf("1 pour continu 0 sinon : "); scanf("%d", &stop);
	}
}