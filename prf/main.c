#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    printf("0x%x\n",(unsigned int)(&i));
    i=97;
    printf("%c\n",i);
    printf("%x\n",i);
    printf("%d\n",i);
    return 0;
}
