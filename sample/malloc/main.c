#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    char *pt;
    int i;
    pt = (char *)malloc(10);
    if(!pt) return 1;
    for(i=0;i<10;*(pt+i++)=i+1);
    for(i=0;i<10;printf("%d\t",*(pt+i++)));
    return 0;
}
