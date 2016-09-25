#include "Sliste.h"

node_t* get_node()
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t));

	new_node->p_data = (data_t*)get_data();
	new_node->p_next = NULL;

	return new_node;
}

node_t* add_node(node_t* head)
{
	node_t* new_node = get_node();

	printf("\nSet up 1 : Head = %p && new_Node = %p\n", head, new_node);

	if(head != NULL)
	{
		new_node->p_next = head;
		head 			 = new_node;
	}
	else head = new_node;

	printf("\nSet up 2 : Head = %p && nextNode = %p\tvalue%3d\n\n", head, new_node->p_next, new_node->p_data->value);

	return head;
}

void print_node(node_t* this_node)
{
	printf("\n\t%p\t%p\t", this_node, this_node->p_next); 
	print_data(this_node->p_data);
	printf("\n");
}

void print_liste(node_t* head)
{
	if(head != NULL)
	{
		node_t* corsor = head;

		while(corsor != NULL)
		{
			print_node(corsor);
			corsor = corsor->p_next;
		}
	}
	else printf("\nError : This Linked liste is empty\n");
}

node_t* serch_node(node_t* head, int this_value)
{
	if(head != NULL)
	{
		node_t* corsor = head;

		while(corsor != NULL)
		{
			if(corsor->p_data->value == this_value) return corsor;
			corsor = corsor->p_next;
		}
	}
	else
	{
		printf("\nThis node not exist\n");
		return NULL;
	}
}

node_t* update_node(node_t* head, int this_value, int update_value)
{
	node_t* isIt_exist = serch_node(head, this_value);

	if(isIt_exist != NULL) isIt_exist->p_data->value = update_value;

	return head;
}

node_t* remove_node(node_t* head, int this_value)
{
	if(serch_node(head, this_value))
	{
	node_t* pred   = NULL;

	if(head->p_data->value == this_value)
	{
		pred = head;
		head = head->p_next;
		free(pred->p_data);
		free(pred);
		return head;
	}

	node_t* corsor = head;

	while(corsor != NULL)
	{
		pred   = corsor;
		corsor = corsor->p_next;

		if(corsor->p_data->value == this_value)
		{
			pred->p_next = corsor->p_next;
			free(corsor->p_data);
			free(corsor);
			return head;
		}
	}
	}
}

node_t* empty_liste(node_t* head)
{
	node_t* corsor = head;
	node_t* prec   = NULL;

	while(corsor != NULL)
	{
		prec   = corsor;
		corsor = corsor->p_next;
		free(prec->p_data);
		free(prec);
	}
	head = NULL;
	return head;
}