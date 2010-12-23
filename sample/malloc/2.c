#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct x{
    char buf[10];
    int y;
}info;
int main(int argc, const char *argv[])
{
    info *pt;
    int i;
    pt = (info *)malloc(sizeof(info)*10);
    if(!pt) return 1;
    for(i=0;i<10;strcpy((pt+i++)->buf,"hello"));
    for(i=0;i<10;pt[i++].y = i+1);
    for(i=0;i<10;puts((pt+i++)->buf));
    for(i=0;i<10;printf("%d\n",pt[i++].y));
    return 0;
}
