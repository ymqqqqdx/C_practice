#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ml(char **x)
{
    *x = malloc(100);
}
int main(int argc, const char *argv[])
{
    char *p;
    ml(&p);
    strcpy(p,"Hello world!");
    puts(p);
    return 0;
}
