#include "Sfile.h"

#define console_cls   system("cls");   printf("\n");
#define console_pause system("PAUSE");

void proc_Menu(int* choice)
{
	console_cls;

	printf("\n\t\t\t############### MENU ###############\n");
	printf("\t\t\t\t1.Create file\n");
	printf("\t\t\t\t2.Emfiler\n");
	printf("\t\t\t\t3.Defiler\n");
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

	int true = 1, choice;

	file_t* my_file = NULL;

	while(true)
	{
		proc_Menu(&choice);
		switch(choice)
		{
			case 1 : console_cls; 
				printf("\nCreate file...\n");
				my_file = get_file(my_file); 
				console_pause; break;
			case 2 : console_cls; 
				printf("\nEmfiler...\n");
				int stop = 1;
				while(stop)
				{
					my_file = (file_t*)f_emflier(my_file);
					printf("\nPress 1 for continue && 0 for ending : "); scanf("%d", &stop);
				}
				console_pause; break;
			case 3 : console_cls;
				printf("\nDefiler...\n");
				my_file = f_defiler(my_file);
				console_pause; break;
			case 4 : console_cls;
				printf("\nIs it empty?...\n");
				if(f_itIs_empty(my_file)) printf("\nfile VIDE\n");
				else printf("\nfile NON VIDE\n");
				console_pause; break;
			case 5 : console_cls;
				printf("\nEMPTY...\n");
				my_file = f_empty(my_file);
				console_pause; break;
			case 6 : console_cls; free(my_file); true = 0; break;
			default: break;
		}
	}
	free(my_file);
}