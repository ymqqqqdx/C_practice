#include <stdio.h>
#include <string.h>
union day{
    int a;
    char b;
    char c[100];
};
union day day1;

int main(int argc, const char *argv[])
{
    int i;
    day1.a=123;
    printf("%d\n",day1.a);
    strcpy(day1.c,"abcdefg");
    printf("%x\n",day1.a);
    for(i=0;i<4;i++)
    {
        printf("%x",day1.c[i]);
    }
    puts("");
    return 0;
}
