#include <stdio.h>
#include <stdlib.h>
typedef struct dd{
    int id;
    struct dd *next;
}sol;
sol * create(sol *org,int id)
{
    sol *p = malloc(sizeof(sol));
    p->id = id;
    p->next = NULL;
    if(org)
        org->next = p;
    return p;
}
void travel_loop(sol *head)
{
    sol *p = head->next;
    while(p != head)
    {
        printf("%d\n",p->id);
        p = p->next;
    }
}
int main(int argc, const char *argv[])
{
    sol *head = NULL,*p;
    int i;
    head = create(head,1);
    for(i = 1;i < 100;i++)
        p = create((i - 1)?p:head,i + 1);
    p->next  = head;
    travel_loop(head);
    return 0;
}
