#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct jose{
    int id;
    struct jose *next;
}loop;
int main(int argc, const char *argv[])
{
    loop *head = NULL,*p;
    srand((unsigned)time(NULL));
    head = create(head,1);
    for(i = 1;i < 100;i++)
        p = create((i-1)?p:head,rand()%1000);
    return 0;
}
