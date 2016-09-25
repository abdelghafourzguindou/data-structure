#include "BST.h"

#define console_cls   system("cls");   printf("\n");
#define console_pause printf("\n\n");  system("PAUSE");

void proc_Menu(int* choice)
{
	console_cls;

	printf("\n\t\t\t############### BST MENU ###############\n");
	printf("\t\t\t\t1.Add node\n");
	printf("\t\t\t\t2.Inorder print\n");
	printf("\t\t\t\t3.Preorder print\n");
	printf("\t\t\t\t4.Postorder print\n");
	printf("\t\t\t\t5.Serch node\n");
	printf("\t\t\t\t6.Update node\n");
	printf("\t\t\t\t7.Remove node\n");
	printf("\t\t\t\t8.Empty BST\n");
	printf("\t\t\t\t9.BST from FILE\n");
	printf("\t\t\t\t10.End\n");
	printf("\t\t\t########################################\n");
	printf("\t\t\tYour choise pls : ");
	int c; 
	scanf("%d", &c);
	*choice = c;
}

main()
{
	BST_t* root = NULL;

	int doing = 1, choice;

	char data[10], this[10];

	while(doing)
	{
		proc_Menu(&choice);
		switch(choice)
		{
			case 1 : console_cls;
				int x = 1;
				while(x)
				{
				printf("\ndata pls : ");
				scanf("%s", data);
				root = Add_Node(root, data);
				printf("\n1 for continue & 0 else : ");
				scanf("%d", &x);
				}
			console_pause;
			break;

			case 2 : console_cls;
				Print_BST_Inorder(root);
			console_pause;
			break;
			case 3 : console_cls;
				Print_BST_Preorder(root);
			console_pause;
			break;
			case 4 : console_cls;
				Print_BST_Postorder(root);
			console_pause;
			break;
			case 5 : console_cls;
				printf("\nGive : ");
				scanf("%s", this);
				if(Serch_Node(root, this)) printf("\nExist\n");
				else printf("\nNo Exist\n");
			console_pause;
			break;
			case 6 : console_cls;
				
			console_pause;
			break;
			case 7 : console_cls;
				printf("\nGive : ");
				scanf("%s", this);
				root = Free_Node(root, this);
			console_pause;
			break;
			case 8 : console_cls;
				root = BST_Free(root);
			console_pause;
			break;
			case 9 : console_cls;
				BST_fread(&root);
			console_pause;
			break;
			case 10 : console_cls;
				doing = 0;
			console_pause;
			break;
			default: console_cls;
		}
		
	}

}