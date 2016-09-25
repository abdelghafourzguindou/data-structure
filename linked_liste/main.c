#include "Sliste.h"

#include <signal.h>

#define console_cls   system("cls");   printf("\n");
#define console_pause printf("\n\n");  system("PAUSE");

void proc_Menu(int* choice)
{
	console_cls;

	printf("\n\t\t\t############### MENU ###############\n");
	printf("\t\t\t\t1.Scan\n");
	printf("\t\t\t\t2.Print\n");
	printf("\t\t\t\t3.Serch\n");
	printf("\t\t\t\t4.Update\n");
	printf("\t\t\t\t5.Remove\n");
	printf("\t\t\t\t6.Empty\n");
	printf("\t\t\t\t7.End\n");
	printf("\t\t\t####################################\n");
	printf("\t\t\tYour choise pls : ");
	int c; 
	scanf("%d", &c);
	*choice = c;
}


main()
{
	node_t* p_Head = NULL;
	node_t* my_node= NULL;

	int true = 1, choice, this_value; ;

	while(true)
	{
		proc_Menu(&choice);
		switch(choice)
		{
			case 1 : console_cls; 
				printf("\nScanning...\n");
				int stop = 1;
				while(stop)
				{
					p_Head = add_node(p_Head); 

					printf("\nPress 1 for continue && 0 for ending : "); scanf("%d", &stop);
				}
				console_pause; break;
			case 2 : console_cls; 
				printf("\nPRINTING...\n");
				printf("\n\tNODE\t\tNEXTNODE\tVALUE\n\t-------------------------------------");
				print_liste(p_Head);
				console_pause; break;
			case 3 : console_cls;
				printf("\nSERCHING...\n");
				printf("\nScan the value pls : "); scanf("%d", & this_value);
				my_node = serch_node(p_Head, this_value);
				print_node(my_node);
				console_pause; break;
			case 4 : console_cls;
				printf("\nUPDATING...\n");
				int update_value;
				printf("\nScan the old && new value pls : "); scanf("%d%d", &this_value, &update_value);
				p_Head = update_node(p_Head, this_value, update_value);
				console_pause; break;
			case 5 : console_cls;
				printf("\nROMOVING...\n");
				printf("\nScan the value pls : "); scanf("%d", &this_value);
				p_Head = remove_node(p_Head, this_value);
				console_pause; break;
			case 6 : console_cls;
				printf("\nEMPTY...\n");
				p_Head = empty_liste(p_Head);
				console_pause; break;
			case 7 : console_cls; free(p_Head); free(my_node); true = 0; break;
			default: break;
		}
	}
	free(my_node);
	free(p_Head);
}