//#include <stdio.h>
int add_two_number(int,int);
int main(int argc, const char *argv[])
{
    int a=0,b=0;
    scanf("%d,%d",&a,&b);
    printf("%d",add_two_number(a,b));
    return 0;
}

int add_two_number(int a,int b)
{
    return a+b;
}
