#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int i = 0;

typedef struct _BST
{
	int Data;
	struct _BST* p_RightBST;
	struct _BST* p_LeftBST;

} BST_t;

BST_t* Add_Node(BST_t*, int);
BST_t* Free_Node(BST_t*, int);
BST_t* FindMin(BST_t*);
BST_t* BST_Free(BST_t*);

int Serch_Node(BST_t*, int);

void Print_BST_Inorder(BST_t*);
void Print_BST_Preorder(BST_t*);
void Print_BST_Postorder(BST_t*);
