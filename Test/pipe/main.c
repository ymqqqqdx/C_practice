#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[80];

    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid > 0)
    {
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        read(fd[0], line, 80);
        write(STDOUT_FILENO, line, 12);
    }
    return 0;
}
