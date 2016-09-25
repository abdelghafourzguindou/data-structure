#include <stdio.h>
#include <stdlib.h>

typedef struct _case
{
	int value;
	struct _case* p_Next;
}case_t;

static int i = 0;

case_t* get_case();