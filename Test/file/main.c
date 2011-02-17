#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp1;
    int fp;
    char *str = "Hello world!";

    fp1 = fopen("akaedu.txt", "w");
    fputs(str, fp1);
    fclose(fp1);

    if((fp = open("aka2.txt", O_RDWR | O_CREAT, 0777)) == -1)
    {
        perror("create");
        exit(-1);
    }

    write(fp, str, strlen(str));
    close(fp);
    return 0;
}
