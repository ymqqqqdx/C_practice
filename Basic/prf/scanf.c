#include <stdio.h>
void print_hello();
int main(int argc, const char *argv[])
{
    char aa[100];
    char *a=aa;
    scanf("%s",a);
    puts(a);
    print_hello();
    return 0;
}
void print_hello()
{
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
}
