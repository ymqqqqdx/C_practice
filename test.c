#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char buf[20];
    strcpy(buf, "hello");
    puts(buf);
    printf("%d\n", strlen(buf));
    while(1);
    return 0;
}
