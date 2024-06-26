/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:08:41 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/24 23:08:41 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

void send_char(pid_t pid, char c)
{
	int bit;
	bit = 7;

	while (bit >= 0)
	{
		if(c & (1<<bit--))
			kill(pid, SIGUSR2);//1
		else
			kill(pid, SIGUSR1);//0
		usleep(100);
	}
		
}

void send_sring(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str++);
	}
	
}

int main(int ac, char *av[])
{
	if	(ac != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid_t pid;
	pid = atoi(av[1]);
	send_sring(pid, av[2]);
	return (0);
}