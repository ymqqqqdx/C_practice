#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct jose{
    int id;
    struct jose *next;
}loop;
loop * create(loop *pro,int id)
{
    loop *p = malloc(sizeof(loop));
    p->id = id;
    p->next = NULL;
    if(pro)
        pro->next = p;
    return p;
}
void travel(loop *head)
{
    int i = 0;
    while(head)
    {
        printf("%d%c",head->id,(++i)%10?'\t':'\n');
        head = head->next;
    }
}
loop *sequence(loop *lp)
{
    loop *head,*tail,*temp;
    loop *p,*t;
    head = malloc(sizeof(loop));
    tail = malloc(sizeof(loop));
    head->id = lp->id;
    lp = lp->next;
    if(lp->id >= head->id)
        tail->id = lp->id;
    else
    {
        tail->id = head->id;
        head->id = lp->id;
    }
    head->next = tail;
    while(lp)
    {
        lp = lp->next;
            if(!lp) break;
        temp = malloc(sizeof(loop));
        temp->id = lp->id;
        if(lp->id >= tail->id)
        {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
        else if(lp->id <= head->id)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            p = head;
            while(p)
            {
                t = p;
                p = p->next;
                if(!p) break;
                if((lp->id >= t->id) && (lp->id <= p->id))
                {
                    t->next = temp;
                    temp->next = p;
                    break;
                }
            }
        }
    }
    printf("head%d\n",head->id);
    printf("tail%d\n",tail->id);
    return head;
}
int main(int argc, const char *argv[])
{
    loop *head = NULL,*p;
    int i;
    srand((unsigned)time(NULL));
    head = create(head,rand()%1000);
    for(i = 1;i < 100;i++)
        p = create((i-1)?p:head,rand()%1000);
    travel(head);
    putchar('\n');
    travel(sequence(head));
    return 0;
}
