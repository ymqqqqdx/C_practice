#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char buff[10];
    int n;
    if( ( n = read(STDIN_FILENO, buff, 10) ) < 0)
    {
        perror("read");
        exit(1);
    }
    write(STDOUT_FILENO, buff, n);
    return 0;
}
