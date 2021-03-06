/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:38:45 by helvi             #+#    #+#             */
/*   Updated: 2021/04/01 15:46:34 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

/*
**int	(*g_run_at_exit)(void) = NULL;
**
**int					ft_atexit(int (*func_for_exit)(void))
**{
**	g_run_at_exit = func_for_exit;
**	return (1);
**}
*/

int	ft_exit(int return_value)
{
	exit(return_value);
	return (1);
}

void	die(const char *s)
{
	ft_putstr_fd(s, 2);
	ft_exit(1);
}
