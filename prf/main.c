#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i='a';
    printf("0x%x\n",(unsigned int)(&i));
    printf("%c\n",i);
    printf("%x\n",i);
    printf("%d\n",i);
    printf("size of int is %d\n",sizeof(int));
    printf("size of float is %d\n",sizeof(float));
    printf("size of double is %d\n",sizeof(double));
    printf("size of char is %d\n",sizeof(char));
    i=32;
    while(i<127)
        printf("%3d: %c%c",i++,i,(i-31)%8==0?'\n':'\t');
    puts("");
    putchar('a'-' ');
    puts("");
    putchar(getchar());
    return 0;
}
