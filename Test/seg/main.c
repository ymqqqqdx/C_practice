#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, const char *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
        while(1)
        {
            printf("%s\n","Hello world!");
            usleep(100000);
        }
    }
    else if(pid == 0)
    {
        sleep(3);
        kill(getppid(), SIGKILL);
    }
    return 0;
}
