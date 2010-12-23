#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int *p;
    int max=10;
    int i=0,k=0;
    p = malloc(sizeof(int)*max);
    while(1)
    {
        scanf("%d",p + i++);
        if(i == max)
            p = realloc(p,sizeof(int)*(max+=10));
        if(*(p+i-1) == -1)
            break;
    }
    while(i-k)
        printf("%d%c",*(p + k++),(k+1)%10 == 0?'\n':'\t');
    putchar('\n');
    free(p);
    return 0;
}
