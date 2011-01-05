#include <stdio.h>

int fun(int t)
{
    return !(t % 2);
}
int main(int argc, const char *argv[])
{
    FILE *fp1 = fopen("in.dat","r");
    FILE *fp2 = fopen("out.dat","w");
    int x;
    while(!feof(fp1))
    {
        fscanf(fp1,"%d",&x);
        if(fun(x/1000) && fun(x%1000/100) && fun(x%100/10) && fun(x%10))
            fprintf(fp2, "%d\n",x);
    }
    return 0;
}
