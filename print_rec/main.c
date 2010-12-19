#include <stdio.h>
void print_matrix(int);
int main(int argc, const char *argv[])
{
    int temp;
    void (*funp)(int) = print_matrix;
    sscanf(argv[1],"%d",&temp);
    (*funp)(temp);
    return 0;
}

void put_c(void)
{
    printf("* ");
}
void print_matrix(int width)
{
    int i,j;
    void (*funp)(void) = put_c;
    for(i=0;i<width;i++,putchar('\n'))
        for(j=0;j<width;j++,(*funp)());
}
