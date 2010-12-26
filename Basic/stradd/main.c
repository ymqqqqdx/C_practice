#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a=0,b=0;
    printf("Enter a:\n");
    scanf("0x%x",&a);
    getchar();
    printf("Enter b:\n");
    scanf("0x%x",&b);
    printf("Result a+b= 0x%x\n",a+b);
    return 0;
}
