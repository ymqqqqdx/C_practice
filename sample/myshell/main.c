#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct aa{
    char * command;
    char * argument[10];
    char * in_file;
    char * out_file;
}shell;
char * strnchar(char *s,const char c,int n)
{
    int i = 0;
    while(*s++)
    {
        if(*s == c)
            if(n == ++i)
                return s;
    }
    return NULL;
}
void analyse(char *in,shell *shl)
{
    int i = 1;
    int k = 0;
    char *p;
    shl->command = strndup(in,(p = strnchar(in,' ',1)) - in);
    
    if(*(++p) != '-')
        shl->argument[k++] = strndup(p,strnchar(p,' ',1) -p);
    while(p = strnchar(in,'-',i++))
        shl->argument[i + k - 2] = strndup(p,strnchar(p,' ',1) - p);
    shl->argument[i++ - 2 + k] = NULL;
    if(p = strnchar(in,'<',1))
        shl->in_file = strndup(p,strnchar(p,' ',1) - ++p);
    else
        shl->in_file = NULL;
    if(p = strnchar(in,'>',1))
        shl->out_file = strndup(p,strnchar(p,' ',1) - ++p);
    else
        shl->out_file = NULL;
}
int main(int argc, const char *argv[])
{
    char arr[80];
    char *p;
    int i = 0;
    shell myshell;
    while(1)
    {
        i = 0;
        printf("mysh%% ");
        fgets(arr,80,stdin);
        if(!strcmp(arr,"exit\n"))
            return 0;
        analyse(arr,&myshell);
        printf("command:\t%s\n",myshell.command);
        free(myshell.command); myshell.command = NULL;
        while(p = myshell.argument[i++])
        {
            printf("argument%d:\t%s\n",i,p);
            free(p); p = NULL;
        }
        printf("in_file:\t%s\n",myshell.in_file ? myshell.in_file : "NULL");
        free(myshell.in_file); myshell.in_file = NULL;
        printf("out_file:\t%s\n",myshell.out_file ? myshell.out_file : "NULL");
        free(myshell.out_file); myshell.out_file = NULL;
    }
    return 0;
}
