/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/28 16:36:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	ft_send(int pid, char sent)
{
	int	bits_shifted;
	int	status;

	bits_shifted = 0;
	while (bits_shifted < 8)
	{
		if ((sent >> bits_shifted) & 0b00000001)
			status = kill(pid, SIGUSR1);
		else
			status = kill(pid, SIGUSR2);
		if (status == -1)
			ft_error("Kill error.");
		bits_shifted++;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
		ft_error("Invalid Syntax.");
	else if (ft_strlen(argv[1]) > 7)
		ft_error("Invalid PID.");
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		ft_send(pid, *argv[2]);
		argv[2]++;
	}
}
