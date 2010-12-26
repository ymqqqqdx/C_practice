#include <stdio.h>
#include <stdlib.h>
typedef struct jose{
    int id;
    struct jose *next;
}loop;
int count = 0;

loop * create(loop *pro,int id)
{
    loop *p = malloc(sizeof(loop));
    p->id = id;
    p->next = NULL;
    if(pro)
        pro->next = p;
    return p;
}

int jose(loop *p,const int m)
{
    loop *temp;
    int i = m,t = 0;
    while(--i)
    {
        temp = p;
        p = p->next;
    }
    printf("%3d: %3d out%c",count,p->id,++count%5==0?'\n':'\t');
    if(count == 100)
       return 0; 
    temp->next = p->next;
    free(p);
    jose(p->next,m);
}

int main(int argc, const char *argv[])
{
    loop *head = NULL,*p;
    int i;
    head = create(head,1);
    for(i = 1;i < 100;i++)
        p = create((i-1)?p:head,i+1);
    p->next = head;
    jose(head,3);
    return 0;
}
