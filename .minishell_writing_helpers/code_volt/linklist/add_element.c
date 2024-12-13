#include <stdio.h>
#include <stdlib.h>

//#define _CRTDBG_MAP_ALLOC like vallgrind for windows

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

void    insert_after(t_node *current_node, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if(new_node == NULL)
        exit(1);
    new_node->data = value;
    new_node->next = current_node->next;
    current_node->next = new_node;

}

void	add_element_to_begin(t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->data = value;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}

void	add_element_to_end(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->data = value;
	current = *head;
	if (current == NULL)
	{
		*head = new_node;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	dealocate(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}

int	main(void)
{
	//t_node *node1 = NULL;
	t_node *node1 = malloc(sizeof(t_node));
	if(node1 == NULL)
	    exit(1);
	node1->data = 1;
	node1->next = NULL;

	// node1.next = malloc(sizeof(t_node));
	// node1.next->data = 2;
	// node1.next->next = NULL;

	add_element_to_end(&node1, 2);
	add_element_to_end(&node1, 3);
	add_element_to_end(&node1, 4);
	add_element_to_end(&node1, 5);

    add_element_to_begin(&node1, 0);
    add_element_to_begin(&node1, -1);
    add_element_to_begin(&node1, -2);

    insert_after(node1->next, 100);

	t_node *current;
	current = node1;

	while (current != NULL)
	{
		printf("node data: %d\n", current->data);
		current = current->next;
	}

	dealocate(&node1);
	//_CrtDumpMemoryLeaks(); like valgrind for windows
	// free(node1.next);
	return (0);
}