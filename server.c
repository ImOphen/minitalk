/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:19:16 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/12 11:19:18 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *(v))
{
	static int	character;
	static int	client_pid;
	static int	i;

	(void)v;
	if ((client_pid != info->si_pid && i != 0))
	{
		i = 0;
		character = 0;
	}
	character = (character << 1) | ((sig - SIGUSR1) ^ 1);
	i++;
	if (i == 8)
	{
		if (character == 0)
			kill(info ->si_pid, SIGUSR1);
		else
			write(1, &character, 1);
		character = 0;
		i = 0;
	}
	client_pid = info -> si_pid;
}

int	main(void)
{
	pid_t				pid;
	int					b;
	struct sigaction	signals;

	b = 0;
	signals.sa_sigaction = &signal_handler;
	pid = getpid();
	ft_printf("My Process ID is : %d\n", pid);
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
