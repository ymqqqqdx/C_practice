#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int num = 1;
    int res, res2, res3;
    res = fork();
    if(res < 0)
    {
        perror("fork");
        exit(-1);
    }
    if(res > 0)
    {
        res2 = fork();
        if(res2 < 0)
        {
            perror("fork");
            exit(-1);
        }
        if(res2 > 0)
        {
            printf("parent\n");
            wait();
        }
        if(res2 == 0)
        {
            while(1)
            {
                sleep(1);
                printf("child2\n");
            }
        }
    }
    if(res == 0)
    {
        res3 = fork();
        if(res3 < 0)
        {
            perror("fork");
            exit(-1);
        }
        if(res3 > 0)
        {
            while(1)
            {
                sleep(1);
                printf("child1\n");
                execlp("hello", "child1", NULL);
            }
        }
        if(res3 == 0)
        {
            while(1)
            {
                execl("/home/ymqqqqdx/Documents/C_practice/Fork/hello", "child", NULL);
            }
        }
    }
    return 0;
}
