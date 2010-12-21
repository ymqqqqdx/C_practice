#include <stdio.h>

void print_arr(void *,int,int);
void bubble(void *,int,int,int (*)(void *,void *),void (*)(void *,void *));
void get_random(int,int,void *);
int cmp_char(void *,void *);
int cmp_int(void *,void *);
void swap_char(void *,void *);
void swap_int(void *,void *);

int main(int argc, const char *argv[])
{
    int i;
    char arr_c [100];
    int arr_i [100];
    get_random(sizeof(char) , sizeof(arr_c)/sizeof(char), arr_c);
    get_random(sizeof(int) , sizeof(arr_i)/sizeof(int), arr_i);
    printf("The Orignal of arr_c is(Random):\n");
    print_arr(arr_c,sizeof(char),sizeof(arr_c)/sizeof(char));
    printf("The Orignal of arr_i is(Random):\n");
    print_arr(arr_i,sizeof(int),sizeof(arr_i)/sizeof(int));
    bubble(arr_c,sizeof(arr_c)/sizeof(char),sizeof(char),cmp_char,swap_char);
    bubble(arr_i,sizeof(arr_i)/sizeof(int),sizeof(int),cmp_int,swap_int);
    printf("The Target of arr_c is:\n");
    print_arr(arr_c,sizeof(char),sizeof(arr_c)/sizeof(char));
    printf("The Target of arr_i is:\n");
    print_arr(arr_i,sizeof(int),sizeof(arr_i)/sizeof(int));
    return 0;
}
void print_arr(void *arr,int size,int length)
{
    int i;
    for(i=0;i<length;i++)
        printf("%d%c", size==1?*(char *)(arr+i):*(int *)(arr+i*4) , (i+1)%15==0 ?'\n':'\t');
    putchar('\n');
}
void bubble(void *arr,int length,int size,int (* fun)(void *,void *),void (*fun1)(void *,void *))
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<(length - i -1);j++)
        {
            if( fun(arr + j*size, arr + (j + 1)*size) )
            {
                fun1(arr + j*size, arr + (j + 1)*size);
            }
        }
    }
}

void get_random(int size,int length,void *arr)
{
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<length;i++)
    {
        if(size==1)
            *(char *)(arr+ size*i) = rand()%127;
        else
            *(int *)(arr + size*i) = rand()%1000;
    }
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
void swap_char(void *a,void *b)
{
    char temp;
    temp = *(char *)a;
    *(char *)a = *(char *)b;
    *(char *)b = temp;
}
void swap_int(void *a,void *b)
{
    int temp;
    temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}
