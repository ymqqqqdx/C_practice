#include <stdio.h>
void print_matrix(int,void (*)(char),char);
void put_c(char t){printf("%c ",t);}
int main(int argc, const char *argv[])
{
    int temp;
    void (*funp)(int,void (*)(char),char) = print_matrix;
    sscanf(argv[1],"%d",&temp);
    (*funp)(temp,put_c,argv[2][0]);
    return 0;
}
void print_matrix(int width,void (*putsth)(char),char tt)
{
    int i,j;
    for(i=0;i<width;i++,putchar('\n'))
        for(j=0;j<width;j++,(*putsth)(tt));
}
