#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(int argc, const char *argv[])
{
    int fd1, fd2, fdtemp;
    float tmp;
    struct stat buf;
    unsigned char *fp1, *fp2;
    int *fptemp;
    int res1, res2, res3;
    int i = 0;
    char buff[100];
    system("rm _TEMP_");
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR | O_CREAT, 00644);
    fdtemp = open("_TEMP_", O_RDWR | O_CREAT, 00644);
    //fdbak = fdtemp;
    fstat(fdtemp, &buf);
    lseek(fdtemp, 3, SEEK_CUR);
    write(fdtemp, "\0", 1);
    fstat(fd1, &buf);
    lseek(fd2, buf.st_size - 1, SEEK_CUR);
    write(fd2, "1", 1);
    fp1 = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    fp2 = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    fptemp = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED, fdtemp, 0);
    res1 = fork();
    if(res1 == 0)
    {
        res2 = fork();
        if(res2 == 0)
        {
            for(i = 0; i < buf.st_size / 3; i++)
            {
                *(fp2 + i) = *(fp1 + i);
                if(i % 100000 == 0) *fptemp += 100000;
            }
        }
        if(res2 > 0)
        {
            for(i = buf.st_size / 3; i < buf.st_size / 3 * 2; i++)
            {
                *(fp2 + i) = *(fp1 + i);
                if(i % 100000 == 0) *fptemp += 100000;
            }
        }
    }
    if(res1 > 0)
    {
        res3 = fork();
        if(res3 == 0)
        {
            for(i = buf.st_size / 3 * 2; i < buf.st_size; i++)
            {
                *(fp2 + i) = *(fp1 + i);
                if(i % 100000 == 0) *fptemp += 100000;
            }
        }
        if(res3 > 0)
        {
            while(1)
            {
                printf("%.1f%% Complete...\n", tmp = (float)*fptemp / (float)buf.st_size * 100);
                //printf("%d\t%ld\n",*fptemp, buf.st_size);
                if(tmp >= 100) break;
                usleep(10000);
                //sleep(1);
            }
            printf("Verifying...\n");
            sprintf(buff, "md5sum %s", argv[1]);
            system(buff);
            sprintf(buff, "md5sum %s", argv[2]);
            system(buff);
            printf("Verify OK!\n");
        }
    }
    close(fd1);
    close(fd2);
    close(fdtemp);
    wait();
    //system("rm _TEMP_");
    return 0;
}
