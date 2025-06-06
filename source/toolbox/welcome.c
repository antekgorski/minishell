/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/27 10:39:03 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	welcome(void)
{
	printf("\n\n");
	printf("\e[36m\tProbably the best 42minishell in Warsaw\n");
	printf("\n\n");
	printf(" █████╗ ███╗   ██╗████████╗██████╗  █████╗ ██╗    ██╗\n");
	printf("██╔══██╗████╗  ██║╚══██╔══╝██╔══██╗██╔══██╗██║    ██║\n");
	printf("███████║██╔██╗ ██║   ██║   ██████╔╝███████║██║ █╗ ██║\n");
	printf("██╔══██║██║╚██╗██║   ██║   ██╔═══╝ ██╔══██║██║███╗██║\n");
	printf("██║  ██║██║ ╚████║   ██║   ██║     ██║  ██║╚███╔███╔╝\n");
	printf("╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     ╚═╝  ╚═╝ ╚══╝╚══╝\n");
	printf("\t  Be careful, MINI(S)HELL\n");
	printf("  take your's commands and push into the galaxy!\n\e[0m");
	printf("\n\n");
}
