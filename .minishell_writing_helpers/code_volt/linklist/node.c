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
	// t_node node2;
	node1.data = 1;
	//node1.next = &node2;
	node1.next = malloc(sizeof(t_node));
	//  node2.data = 2;
	//  node2.next = NULL;
    node1.next->data = 2;
    node1.next->next = NULL;
	printf("first node data: %d\n", node1.data);
	// printf("second node data: %d\n", node2.data);
	// printf("second node data: %d\n", node1.next->data);
	printf("second node data: %d\n", (*node1.next).data);
    free(node1.next);
	return (0);
}