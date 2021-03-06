/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:22:38 by hlaineka          #+#    #+#             */
/*   Updated: 2021/04/06 11:14:15 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_float_to_str(long double n, long long int number)
{
	int		i;
	char	*returnable;

	if (n < 0)
	{
		n = n * -1;
		number = number * -1;
	}
	i = 1;
	returnable = malloc(sizeof(char) * 20);
	if (returnable)
	{
		returnable[0] = '.';
		n = n - number;
		while (i < 20)
		{
			n = n * 10;
			number = n;
			returnable[i] = (number % 10) + '0';
			i++;
		}
		return (returnable);
	}
	return (NULL);
}

char	*ft_itoa_float(long double n)
{
	char			*str1;
	char			*str2;
	char			*returnable;
	long long int	number;

	number = n;
	str1 = ft_itoa_base(number, 10);
	if (str1[0] == '0' && n < 0)
		str1 = ft_strjoin_frees2("-", str1);
	str2 = ft_float_to_str(n, number);
	returnable = ft_strjoin_frees2(str1, str2);
	free(str1);
	return (returnable);
}
