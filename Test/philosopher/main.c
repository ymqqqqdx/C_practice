#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t chopstick[5] = {PTHREAD_MUTEX_INITIALIZER};

void *chop(void *num)
{
    int whom = (int )num;
    printf("thread %d created\n", whom);
    if(whom != 3)
    {
        while(1)
        {
            usleep(rand() % 5);
            pthread_mutex_lock(&chopstick[whom == 1 ? 5 : whom - 1]);
            printf("Philosoper %d fetch chopstick %d\n", whom, whom == 1 ? 5 : whom - 1);
            pthread_mutex_lock(&chopstick[whom == 5 ? 1 : whom + 1]);
            printf("Philosoper %d fetch chopstick %d\n", whom, whom == 5 ? 1 : whom + 1);
            usleep(rand() % 5);
            pthread_mutex_unlock(&chopstick[whom == 1 ? 5 : whom - 1]);
            pthread_mutex_unlock(&chopstick[whom == 5 ? 1 : whom + 1]);
            printf("Philosoper %d released chopstick %d %d\n", whom, whom == 1 ? 5 : whom - 1, whom == 5 ? 1 : whom + 1);
        }
    }
    else
    {
        while(1)
        {
            usleep(rand() % 5);
            pthread_mutex_lock(&chopstick[whom == 5 ? 1 : whom + 1]);
            printf("Philosoper %d fetch chopstick %d\n", whom, whom == 5 ? 1 : whom + 1);
            pthread_mutex_lock(&chopstick[whom == 1 ? 5 : whom - 1]);
            printf("Philosoper %d fetch chopstick %d\n", whom, whom == 1 ? 5 : whom - 1);
            usleep(rand() % 5);
            pthread_mutex_unlock(&chopstick[whom == 1 ? 5 : whom - 1]);
            pthread_mutex_unlock(&chopstick[whom == 5 ? 1 : whom + 1]);
            printf("Philosoper %d released chopstick %d %d\n", whom, whom == 1 ? 5 : whom - 1, whom == 5 ? 1 : whom + 1);
        }
    }
}
int main(int argc, const char *argv[])
{
    pthread_t tid[5];
    int i;
    for (i = 1; i < 6; i++) 
    {
        pthread_create(&tid[i - 1], NULL, (void *)chop, (void *)i);
    }
    for (i = 0; i < 5; i++) 
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
