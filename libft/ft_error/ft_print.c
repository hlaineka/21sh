/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:23:03 by hlaineka          #+#    #+#             */
/*   Updated: 2021/04/01 15:40:57 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

static int	selector(t_tags *command, va_list *source)
{
	char	specifier;

	specifier = command->specifier;
	if (specifier == 's')
		return (print_s(command, source));
	if (specifier == 'c' || specifier == '%')
		return (print_c(command, source));
	if (specifier == 'p')
		return (print_p(command, source));
	if (specifier == 'x' || specifier == 'X')
		return (print_x(command, source));
	if (specifier == 'd' || specifier == 'i')
		return (print_d(command, source));
	if (specifier == 'u')
		return (print_u(command, source));
	if (specifier == 'o')
		return (print_o(command, source));
	if (specifier == 'f')
		return (print_f(command, source));
	return (0);
}

static void	initialize_command(t_tags *command)
{
	command->specifier = '\0';
	command->positive_value = FALSE;
	command->flag_zero = FALSE;
	command->flag_minus = FALSE;
	command->flag_plus = FALSE;
	command->flag_space = FALSE;
	command->flag_hash = FALSE;
	command->flag_fd = 1;
	command->width = -1;
	command->width_address = FALSE;
	command->precision = -1;
	command->precision_address = FALSE;
	command->length = -1;
	command->length_hh = FALSE;
	command->length_h = FALSE;
	command->length_l = FALSE;
	command->length_ll = FALSE;
	command->length_lll = FALSE;
	command->empty = FALSE;
}

static int	check_command(const char *format, t_tags *command, va_list *source)
{
	int		w;

	w = 0;
	while (format[++w] != '\0' && !is_specifier(format[w]))
	{
		if ((command->precision == -1 && command->width == -1
				&& !command->flag_zero && format[w] == '0') || format[w] == 'r')
			set_flag(command, format[w]);
		if (ft_isdigit(format[w]) || format[w] == '*')
		{
			if (command->precision == -1)
				set_width(command, format[w], source);
			else
				set_precision(command, format[w], source);
		}
		else if (format[w] == '.')
			set_precision(command, format[w], source);
		else if (format[w] == 'h' || format[w] == 'l' || format[w] == 'L')
			set_length(command, format[w]);
	}
	if (format[w] == '\0' || !is_specifier(format[w]))
		command->empty = TRUE;
	else
		command->specifier = format[w];
	return (w);
}

int	ft_printer(const char *format, va_list *source)
{
	int		printed;
	t_tags	*command;
	int		i;

	command = malloc(sizeof(t_tags));
	printed = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		initialize_command(command);
		if (format[i] == '%')
		{
			i = i + check_command(&format[i], command, source) + 1;
			if (command->empty)
				return (-1);
			printed = printed + selector(command, source);
		}
		else
		{
			ft_putchar_fd(format[i], command->flag_fd);
			printed = printed + 1;
		}
	}
	free(command);
	return (printed);
}
