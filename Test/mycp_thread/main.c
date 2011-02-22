#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>

pthread_t ntid;
int fd, num;
unsigned char *fp1, *fp2;
struct stat buf;
int total;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t create_mutex = PTHREAD_MUTEX_INITIALIZER;
void *thr_pr(void)
{
    while(1)
    {
        printf("\b\b\b\b%ld%%", total * 100 / buf.st_size);
        if(total >= buf.st_size)
            exit(0);
        usleep(100);
    }
}
void *thr_cp(void *number)
{
    int seq = (int)number;
    int i;
    printf("%d\n", seq);
    for (i = (buf.st_size / num) * (seq - 1); seq == num ? i < (buf.st_size / num) * seq + (buf.st_size / num) * seq + (buf.st_size % num) : i < (buf.st_size / num) * seq ; i++) 
    {
        pthread_mutex_lock(&mutex);
        *(fp2 + i) = *(fp1 + i);
        total++;
        pthread_mutex_unlock(&mutex);
    }
}
int main(int argc, const char *argv[])
{
    int fd1, i;
    pthread_t tid;
    if(argc < 4)
    {
        printf("Usage: %s source target thread\n", argv[0]);
        exit(1);
    }
    fd1 = open(argv[1], O_RDONLY);
    fd = open(argv[2], O_RDWR | O_CREAT, 00644);
    fstat(fd1, &buf);
    lseek(fd, buf.st_size - 1, SEEK_CUR);
    write(fd, "1", 1);
    num = atoi(argv[3]);
    fp1 = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    fp2 = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    pthread_create(&ntid, NULL, (void *)thr_pr, NULL);
    for (i = 1; i < num + 1; i++) 
    {
        tid = pthread_create(&ntid, NULL, (void *)thr_cp, (void *)i); 
    }
    while(1)
        sleep(1);
    return 0;
}
