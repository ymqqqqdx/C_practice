#include <stdio.h>
#define is_even(n) !is_odd(n)
int is_odd(int n){return n%2;}
void get_random(int *p,int size)
{
    int i = 0;
    srand((unsigned)time(NULL));
    while(size - i)
        *(p + i++) = rand()%100;
}
void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
int main(int argc, const char *argv[])
{
    int arr[100],i = 0,j = 100 - 1;
    get_random(arr,100);
    while(i < j)
    {
        while(is_odd(arr[i])) i++;
        while(is_even(arr[j])) j--;
        swap(&arr[i],&arr[j]);
    }
    i = 0;
    while(100 - i)
        printf("%d%c",*(arr + i++),(i + 1)%10 ?'\t':'\n');
    return 0;
}
