#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int fd;
    fd = open("1.txt", O_RDWR | O_CREAT, 00644);
    lseek(fd, 100, SEEK_CUR);
    write(fd, "1", 1);
    close(fd);
    return 0;
}
