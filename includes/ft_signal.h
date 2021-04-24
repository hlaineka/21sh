/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:12:09 by helvi             #+#    #+#             */
/*   Updated: 2021/04/23 14:42:24 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>
# include "includes.h"

void	start_signal(void);
void	sig_handler_input(int signo);
void	sig_handler_exec(int signo);
void	signals_to_default(void);

#endif
