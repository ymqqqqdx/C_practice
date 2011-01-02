#include <stdio.h>
#include <stdlib.h>
void get_random(int *p,int size)
{
    int i = 0;
    srand((unsigned)time(NULL));
    while(size - i)
        *(p + i++) = rand()%100;
}
int find_same(int *p,int num,int size)
{
    int i = num + 1;
    while(size - i)
    {
        if(*(p + i++) == *(p + num))
            return 0;
    }
    return 1;
}
int del_same(int *ori,int *tar,int size)
{
    int i,k = 0;
    for(i = 0;i < size;i++)
    {
        if(find_same(ori,i,size))
            *(tar + k++) = *(ori + i);
    }
    return k;
}
int main(int argc, const char *argv[])
{
    int i = 0,k = 0;
    int *ch = malloc(100 * sizeof(int));
    int *ta = malloc(100 * sizeof(int));
    get_random(ch,100);
    while(100 - i)
        printf("%d%c",*(ch + i++),(i + 1)%10 ?'\t':'\n');
    k = del_same(ch,ta,100);
    i = 0;
    while(k - i)
        printf("%d%c",*(ta + i++),(i + 1)%10 ?'\t':'\n');
    return 0;
}
