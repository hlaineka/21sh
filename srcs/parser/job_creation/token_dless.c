/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dless.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:45:44 by hlaineka          #+#    #+#             */
/*   Updated: 2021/04/21 16:52:38 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "input.h"
#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

/*
**
*/

char	*ft_strjoin_all(char *str1, char *str2, int mode)
{
	char	*returnable;
	int		i;
	int		w;

	returnable = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	w = 0;
	while (str1 && str1[i])
		returnable[w++] = str1[i++];
	i = 0;
	while (str2 && str2[i])
		returnable[w++] = str2[i++];
	returnable[w] = '\0';
	if (mode == 1 || mode == 3)
		ft_free(str1);
	if (mode == 2 || mode == 3)
		ft_free(str2);
	return (returnable); 
}

t_job	*token_dless(t_job *job, t_term *term, t_node *current)
{
	char	*delimiter;
	int		fd;
//	char	*input;
//	t_input	tinput;
	char	*output;
	t_job	*returnable;

//	ft_bzero(&tinput, sizeof(t_input));
	output = NULL;
	fd = get_fd(current, 1);
	returnable = get_left_job(job, current, term);
	delimiter = get_filename(current);
	delimiter = ft_strjoin_frees1(delimiter, "\n"); //uncomment
	output = get_input_heredoc(delimiter, term->here_input, term);
//	ft_printf("> "); //substitute this
//	get_next_line(0, &input); //substitute this
//	while (!ft_strequ(delimiter, input))
//	{
//		output = ft_strjoin_all(output, input, fd);
//		ft_printf("> "); //substitute this
//		get_next_line(0, &input); //substitute this
//	}
	if (returnable)
		write(returnable->first_process->fd_stdin, output, ft_strlen(output));
	else
		write(STDOUT_FILENO, output, ft_strlen(output));
	ft_memdel((void**)&output);
//	ft_printf("DONG1");
//	while(1);
	return (returnable);
}
