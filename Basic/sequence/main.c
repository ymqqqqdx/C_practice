#include <stdio.h>
int a[10]={1,23,43,65,34,65,23,43,56,54};
char b[10]={21,54,23,76,23,42,45,98,76,40};
void * get_max(void *,int,int ,int (*)(void *,void *));
int cmp_int(void *,void * );
int cmp_char(void *,void * );
int main(int argc, const char *argv[])
{
    void *temp;
    temp = get_max(a,10,sizeof(int),cmp_int);
    printf("The biggest in arry a is:%d\n",*(int *)temp);
    temp = get_max(b,10,sizeof(char),cmp_char);
    printf("The biggest in arry b is:%d\n",*(char *)temp);
    return 0;
}

int cmp_int(void *a,void *b)
{
    if(*(int *)a > *(int *)b)
        return 0;
    else
        return 1;
}

int cmp_char(void *a,void *b)
{
    if(*(char *)a > *(char *)b)
        return 0;
    else
        return 1;
}

void * get_max(void *a,int len,int size,int (*fun)(void *,void *))
{
   int i;
   void *temp=a;
   for(i=0;i<len-1;i++)
   {
        if(fun(temp,a+(i+1)*size))
            temp=a+(i+1)*size;
   }
   return temp;
}
