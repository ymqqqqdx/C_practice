#include <stdio.h>
#include <signal.h>

void func(int num)
{
    wait();
    printf("%s\n","child end");
}
int main(int argc, const char *argv[])
{
    struct sigaction newsig;
    int res, res2;
    int i;

    newsig.sa_handler = func;
    newsig.sa_flags = 0;
    sigemptyset(&newsig.sa_mask);

    sigaction(SIGCHLD, &newsig, NULL);
    res = fork();
    if(res > 0)
    {
        while(1)
        {
            printf("parent\n");
            sleep(1);
        }
    }
    else if(res == 0)
    {
        res2 = fork();
        if(res2 > 0)
        {
            for (i = 0; i < 10; i++) 
            {
                sleep(1);
                printf("child%d\n", i);
            }
        }
        else if(res2 == 0)
        {
            for (i = 0; i < 20; i++) 
            {
                printf("cccccc\n");
            }
        }
    }
    return 0;
}
