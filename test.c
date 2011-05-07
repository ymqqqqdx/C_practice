#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    int i;
    char *mall = malloc(10);
    for(i = 0; i < 10; i++)
    {
        printf("%d\n", *(mall + i));
    }
    return 0;
}
