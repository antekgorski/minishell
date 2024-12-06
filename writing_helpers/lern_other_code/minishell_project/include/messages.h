/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:21:05 by sehosaf           #+#    #+#             */
/*   Updated: 2024/08/01 18:36:35 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define PROMPT "\033[0;36mminishell\033[0m \033[0;32m> \033[0m"

//		** Error messages **
# define ERR_GENERIC "\033[0;31mError: \033[0m"
# define ERR_MALLOC "minishell: malloc failed"
# define ERR_PERM "Permission denied"

//		** Syntax error messages **
# define ERR_SNX_TOKEN "minishell: syntax error near unexpected token `"
# define ERR_SNX_EOF "minishell: syntax error: unexpected end of file "

//		** Built-in commands messages **
# define ERR_NO_HOME "minishell: cd: HOME not set "
# define ERR_NO_CD "minishell: cd: can't cd to "
# define ERR_RET_CWD "minishell: cd: error retrieving current directory "
# define ERR_MANY_ARGS "minishell: exit: too many arguments "
# define ERR_PWD "minishell: pwd: error "

//		** Execution messages **
# define ERR_IS_DIR "minishell: is a directory: "
# define ERR_FORK "minishell: fork failed "
# define ERR_EXEC "minishell: execve failed "
# define ERR_ENV "minishell: environment list is empty "
# define ERR_INPUT_FILE "minishell: input file error: "
# define ERR_OUTPUT_FILE "minishell: output file error: "
# define ERR_PIPE "minishell: pipe error: "

//		** Signals messages **
# define ERR_SIGINT "minishell: sigaction: SIGINT "
# define ERR_SIGQUIT "minishell: sigaction: SIGQUIT "
# define ERR_KILL "minishell: kill"

#endif
