#include "../headers/minishell.h"

void add_next_node()
{
    //adder next node
}

add_prev_node(t_list)
{
    //add prev node
}

create_node(t_token token, char *command)
{
    t_node	*new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return (NULL);
    new_node->token = token;
    new_node->command = command;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}