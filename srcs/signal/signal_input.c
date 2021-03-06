/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:34:59 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/05/02 12:25:50 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	sig_handler_input(int signo)
{
	t_input	*input;
	t_term	*term;
	int		col;
	int		row;

	(void)signo;
	col = g_input->prompt_col - 1;
	row = g_input->prompt_row - 1;
	term = g_term;
	input = g_input;
	tputs(tgoto(term->cm_string, col, row), 1, ft_putc);
	ft_putstr_input(input->ls, input, term);
	ft_putrstr_input(input->rrs, input, term);
	input->ls[0] = '\0';
	input->rrs[0] = '\0';
	*input->quote = PROMPT_NORMAL;
	ft_putstr_fd("\n\r", STDOUT_FILENO);
	ft_memdel((void **)input->ret_str);
	*input->input_temp = NULL;
	if (input->heredoc)
		init_input_tty(input, PROMPT_HEREDOC);
	else
		init_input_tty(input, PROMPT_START);
}

void	set_signal_input(void)
{
	if ((signal(SIGINT, sig_handler_input) == SIG_ERR)
		|| (signal(SIGCONT, sig_handler_input) == SIG_ERR)
		|| (signal(SIGINT, sig_handler_input) == SIG_ERR)
		|| (signal(SIGTSTP, sig_handler_input) == SIG_ERR)
		|| (signal(SIGTERM, sig_handler_input) == SIG_ERR)
		|| (signal(SIGQUIT, sig_handler_input) == SIG_ERR)
		|| (signal(SIGHUP, sig_handler_input) == SIG_ERR)
		|| (signal(SIGPIPE, sig_handler_input) == SIG_ERR)
		|| (signal(SIGALRM, sig_handler_input) == SIG_ERR)
		|| (signal(SIGXCPU, sig_handler_input) == SIG_ERR)
		|| (signal(SIGXFSZ, sig_handler_input) == SIG_ERR)
		|| (signal(SIGABRT, sig_handler_input) == SIG_ERR)
		|| (signal(SIGVTALRM, sig_handler_input) == SIG_ERR)
		|| (signal(SIGPROF, sig_handler_input) == SIG_ERR))
		ft_exit(0);
}
