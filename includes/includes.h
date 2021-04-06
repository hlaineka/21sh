/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:00:19 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/04/06 11:21:14 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <curses.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

# include "libft.h"
# include "structs_21.h"
# include "input.h"
# include "parser.h"
# include "ft_signal.h"

# define STR_LENGTH 1024

/*
** smallest allowed argv size in posix 4096 total
*/

# define ARGV_SIZE 4096

#endif
