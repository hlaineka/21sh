/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:07:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/05/12 10:38:17 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	handle_process(t_process *proc, int status)
{
	proc->status = status;
	if (WIFEXITED(status))
	{
		proc->completed = 1;
		proc->status = WEXITSTATUS(status);
	}
	else if (WIFSTOPPED(status))
	{
		proc->stopped = 1;
		proc->status = WIFSTOPPED(status);
	}
	else if (WIFSIGNALED(status))
	{
		proc->completed = 1;
		proc->status = WTERMSIG(status);
	}
}

void	sig_child_handler(void)
{
	pid_t		pid;
	int			status;
	t_job		*jobs;
	t_process	*proc;

	pid = waitpid(-1, &status, WNOHANG);
	jobs = g_term->jobs;
	while (jobs)
	{
		proc = jobs->first_process;
		while (proc)
		{
			if (pid == proc->pid)
			{
				handle_process(proc, status);
				kill_processes_before_pid(jobs, pid);
				return ;
			}
			proc = proc->next;
		}
		jobs = jobs->next;
	}
}

void	sig_tstp_handler(void)
{
	t_job		*jobs;
	t_process	*proc;

	jobs = g_term->jobs;
	while (jobs)
	{
		proc = jobs->first_process;
		while (proc)
		{
			kill(proc->pid, SIGTSTP);
			proc->stopped = 1;
			proc = proc->next;
		}
	}
}

void	sig_handler_exec(int signo)
{
	t_job		*jobs;
	t_process	*proc;

	if (signo == SIGCHLD)
		sig_child_handler();
	if (signo == SIGINT)
	{
		jobs = g_term->jobs;
		while (jobs)
		{
			proc = jobs->first_process;
			while (proc)
			{
				kill(proc->pid, SIGINT);
				proc = proc->next;
			}
			jobs = jobs->next;
		}
		ft_putchar('\n');
	}
}

void	set_signal_execution(void)
{
	if ((signal(SIGINT, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGCONT, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGINT, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGTSTP, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGTERM, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGQUIT, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGHUP, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGPIPE, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGALRM, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGXCPU, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGXFSZ, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGABRT, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGVTALRM, sig_handler_exec) == SIG_ERR)
		|| (signal(SIGPROF, sig_handler_exec) == SIG_ERR))
		ft_exit(0);
}
