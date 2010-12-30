#include <stdio.h>

int main(int argc, const char *argv[])
{
    unsigned int a = 239,b = 78,result = 0,i;
    for(i = 0;i < 32;i++)
    {
        if((b >> i) & 0x01)
            result += a << i;
    }
    printf("%d\n",result);
    return 0;
}
