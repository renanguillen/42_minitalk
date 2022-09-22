/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:32:26 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 17:16:55 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// # include <stdarg.h>
// # include <stdbool.h>
# include <signal.h>
# include "../libft/includes/libft.h"

typedef struct s_char
{
	int		bits_shifted;
	char	assembled;
}	t_char;

#endif