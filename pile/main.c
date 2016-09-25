#include "Spile.h"

#include <signal.h>

#define console_cls   system("cls");   printf("\n");
#define console_pause system("PAUSE");

void proc_Menu(int* choice)
{
	console_cls;

	printf("\n\t\t\t############### MENU ###############\n");
	printf("\t\t\t\t1.Create pile\n");
	printf("\t\t\t\t2.Empiler\n");
	printf("\t\t\t\t3.Depiler\n");
	printf("\t\t\t\t4.Is it empty?\n");
	printf("\t\t\t\t5.Empty\n");
	printf("\t\t\t\t7.End\n");
	printf("\t\t\t####################################\n");
	printf("\t\t\tYour choise pls : ");
	int c; 
	scanf("%d", &c);
	*choice = c;
}


main()
{

	int true = 1, choice, this_value;

	pile_t* my_Stack = NULL;

	while(true)
	{
		proc_Menu(&choice);
		switch(choice)
		{
			case 1 : console_cls; 
				printf("\nCreate pile...\n");
				my_Stack = get_pile(my_Stack); 
				console_pause; break;
			case 2 : console_cls; 
				printf("\nEmpiler...\n");
				int stop = 1;
				while(stop)
				{
					my_Stack = p_emplier(my_Stack);
					printf("\nPress 1 for continue && 0 for ending : "); scanf("%d", &stop);
				}
				console_pause; break;
			case 3 : console_cls;
				printf("\nDepiler...\n");
				my_Stack = p_depiler(my_Stack);
				console_pause; break;
			case 4 : console_cls;
				printf("\nIs it empty?...\n");
				if(p_itIs_empty(my_Stack)) printf("\nPILE VIDE\n");
				else printf("\nPILE NON VIDE\n");
				console_pause; break;
			case 5 : console_cls;
				printf("\nEMPTY...\n");
				my_Stack = p_empty(my_Stack);
				console_pause; break;
			case 6 : console_cls; free(my_Stack); true = 0; break;
			default: break;
		}
	}
	free(my_Stack);
}