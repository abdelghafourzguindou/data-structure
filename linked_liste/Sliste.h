#include "Sdata.h"

typedef struct _node
{
	data_t 		 *p_data;
	struct _node *p_next;
} node_t;

node_t* get_node();
node_t* add_node(node_t*);
node_t* remove_node(node_t*, int);
node_t* update_node(node_t*, int, int);
node_t* serch_node(node_t*, int);
node_t* empty_liste(node_t*);

void print_node(node_t*);
void print_liste(node_t*);