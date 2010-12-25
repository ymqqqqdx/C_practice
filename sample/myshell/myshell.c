#include <stdio.h>
#include <string.h>
typedef struct cmd
{
    char *command[10];
    char *in;
    char *out;
}cmd_t;
cmd_t g_command;
void parse(char *a)
{
    char *p = a;
    int i = 1;
    g_command.command[0] = p;
    while(*p++ == ' ')
        g_command.command[0] = p;
    while(*p)
    {
        if(*p==' ')
        {
            *(p++)=0;
            continue;
        }
        if(*p!=' ' &&*(p - 1) == '\0' && *p!='<' && *p!='>')
        {
             while(*++p == ' ');
             g_command.command[i++] = p;
        }
        if(*p=='>')
        {
             while(*++p == ' ');
             g_command.out = p;
        }
        if(*p=='<')
        {
             while(*++p == ' ');
             g_command.in = p;
        }
        p++;
    }
    g_command.command[i] = NULL;
}
int main(int argc, const char *argv[])
{
    int i = 1;
    char a[80];
    printf("mysh%% ");
    fgets(a,80,stdin);
    a[strlen(a) - 1] = 0;
    parse(a);
    printf("command:\t%s\n",g_command.command[0]);
    while(g_command.command[i])
        printf("argument%d:\t%s\n",i++,g_command.command[i]);
    if(g_command.in)  printf("infiles:\t%s\n",g_command.in);
    if(g_command.out) printf("outfiles:\t%s\n",g_command.out);
}

