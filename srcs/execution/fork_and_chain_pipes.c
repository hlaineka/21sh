/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_chain_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:39:02 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/04/23 10:58:36 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	set_read(int *lpipe)
{
	dup2(lpipe[0], STDIN_FILENO);
	close(lpipe[0]);
	close(lpipe[1]);
}

static void	set_write(int *rpipe)
{
	dup2(rpipe[1], STDOUT_FILENO);
	close(rpipe[0]);
	close(rpipe[1]);
}

/*
** FORK_AND_CHAIN_PIPES:
** - in the first element in the pipeline, let the lpipe be NULL
**      f.ex. process->pid = fork_and_chain_pipes(NULL, rpipe);
** - in the elements in the middle use both lpipe and rpipe
**      f.ex. process->pid = fork_and_chain_pipes(lpipe, rpipe);
** - in the last element, let the rpipe be NULL
**      f.ex. process->pid = fork_and_chain_pipes(lpipe, NULL);
** --> with the return value you know whether it is a parent of child
**     process.
**    RETURN VALUE: SUCCESS && in CHILD   pid == 0;
**                  SUCCESS && in PARENT  pid > 0;
**                  FAIL && in PARENT     pid < 0;
*/

pid_t	fork_and_chain_pipes(int *lpipe, int *rpipe)
{
	pid_t	pid;

	pid = fork();
	if (pid)
		return (pid);
	if (lpipe)
		set_read(lpipe);
	if (rpipe)
		set_write(rpipe);
}
