#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int id;
    struct node *next;
}node_t;

node_t * create(node_t *ori,int id)
{
    node_t *p = malloc(sizeof(node_t));
    p->next = NULL;
    p->id = id;
    ori->next = p;
    return p;
}
void travel(node_t *head)
{
    while(head)
    {
        printf("%d\n",head->id);
        head = head->next;
    }
}
node_t * tailtohead(node_t *head)
{
    node_t * p1 = head;
    node_t * p2 = head->next;
    node_t * p3 = head->next->next;
    
    head->next = NULL;
    while(p2)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3 ? p3->next : NULL;
    }
    return p1;
}
int main(int argc, const char *argv[])
{
    int i;
    node_t *head = malloc(sizeof(node_t));
    node_t *p = head;
    head->id = 1;
    for(i = 1; i < 10; i++)
        p = create(p, i + 1);
    travel(head);
    head = tailtohead(head);
    travel(head);
    return 0;
}
