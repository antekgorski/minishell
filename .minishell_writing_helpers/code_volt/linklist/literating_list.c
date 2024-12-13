//      arrays      |   linked_list
//      int i = 0;  |   t_node *current = head;
//      i < n;      |   current != NULL;
//      i++;        |   current = current->next;

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

int	main(void)
{
	t_node node1;
	node1.data = 1;
	node1.next = malloc(sizeof(t_node));
    node1.next->data = 2;
    node1.next->next = NULL;

    t_node *current = &node1;

    while(current != NULL)
    {
        printf("node data: %d\n", current->data);
        current = current->next;
    }

    free(node1.next);
	return (0);
}