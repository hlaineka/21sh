/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:24:36 by hlaineka          #+#    #+#             */
/*   Updated: 2021/04/01 12:54:05 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a "fresh" substring from the string given as argument.
** The substring begins at index START and ends on index END. If START and END
** aren't refering to a valid substring, the behavior is undefined. If the
** allocation fails, the function return NULL
*/

char	*ft_strsub_mid(const char *s, unsigned int start, size_t end)
{
	char			*returnable;
	unsigned int	i;

	returnable = (char *)malloc(sizeof(char) * end - start + 1);
	i = 0;
	if (returnable)
	{
		while (i < (end - start))
		{
			returnable[i] = s[start + i];
			i++;
		}
		returnable[i] = '\0';
		return (returnable);
	}
	return (NULL);
}
