/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:19:30 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/24 13:09:50 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintlen_base(unsigned int n, unsigned int base)
{
	size_t		len;

	len = 1;
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}
