#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    printf("0x%x\n",(unsigned int)(&i));
    i=97;
    printf("%c\n",i);
    printf("%x\n",i);
    printf("%d\n",i);
    printf("size of int is %d\n",sizeof(int));
    printf("size of float is %d\n",sizeof(float));
    printf("size of double is %d\n",sizeof(double));
    printf("size of char is %d\n",sizeof(char));
    return 0;
}
