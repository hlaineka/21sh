/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_user.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:34:41 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/04/16 11:53:51 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input.h"

static void	print_input(char *str, t_input *input, t_term *term)
{
	int		col;
	int		row;

	col = input->prompt_col - 1;
	row = input->prompt_row - 1;
	tputs(tgoto(term->cm_string, col, row), 1, ft_putc);
	ft_putstr_input(str, input, term);
}

void	init_input_tty(t_input *input, int prompt_mode)
{
	ft_bzero(input->ls, input->ls_size);
	ft_bzero(input->rrs, input->rrs_size);
	get_pos(&input->start_row, &input->start_col);
	input->prompt_length = print_prompt(prompt_mode);
	get_pos(&input->prompt_row, &input->prompt_col);
	input->cursor_row = input->prompt_row;
	input->cursor_col = input->prompt_col;
	input->hist_cur = input->last_comm;
}

char	*read_input_tty(int prompt_mode, t_input *input, t_term *term)
{
	char	read_chars[1024];
	char	*str;
	int		len;

	init_input_tty(input, prompt_mode);
	while (1)
	{
		ft_bzero(read_chars, 1024);
		if (read(STDIN_FILENO, read_chars, 1024) == -1)
			err_fatal(ERR_READ, NULL, term);
		if (shell_keypress(read_chars, input, term))
		{
			len = ft_strlen(input->ls) + ft_strlen(input->rrs) + 2;
			str = ft_memalloc(sizeof(char) * len);
			if (!str)
				err_fatal(ERR_MALLOC, NULL, term);
			end_keypress(input, term);
			ft_strcat(str, input->ls);
			ft_strncat(str, "\n", 1);
			print_input(str, input, term);
			break ;
		}
	}
	return (str);
}

static char	*get_input_tty(char *str, t_term *term, t_input *input)
{
	int		quote;
	int		len;
	char	*temp;
	char	*temp2;

	input->input_temp = &temp;
	quote = PROMPT_START;
	while (quote)
	{
		if (quote == PROMPT_START)
			quote = PROMPT_NORMAL;
		temp = read_input_tty(quote, input, term);
		len = ft_strlen(str);
		if (!str)
			temp2 = ft_strdup(temp);
		else
			temp2 = ft_strjoin(str, temp);
		free(str);
		free(temp);
		str = temp2;
		temp = str + len;
		quote = ft_is_quote_open(quote, temp);
	}
	return (str);
}

char	*get_input(int argc, char **argv, t_term *term, t_input *input)
{
	char	*str;

	str = NULL;
	input->ret_str = &str;
// do signal fail check
	signal(SIGINT, SIG_DFL);
	signal(SIGINT, sig_handler_input);

	signal(SIGCONT, sig_handler_input);
	signal(SIGINT, sig_handler_input);
	signal(SIGTSTP, sig_handler_input);
	signal(SIGTERM, sig_handler_input);
	signal(SIGQUIT, sig_handler_input);
	signal(SIGHUP, sig_handler_input);
	signal(SIGPIPE, sig_handler_input);
	signal(SIGALRM, sig_handler_input);
	signal(SIGXCPU, sig_handler_input);
	signal(SIGXFSZ, sig_handler_input);
	signal(SIGABRT, sig_handler_input);
	signal(SIGVTALRM, sig_handler_input);
	signal(SIGPROF, sig_handler_input);


	if (argc == 1)
	{
		enable_raw_mode(term);
		str = get_input_tty(str, term, input);
		input->history = command_to_history(input, str);
		if (!input->history)
			err_fatal(ERR_MALLOC, NULL, term);
		disable_raw_mode_continue(term);
	}



	signal(SIGINT, SIG_DFL);
	(void)argv;
	return (str);
}
