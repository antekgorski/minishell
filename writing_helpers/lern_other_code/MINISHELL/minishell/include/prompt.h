/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:01:57 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/24 17:57:58 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

/* ------------  SHELL PROMPT AND INTRO MESSAGE DEFINED  -------------------- */

/**
 * @brief Defines the prompt for the minishell.
 *
 * This string is printed to the console to indicate that minishell is ready 
 * to accept a command.
 */
# define PROMPT "\e[1;4;36mminishell$\033[0m "

/**
 * @brief Defines the introductory message for the minishell.
 */
# define INTRO_MSG	"\e[1;36m\n\
           _       _     _         			 \n\
 _ __ ___ (_)_ __ (_)___| |__   ___| | || |  \n\
| '_ ` _ \\| | '_ \\| / __| '_ \\ / _ \\ | / __) \n\
| | | | | | | | | | \\__ \\ | | |  __/ | \\__ \\ \n\
|_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_(   / \n\
                                        |_|  \n\
\n"

#endif