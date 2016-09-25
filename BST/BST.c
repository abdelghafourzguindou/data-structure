#include "BST.h"

BST_t* Add_Node(BST_t* root, int data)
{
	if(root == NULL) 
	{
		BST_t* new_node = (BST_t*)malloc(sizeof(BST_t));
		new_node->Data       = data;
		new_node->p_RightBST = NULL;
		new_node->p_LeftBST  = NULL;
		return new_node;
	}
	else
	{
		if     (data <= root->Data) root->p_LeftBST  = Add_Node(root->p_LeftBST,  data);
		else if(data > root->Data) root->p_RightBST = Add_Node(root->p_RightBST, data);
	}
	
	return root;
}

void Print_BST_Inorder(BST_t* root)
{
	if(root != NULL)
	{
		Print_BST_Inorder(root->p_LeftBST);
		printf("%d\t", root->Data);
		Print_BST_Inorder(root->p_RightBST);
	}
}

void Print_BST_Preorder(BST_t* root)
{
	if(root != NULL)
	{
		printf("%d\t", root->Data);
		Print_BST_Preorder(root->p_LeftBST);
		Print_BST_Preorder(root->p_RightBST);
	}
}

void Print_BST_Postorder(BST_t* root)
{
	if(root != NULL)
	{
		Print_BST_Postorder(root->p_LeftBST);
		Print_BST_Postorder(root->p_RightBST);
		printf("%d\t", root->Data);
	}
}

int Serch_Node(BST_t* root, int thisData)
{
	if(root != NULL)
	{
		if(root->Data == thisData) return 1;
		else if(thisData < root->Data) Serch_Node(root->p_LeftBST, thisData);
		else Serch_Node(root->p_RightBST, thisData);
	}

	else return 0;
}

BST_t* FindMin(BST_t* root)
{
	if(root == NULL) return NULL;
	if(root->p_LeftBST) return FindMin(root->p_LeftBST);
	else return root;
}

BST_t* Free_Node(BST_t* root, int data)
{
	if(root == NULL) return root;
	else if(data < root->Data) root->p_LeftBST  = Free_Node(root->p_LeftBST,  data);
	else if(data > root->Data) root->p_RightBST = Free_Node(root->p_RightBST, data);
	else
	{
		//case 1 : no child
		if(root->p_LeftBST == NULL && root->p_RightBST == NULL)
		{
			free(root);
			root = NULL;
		}
		//case 2 : 1 child
		else if(root->p_LeftBST == NULL)
		{
			BST_t* temp = root;
			root = root->p_RightBST;
			free(temp);
		}
		else if(root->p_RightBST == NULL)
		{
			BST_t* temp = root;
			root = root->p_LeftBST;
			free(temp);
		}
		//case 3 : 2 child
		else
		{
			BST_t* temp = FindMin(root->p_RightBST);
			root->Data = temp->Data;
			root->p_RightBST = Free_Node(root->p_RightBST, temp->Data);
		}
	}
	return root;
}

int zeros(BST_t *root, int z)
{
	if(root)
	{
	z = zeros(root->p_LeftBST, z);
	z = zeros(root->p_RightBST, z);
	if(root->Data == 0) 
	{
		return z + 1;
	}
	}

	return z;
}

BST_t* BST_Free(BST_t* root)
{
	BST_Free(root->p_LeftBST);
	BST_Free(root->p_RightBST);
	free(root);
	
	return NULL;
}