#include <stdio.h>
typedef struct aa{
    int length;
    char *pt;
}bb;
bb maxsubstring(char *a)
{
    int max=1;
    char *max_p=a;
    char *max_pt=a;
    bb temp;
    a++;
    while(*a++)
    {
        if(*a != *(a-1))
        {
            if(max< a-max_p)
            {
                max = a - max_p;
                max_pt = a;
            }
            max_p = a;
        }
    }
    temp.pt = max_pt - max;
    temp.length = max;
    return temp;
}
int main(int argc, const char *argv[])
{
    char buf[100];
    int i;
    bb temp;
    temp=maxsubstring("eeeeeeeeeeeeewwwwwwwwwwwwwwwwwwwwwwwwqqqqqqqqqqqqqqljasdlkfjllllllll");
    printf("%d\n",temp.length);
    for(i=0;i<temp.length;i++)
        putchar(*temp.pt);
    putchar('\n');
    return 0;
}
