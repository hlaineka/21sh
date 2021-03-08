/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 20:14:47 by hlaineka          #+#    #+#             */
/*   Updated: 2021/03/06 13:40:27 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> // perror needs this. do we need this one?

void	print_error(char *directory_name)
{
	ft_printf("ft_ls: %s: ", directory_name);
	perror("");
}
