#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a = 11,b = 89;
    char c;
    a = a^b;
    b = a^b;
    a = a^b;
    printf("%d\n",a);
    printf("%d\n",b);
    return 0;
}
