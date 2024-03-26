/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:04:27 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/26 00:51:34 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	signal_handler(int signum)
{
	static int	bit = 0;
	static char	c = 0;

	if (bit > 0)
	{
		c <<= 1;
	}
	if (signum == SIGUSR2)
	{
		c |= 1;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("PID process = %d\n", pid);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR || signal(SIGUSR2,
			signal_handler) == SIG_ERR)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
