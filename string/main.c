#include <stdio.h>

int main(int argc, const char *argv[])
{
    char aa[10]={"what is?"};
    char *pt=aa;
    int i;
    aa[10]=89;
    for(i=0;i<8;i++)
    putchar(aa[i]);
        
    while(*pt!='\0')
        putchar(*pt++);
    putchar('\n');

    putchar(getchar());

    return 0;
}
