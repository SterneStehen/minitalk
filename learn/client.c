// client.c
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void send_char(pid_t pid, char c)
{
    int bit = 7;
    while (bit >= 0)
    {
        if (c & (1 << bit))
            kill(pid, SIGUSR2);//1
        else
            kill(pid, SIGUSR1);//0
        usleep(100);
        bit--;
    }
}

void send_string(pid_t pid, char *str)
{
    while (*str)
    {
        send_char(pid, *str++);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(2, "Usage: ./client <PID> <message>\n", 32);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    send_string(pid, argv[2]);
    return 0;
}
