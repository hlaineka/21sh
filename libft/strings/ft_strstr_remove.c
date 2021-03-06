/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:04:57 by hlaineka          #+#    #+#             */
/*   Updated: 2021/04/01 12:59:21 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Removes str2 from str1 if it is found on str1. If not, returns str1.
*/

char	*ft_strstr_remove(char *str1, char *str2)
{
	int		end;
	int		start;
	int		i;
	int		w;
	char	*returnable;

	start = ft_strstri(str1, str2);
	end = start + ft_strlen(str2);
	returnable = malloc(sizeof(char) * (ft_strlen(str1) - ft_strlen(str2) + 1));
	i = 0;
	w = 0;
	while (str1[i])
	{
		if (i >= start && i < end)
			i++;
		else
		{
			returnable[w] = str1[i];
			i++;
			w++;
		}
	}
	returnable[w] = '\0';
	return (returnable);
}
