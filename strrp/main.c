#include <stdio.h>
#include <string.h>
int judge(char);
int main(int argc, const char *argv[])
{
    int i=0;
    int j=0,k=0,l=0;
    char buf[200]={0};
    char buf2[200]={0};
    printf("Enter a string:\n");
    gets(buf);
    printf("The Original String is:\n");
    puts(buf);
    for(i=j=strlen(buf)-1;i>=0;i--)
    {
        if(judge(buf[i]))
        {
            for(k=0;j==(strlen(buf)-1)?k<(j-i):k<(j-i-1);k++)
                buf2[l++]=buf[i+k+1];
            buf2[l++]=buf[i];
            j=i;
        }
        if(i==0)
        {
            for(k=0;k<j;k++)
                buf2[l++]=buf[k];
        }
    }
    printf("The Target String is:\n");
    puts(buf2);
    return 0;
}
int judge(char temp)
{
    if((temp>='0' && temp<='9') || (temp>='A' && temp<='Z') || (temp>='a' && temp<='z'))
        return 0;
    else
        return 1;
}
