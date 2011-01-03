#include <stdio.h>
#include <string.h>
void foo(char *src,char *a[])
{
    int i = 0;
    do
    {
        a[i] = strtok(src," ");
        src = NULL;
    }while(a[i++]);
}
int main(int argc, const char *argv[])
{
    int i = 0;
    char src[100];
    char *a[100];
    fgets(src,100,stdin);
    src[strlen(src) - 1] = '\0';
    foo(src,a);
    while(a[i])
        puts(a[i++]);
    puts(src);
    return 0;
}
