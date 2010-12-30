#include <stdio.h>

int main(int argc, const char *argv[])
{
    unsigned int a = 0x8ff,i;
    for(i = 0;i < 32;i++)
        printf("%d",((a<<i) & 0x80000000) == 0x80000000);
    putchar('\n');
    return 0;
}
