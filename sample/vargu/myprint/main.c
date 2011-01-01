#include <stdio.h>
void myprint(char * format, ...)
{
    char **p = &format;
    puts(*++p);
    puts(*++p);
    puts(*++p);
}
int main(int argc, const char *argv[])
{
    myprint("","Hello world!","How are you?","How old are you?");
    return 0;
}
