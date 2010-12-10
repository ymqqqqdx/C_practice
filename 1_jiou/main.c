#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(int argc, const char *argv[])
{
    int a[50];
    int i=0,oddadd=0,evenadd=0;
    srand((unsigned)time(NULL));

    for(i=0;i<50;i++)
    {
        a[i]=rand()%30;
        printf("%d%c",a[i],((i+1)%4==0)?'\n':'\t');
    }

    for(i=0;i<50;i++)
    {
        if(a[i]%2)
            evenadd++;
        else
            oddadd++;
    }

    printf("\nIn array a, %d numbers are even ,%d numbers are odds\n",evenadd,oddadd);
    return 0;
}
