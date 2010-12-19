#include <stdio.h>
typedef int (* funp) (int,int);
int add(int i,int j){return i+j;}
int sub(int i,int j){return i-j;}
int mul(int i,int j){return i*j;}
int div(int i,int j){return i/j;}
int mod(int i,int j){return i%j;}
typedef struct cmd{
    char sym;
    int (* fun_t) (int,int);
}cal;
cal arr[] = {
    {'+',add},
    {'-',sub},
    {'*',mul},
    {'/',div},
    {'%',mod},
};
int main(int argc, const char *argv[])
{
    char symbol=0;
    int a,b;
    int i,result;
    funp calc;
    while(1)
    {
        puts("Enter a symbol('#' to Exit):");
        scanf("%c",&symbol);
        if(symbol=='#')
            break;
        puts("Enter a:");
        scanf("%d",&a);
        puts("Enter b:");
        scanf("%d",&b);
        for (i = 0;i < 5; i++)
        {
            if(arr[i].sym == symbol)
                result = arr[i].fun_t(a,b);
        }
        //switch(symbol)
        //{
        //case '+' : calc=add; break;
        //case '-' : calc=sub; break;
        //case '*' : calc=mul; break;
        //case '/' : calc=div; break;
        //case '%' : calc=mod; break;
        //}
        //result = (*calc)(a,b);
        getchar();
        printf("%d %c %d = %d\n",a,symbol,b,result);
    }
    puts("Exit!");
    return 0;
}
