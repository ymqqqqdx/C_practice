#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fd1, fd2;
    struct stat buf;
    char buffer[10000];
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR | O_CREAT, 00644);
    fstat(fd1, &buf);
    read(fd1, buffer, buf.st_size);    
    write(fd2, buffer, buf.st_size); 
    close(fd1);
    close(fd2);
    return 0;
}
