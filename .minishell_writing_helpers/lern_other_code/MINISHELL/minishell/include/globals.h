/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:59:05 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/24 17:56:19 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

/* ------------  GLOBAL VARIABLE DECLARED  ---------------------------------- */

/**
 * @brief Global variable to hold the exit status of commands.
 *
 * This variable is used throughout the program to keep track of the exit status
 * of the last command that was executed. It is especially useful for 
 * implementing the $? shell variable, which in a real shell would print the 
 * exit status of the most recently executed foreground pipeline.
 */
extern long long	g_exit_status;

#endif