#include <stdio.h>

int main(int argc, const char *argv[])
{
    int *p[4];
    int i;
    char *temp;
    char bb[20]={1,2,3,4,5,6,7,8,9};
    p[1]=(int *)bb;
    for(i=0;i<9;i++)
    {
       printf("%d\n",*((char *)(p[1])+i) );
    }
    return 0;
}
