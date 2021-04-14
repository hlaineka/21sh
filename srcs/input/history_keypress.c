/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:52:51 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/04/11 12:06:07 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	history_up(t_input *input, t_term *term)
{
	char	*str;
	int		x;
	int		y;

	if (input->hist_cur->next == NULL)
		return ;
	input->hist_cur = input->hist_cur->next;
	str = input->hist_cur->content;
	if (!str)
		return ;
	x = input->prompt_col - 1;
	y = input->prompt_row - 1;
	if (ft_strlen(input->ls) + ft_strlen(input->rrs) + input->prompt_length > term->nrows)
		clear_rows_starting_y(y + 1, term);
	tputs(tgoto(term->cm_string, x, y), 1, ft_putc);
	tputs(term->ce_string, 1, ft_putc);
	ft_bzero(input->ls, input->ls_size);
	ft_bzero(input->rrs, input->rrs_size);
	ft_strcat(input->ls, str);
	ft_putstr_input(input->ls, input, term);
	get_pos(&input->cursor_row, &input->cursor_col);
}

void	history_down(t_input *input, t_term *term)
{
	char	*str;
	int		x;
	int		y;

	if (input->hist_cur->prev == NULL)
		return ;
	input->hist_cur = input->hist_cur->prev;
	str = input->hist_cur->content;
	if (!str)
		return ;
	x = input->prompt_col - 1;
	y = input->prompt_row - 1;
	if (ft_strlen(input->ls) + ft_strlen(input->rrs) + input->prompt_length > term->nrows)
		clear_rows_starting_y(y + 1, term);
	tputs(tgoto(term->cm_string, x, y), 1, ft_putc);
	tputs(term->ce_string, 1, ft_putc);
	ft_bzero(input->ls, input->ls_size);
	ft_bzero(input->rrs, input->rrs_size);
	ft_strcat(input->ls, str);
	ft_putstr_input(input->ls, input, term);
	get_pos(&input->cursor_row, &input->cursor_col);
}

t_clist	*command_to_history(t_input *input, char *str)
{
	t_clist	*new;
	char	*ptr;

	new = ft_clstnew(str, ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	ptr = ft_strrchr(new->content, '\n');
	*ptr = '\0';
	new->prev = input->last_comm;
	new->next = input->history;
	input->history->prev = new;
	input->last_comm->next = new;
	return (new);
}
