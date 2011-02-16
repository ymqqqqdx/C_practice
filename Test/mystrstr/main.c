#include <stdio.h>
#include <string.h>

int mystrstr(char *src, char *fin, char *replace, char *store)
{
    int i, j;
    int count = 0, flag = 0;

    for(i = 0; i < strlen(src); i++)
    {
        for(j = 0; j < strlen(fin); j++)
        {
            if(*(fin + j) != *(src + i + j))
                break;
            if(j == strlen(fin) - 1)
            {
                count++;
                i += strlen(fin) - 1;
                strcat(store, replace);
                flag = 1;
            }
        }
        if(!flag)
            strncat(store, src + i, 1);
        flag = 0;
    }

    return count;
}

int main(int argc, const char *argv[])
{
    char haystack[100];
    char needle[100];
    char replace[100];
    char store[200] = {0};

    printf("%s\n", "Enter the haystack:");
    scanf("%s", haystack);
    printf("%s\n", "Enter the needle:");
    scanf("%s", needle);
    printf("%s\n", "Enter the string to replace:");
    scanf("%s", replace);
    printf("There are %d %s in %s\n",mystrstr(haystack, needle, replace, store), needle, haystack);
    printf("After replace:\n%s\n", store);
    return 0;
}
