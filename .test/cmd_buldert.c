#include "../../include/minishell.h"

static t_cmd    *new_cmd(void)
{
    t_cmd   *cmd;
    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    cmd->argv = NULL;
    cmd->redirs = NULL;
    cmd->is_builtin = 0;
    cmd->pipe_in = 0;
    cmd->pipe_out = 1;
    cmd->exit_code = 0;
    cmd->next = NULL;
    return (cmd);
}
static void add_redir(t_redir **redirs, t_token_type type, char *filename)
{
    t_redir *new;
    t_redir *temp;
    new = malloc(sizeof(t_redir));
    if (!new)
        return ;
    new->type = type;
    new->filename = ft_strdup(filename);
    new->next = NULL;
    if (!*redirs)
        *redirs = new;
    else
    {
        temp = *redirs;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}
static char **add_to_argv(char **argv, char *arg)
{
    int     i;
    char    **new_argv;
    i = 0;
    while (argv && argv[i])
        i++;
    new_argv = malloc(sizeof(char *) * (i + 2));
    if (!new_argv)
        return (NULL);
    i = 0;
    while (argv && argv[i])
    {
        new_argv[i] = argv[i];
        i++;
    }
    new_argv[i] = ft_strdup(arg);
    new_argv[i + 1] = NULL;
    free(argv);
    return (new_argv);
}
t_cmd   *parse_tokens(t_token *tokens)
{
    t_cmd   *cmds;
    t_cmd   *current_cmd;
    t_token_type    redir_type;
    cmds = new_cmd();
    if (!cmds)
        return (NULL);
    current_cmd = cmds;
    while (tokens)
    {
        if (tokens->type == PIPE) // Nowa komenda
        {
            current_cmd->next = new_cmd();
            current_cmd = current_cmd->next;
        }
        else if (tokens->type == REDIR_IN || tokens->type == REDIR_OUT
            || tokens->type == REDIR_APPEND || tokens->type == HEREDOC)
        {
            redir_type = tokens->type; // Zapisz typ redirekcji
            tokens = tokens->next;
            if (tokens) // Dodaj redirekcję
                add_redir(&current_cmd->redirs, redir_type, tokens->value);
        }
        else if (tokens->type == WORD) // Argument
            current_cmd->argv = add_to_argv(current_cmd->argv, tokens->value);
        tokens = tokens->next;
    }
    return (cmds);
}

void    ft_cmd_bilder(t_minishell *minishell)
{
    t_cmd   *cmds;
    t_cmd   *current_cmd;
    int     i;
    t_list  *token;
    token = minishell->token_list;
    cmds = ft_new_cmd();
    if (!cmds)
        ft_panic("malloc", 1);
    current_cmd = cmds;
    i = 0;
    while (token)
    {
        if (*(t_token *)token->content == PIPE)
        {
            current_cmd->next = ft_new_cmd();
            if (!current_cmd->next)
                ft_panic("malloc", 1);
            current_cmd = current_cmd->next;
        }
        else if (*(t_token *)token->content == IREDIR
            || *(t_token *)token->content == OREDIR
            || *(t_token *)token->content == APPEND
            || *(t_token *)token->content == HERDOC)
        {
            t_token redir_type = *(t_token *)token->content;
            token = token->next;
            i++;
            if (minishell->lexter_tab[i] && *(t_token *)token->content == CMD)
                ft_add_redir(&current_cmd->redirs, redir_type,
                    minishell->lexter_tab[i]);
            else
            {
                printf("syntax error near unexpected token\n");
                return ;
            }
        }
        else if (*(t_token *)token->content == CMD)
            current_cmd->argv = ft_add_cmd(current_cmd->argv,
                    minishell->lexter_tab[i]);
        token = token->next;
        i++;
    }
    minishell->cmd_list = cmds;
}
