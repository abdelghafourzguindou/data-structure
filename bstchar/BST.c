#include "BST.h"

BST_t* Add_Node(BST_t* root, char* data)
{
	if(root == NULL) 
	{
		BST_t* new_node = (BST_t*)malloc(sizeof(BST_t));
		strcpy(new_node->Data, data);
		new_node->occ = 1;
		new_node->p_RightBST = NULL;
		new_node->p_LeftBST  = NULL;

		return new_node;
	}
	else
	{
		if     (strcmp(data, root->Data) < 0) root->p_LeftBST  = Add_Node(root->p_LeftBST,  data);
		else if(strcmp(data, root->Data) > 0) root->p_RightBST = Add_Node(root->p_RightBST, data);
		else root->occ++;
	}
	
	return root;
}

void BST_fread(BST_t **BST_root)
{
	FILE *F = fopen("thisBSTchar.txt", "r");
	if(F)
	{
		char word[10];
		BST_t *root = *BST_root;
		while(!feof(F)) 
		{
			fscanf(F, "%s ", word);

			printf("\n%s\n", word); system("PAUSE");

			root = Add_Node(root, word);
		}
		*BST_root = root;
		printf("\nOperation avec succe\n");
	}
	else printf("\nOperation eroner\n");
}

void Print_BST_Inorder(BST_t* root)
{
	if(root != NULL)
	{
		Print_BST_Inorder(root->p_LeftBST);
		printf("Data = %s\tOcc = %d\n", root->Data, root->occ);
		Print_BST_Inorder(root->p_RightBST);
	}
}

void Print_BST_Preorder(BST_t* root)
{
	if(root != NULL)
	{
		printf("Data = %s\tOcc = %d\n", root->Data, root->occ);
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
		printf("Data = %s\tOcc = %d\n", root->Data, root->occ);
	}
}

int Serch_Node(BST_t* root, char* thisData)
{
	if(root != NULL)
	{
		if(!strcmp(root->Data, thisData)) return 1;
		else if(strcmp(thisData, root->Data) < 0) Serch_Node(root->p_LeftBST, thisData);
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

BST_t* Free_Node(BST_t* root, char* data)
{
	if(root == NULL) return root;
	else if(strcmp(data, root->Data) < 0) root->p_LeftBST  = Free_Node(root->p_LeftBST,  data);
	else if(strcmp(data, root->Data) > 0) root->p_RightBST = Free_Node(root->p_RightBST, data);
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
			strcpy(root->Data, temp->Data);
			root->p_RightBST = Free_Node(root->p_RightBST, temp->Data);
		}
	}
	return root;
}

BST_t* BST_Free(BST_t* root)
{
	BST_Free(root->p_LeftBST);
	BST_Free(root->p_RightBST);
	free(root);
	
	return NULL;
}