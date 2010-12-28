#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct str{
    char name[256];
    int id;
    int chinese;
    struct str *next;
}stu;
stu * create(stu * pro,int id,int chinese,char *name)
{
    stu *p = malloc(sizeof(stu));
    p->id = id;
    p->chinese = chinese;
    strcpy(p->name,name);
    p->next = NULL;
    if(pro)
        pro->next = p;
    return p;
}
void print(stu *p)
{
    printf("%s\t%d\t%d\n",p->name,p->id,p->chinese);
}
void freelist(stu *p)
{
    stu *temp;
    while(p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}
void travel(stu *p,void (*fun)(stu *))
{
    while(p)
    {
        fun(p);
        p = p->next;
    }
}
stu * del(int id,stu *head)
{
    stu *temp = head;
    stu *p = head;
    if(p->id == id)
    {
        p = p->next;
        free(temp);
        return p;
    }
    while(p)
    {
        temp = p;
        p = p->next;
        if(p)
            if(p->id == id)
                temp->next = p->next;
    }
    return head;
}
stu * insert_next(int id,stu *next,int nid,int chinese,char *name)
{
    stu *p = next;
    stu *temp = malloc(sizeof(stu));
    temp->id =nid;
    temp->chinese = chinese;
    strcpy(temp->name,name);
    while(p)
    {
        temp->next = p->next;
        if(p->id == id)
        {
            p->next = temp;
            return p;
        }
        p = p->next;
    }
}
int main(int argc, const char *argv[])
{
    stu *head = NULL,*p;
    head = create(head,1,98,"zhang");
    p = create(head,2,78,"wang");
    p = create(p,3,89,"li");
    p = create(p,4,90,"zhao");
    p = create(p,5,67,"zhou");
    p = create(p,6,79,"wu");
    //travel(head,print);
    //head = del(1,head);
    //travel(head,print);
    insert_next(1,head,12,88,"emule");
    travel(head,print);
    freelist(head);
    return 0;
}
