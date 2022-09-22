/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:55 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 20:05:22 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_char	g_char;

void	char_display(int signal)
{
	if (signal == SIGUSR1)
		g_char.assembled += (0b00000001 << g_char.bits_shifted);
	if (g_char.bits_shifted == 7)
	{
		ft_putchar_fd(g_char.assembled, STDOUT_FILENO);
		ft_bzero(&g_char, 2);
		return ;
	}
	g_char.bits_shifted++;
}

int	main(void)
{
	ft_bzero(&g_char, 2);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	signal(SIGUSR1, char_display);
	signal(SIGUSR2, char_display);
	while (true)
		pause();
}