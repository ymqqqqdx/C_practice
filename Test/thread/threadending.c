#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_1(void *arg)
{
    printf("%s\n", "thread 1 returning");
    return (void *)1;
}

void *thread_2(void *arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
}

void *thread_3(void *arg)
{
    while(1)
    {
        printf("thread 3 writing\n");
        sleep(1);
    }
}

int main(int argc, const char *argv[])
{
    pthread_t tid;
    void *tret;
    pthread_create(&tid, NULL, thread_1, NULL);    
    pthread_join(tid, &tret);//wait thread return
    printf("thread 1 exit code %d\n", (int)(tret));

    pthread_create(&tid, NULL, thread_2, NULL);
    pthread_join(tid, &tret);
    printf("thread 2 exit code %d\n", (int)tret);

    pthread_create(&tid, NULL, thread_3, NULL);
    sleep(3);
    pthread_cancel(tid);//end thread 3
    pthread_join(tid, &tret);
    printf("thread 3 exit code %d\n", (int)tret);
    return 0;
}
