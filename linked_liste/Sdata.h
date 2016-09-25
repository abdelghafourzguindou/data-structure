#include <stdio.h>
#include <stdlib.h>

typedef struct _data 
{
	int value;
} data_t;

data_t* get_dta();
void print_data(data_t*);