/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:47:54 by hlaineka          #+#    #+#             */
/*   Updated: 2021/04/01 13:09:39 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Adds a new string to the end of string array. Frees the old strarr and all
** the str in it. The string and array must be null-terminated.
*/

#include "libft.h"

char	**ft_strarr_add(char **arr, char *str)
{
	char	**returnable;
	int		i;

	i = 0;
	returnable = malloc(sizeof(char *) * (ft_array_length(arr) + 2));
	while (arr && arr[i])
	{
		returnable[i] = ft_strdup(arr[i]);
		ft_free(arr[i]);
		i++;
	}
	returnable[i] = ft_strdup(str);
	returnable[i + 1] = NULL;
	ft_free(arr);
	return (returnable);
}
