/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:12:20 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/04/11 12:07:52 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	ft_putc(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}
