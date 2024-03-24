// server.c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signal_handler(int signum)
{
    static int bit = 0;
    static char c = 0;

    c |= (signum == SIGUSR2);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
    else
    {
        c <<= 1;
    }
}

int main(void)
{
    printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
    {
        pause(); // Wait for signals
    }
    return 0;
}
