/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:04:27 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/25 20:04:27 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void signal_handler(int signum)
{
    static int bit;
    static char c;

    if (bit == 0)
        c = 0;

    c |= (signum == SIGUSR2);
    bit++;

    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
    }
    else
    {
        c <<= 1;
    }
}

int main(void)
{
    int pid;
	pid = getpid();
	printf("Server PID: %d\n", pid);
   
    while (1)
    {
        signal(SIGUSR1, signal_handler);
    	signal(SIGUSR2, signal_handler);
	    pause();
    }
    return 0;
}
