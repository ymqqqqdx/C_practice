#include <stdio.h>
#include <string.h>
char name2[][15] = {"123","456","789","000"};
int main(int argc, const char *argv[])
{
    char temp;
    char *name[] = {"legal month","Jan","Feb","Mar"};
    printf("name2 = 0x%p\n",name2);
    printf("name2[1] = 0x%p\n",name2[1]);
    printf("name = 0x%p\n",name);
    printf("name = %s\n",name[0]);
    getchar();
    return 0;
}
