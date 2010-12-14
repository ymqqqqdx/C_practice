#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
    for(j=strlen(buf),i=strlen(buf)-1;i>=0;i--)
    {
        if(judge(buf[i]))
        {
            for(k=0;k<(j-i-1);buf2[l++]=buf[i+k+++1]);
            buf2[l++]=buf[i];
            j=i;
        }
        if(i==0)
            for(k=0;k<j;buf2[l++]=buf[k++]);
    }
    printf("The Target String is:\n");
    puts(buf2);
    return 0;
}
int judge(char temp)
{
    if(isalpha(temp) || isdigit(temp))
        return 0;
    else
        return 1;
}
