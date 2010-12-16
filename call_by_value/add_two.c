#include <stdio.h>
int add_two(int i,int j);
int main(int argc, const char *argv[])
{
    printf("%d",add_two(3,5));
    return 0;
}
int add_two(int i,int j)
{
    return (i+j);
}
