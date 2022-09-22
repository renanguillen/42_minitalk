/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:55 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 19:56:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_char global;

void char_display(int signal)
{
	if (signal == SIGUSR1)
		global.assembled += (0b00000001 << global.bits_shifted);
	if (global.bits_shifted == 7)
	{
		ft_putchar_fd(global.assembled, STDOUT_FILENO);
		ft_bzero(&global, 2);
		return ;
	}
	global.bits_shifted++;
}

int	main(void)
{
	ft_bzero(&global, 2);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	signal(SIGUSR1, char_display);
	signal(SIGUSR2, char_display);
	while (true)
		pause();
}