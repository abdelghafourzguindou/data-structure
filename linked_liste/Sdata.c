#include "Sdata.h"

data_t* get_data()
{
	data_t* newData = (data_t*)malloc(sizeof(data_t));
	printf("\nValue pls : ");
	scanf("%d", &newData->value);

	return newData;
}

void print_data(data_t* data)
{
	printf("%3d", data->value);
}