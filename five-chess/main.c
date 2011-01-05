#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0,j = 0;
    for(j = 0;j < 30;j++)
        printf("%c%c",'_','_');
    printf("%c%c",'\n','|');
    for (i = 0; i < 20; i++) 
    {
        for(j = 0;j < 20;j++)
            printf("%c%c%c",'_','_','|');
        printf("\n%c",'|');
    }
    return 0;
}
