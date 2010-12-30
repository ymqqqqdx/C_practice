#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void binary()
{
    unsigned int a,i,t = 0; 
    printf("Input a number:");
    scanf("%d",&a);
    getchar();
    printf("*******Result*******\n");
    for(i = 0;i < 32;i++)
    {
        if(!t)
            t = ((a<<i) & 0x80000000) == 0x80000000;
        if(t)
        printf("%d",((a<<i) & 0x80000000) == 0x80000000);
    }
    printf("\n********************\n");
}
void multi()
{
    unsigned int x,y,i,result = 0;
    printf("Please input x y: ");
    scanf("%d %d",&x,&y);
    getchar();
    for(i = 0;i < 32;i++)
    {
        if((y >> i) & 0x01)
            result += x << i;
    }
    printf("*******Result*******\n");
    printf("%d * %d = %d\n",x,y,result);
    printf("********************\n");
}
void exchange()
{
    char arr[100];
    char *p = arr;
st: printf("Please input a string:");
    scanf("%s",arr);
    getchar();
    if(!strlen(arr))
        goto st;
    while(*p)
    {
        *p < 'a' ? (*p += 32) : (*p -= 32);
        p++;
    }
    puts(arr);
}
void encry()
{
    char arr[80];
    printf("Please input a string:");
    scanf("%s",arr);
    getchar();
    char *p = arr;
    printf("After encrytion:\n");
    while(*p)
        printf("%c",*p++ ^ 0x02);
    putchar('\n');
}
int main(int argc, const char *argv[])
{
    char ch;
st:  printf("1.Decimal to binary\n2.x*y\n3.low or up exchange\n4.Encryption\n5.Exit\n");
re: fprintf(stdout, "Input your choice:");
    ch = getchar();
    if(ch != '\n') getchar();
    else goto re;
    if(ch == '1')
        binary();
    else if(ch == '2')
        multi();
    else if(ch == '3')
        exchange();
    else if(ch == '4')
        encry();
    else if(ch == '5' || ch == 'q')
        return 0;
    goto st;
    return 0;
}
