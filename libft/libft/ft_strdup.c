/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:34:18 by hlaineka          #+#    #+#             */
/*   Updated: 2021/03/24 16:37:59 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** creates a new string and copies the content of s to it.Returns the new str
*/

char	*ft_strdup(const char *s)
{
	int		i;
	char	*returnable;
	int		length;

	length = ft_strlen(s);
	returnable = NULL;
	returnable = (char *)malloc(sizeof(char) * (length + 1));
	if (!returnable)
		return (NULL);
	i = 0;
	while (s && s[i] != '\0')
	{
		returnable[i] = s[i];
		i++;
	}
	returnable[i] = '\0';
	return (returnable);
}
