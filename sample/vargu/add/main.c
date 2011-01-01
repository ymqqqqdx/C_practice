#include <stdio.h>
#include <stdarg.h>
void myprint(char * format, ...)
{
    char *p;
    va_list ap;
    va_start(ap,format);
    puts(va_arg(ap,char *));
    puts(va_arg(ap,char *));
    puts(va_arg(ap,char *));
    va_end(ap);
}
int addint(int count, ...)
{
    int result = 0;
    va_list ap;
    va_start(ap,count);
    while(count--)
        result += va_arg(ap,int);
    va_end(ap);
    return result;
}
int main(int argc, const char *argv[])
{
    myprint("","Hello world!","How are you?","How old are you?");
    printf("%d\n",addint(10,1,2,3,4,5,6,7,8,9,10));
    return 0;
}
