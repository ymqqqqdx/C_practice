#include <stdio.h>
#include <string.h>
typedef struct aa{
    int length;
    char *pt;
}info;
info maxsubstring(char *a)
{
    int max=1;
    char *max_p=a;
    char *char_pt=a;
    info temp;
    a++;
    while(*a++)
    {
        if(*a != *(a-1))
        {
            if(max < a-max_p)
            {
                max = a - max_p;
                char_pt = a;
            }
            max_p = a;
        }
    }
    temp.pt = char_pt - max;
    temp.length = max;
    return temp;
}
int main(int argc, const char *argv[])
{
    int i=0;
    info temp;
    char buff[1000];
    strcpy(buff,argv[1]);
    temp=maxsubstring(buff);
    printf("%d\n",temp.length);
    for(i=0;i<temp.length;i++)
        putchar(*temp.pt);
    putchar('\n');
    return 0;
}
