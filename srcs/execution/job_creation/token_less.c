/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:52:24 by hlaineka          #+#    #+#             */
/*   Updated: 2021/05/04 10:38:16 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "execution.h"
#include <sys/stat.h>
#include <fcntl.h>

static int	open_fd(char *filename, int old_fd)
{
	int	returnable;
	int	closed_fd;

	returnable = 0;
	closed_fd = check_fd(old_fd, 0);
	if (-1 != closed_fd || old_fd < 3)
	{
		if (-1 != closed_fd)
			returnable = close_fd(old_fd);
		if (returnable >= 0)
			returnable = open(filename, O_RDONLY);
	}
	return (returnable);
}

/*
** open(filename, O_RDWR | O_CREAT | O_TRUNC):
** opens the file with read and write permission, creates the file if it
** does not exists and overwrites the data on the file AND truncates all
** excess residual data left from overwrite.
*/

t_job	*token_less(t_job *job, t_term *term, t_node *current)
{
	int		old_fd;
	char	*filename;
	t_job	*returnable;

	old_fd = get_fd(current, 0);
	filename = get_filename(current);
	if (!filename)
		return (NULL);
	open_fd(filename, old_fd);
	returnable = get_left_job(job, current, term);
	if (!returnable)
		return (NULL);
	return (returnable);
}
