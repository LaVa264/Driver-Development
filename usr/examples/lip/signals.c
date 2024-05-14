#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

volatile bool received_sigint = false;

void sigint_handler(int sig)
{
    received_sigint = true;
    printf("SIGINT\n");
}

int main()
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        printf("Failed to disposition SIGINT!\n");
        exit(EXIT_FAILURE);
    }

    printf("PID: %d\n", getpid());

    while (!received_sigint);
}