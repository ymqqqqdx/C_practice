#include <stdio.h>
#include <stdlib.h>
typedef struct jose{
    int id;
    struct jose *next;
}loop;
int count = 0,N=0,M=0;
/** 
* @brief create a node of a linked list
* 
* @param pro orignal address
* @param id people's id
* 
* @return address of the newly built
*/
loop * create(loop *pro,int id)
{
    loop *p = malloc(sizeof(loop));
    p->id = id;
    p->next = NULL;
    if(pro)
        pro->next = p;
    return p;
}
/** 
* @brief travel all points of the list and print the id of the out
* 
* @param p original address
* @param m out when count to m
* 
* @return success return 0
*/
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
    if(count == N)
       return 0; 
    temp->next = p->next;
    free(p);
    jose(temp->next,m);
}
int main(int argc, const char *argv[])
{
    loop *head = NULL,*p;
    int i;
    N = atoi(argv[1]);
    M = atoi(argv[2]);
    head = create(head,1);
    for(i = 1;i < N;i++)
        p = create((i-1)?p:head,i+1);
    p->next = head;
    jose(head,M);
    return 0;
}
