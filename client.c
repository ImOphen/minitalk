/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:19:22 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/12 11:19:24 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("signal recieved\n");
}

void	send_null(pid_t pid)
{
	int	byte;

	byte = 8;
	while (byte--)
	{
		kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	int			byte;
	static int	i;

	signal(SIGUSR1, signal_handler);
	if (argc < 3)
		return (ft_printf("WRONG ARGUMENTS\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (ft_printf("PID NOT VALID\n"), 0);
	while (argv[2][i])
	{
		byte = 8;
		while (byte--)
		{
			if (argv[2][i] & 1 << byte)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
		}
		i++;
	}
	send_null(pid);
}
