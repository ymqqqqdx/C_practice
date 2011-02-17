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
    int fd1, fd2;
    struct stat buf;
    unsigned char *fp1, *fp2;
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR | O_CREAT, 00644);
    fstat(fd1, &buf);
    lseek(fd2, buf.st_size - 1, SEEK_CUR);
    write(fd2, "1", 1);
    fp1 = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd1, 0);
    fp2 = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    memcpy(fp2, fp1, buf.st_size);
    close(fd1);
    close(fd2);
    return 0;
}
