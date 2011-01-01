#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    FILE *fp1,*fp2;
    char temp;
    char *pt = malloc(1024);
    fp1 = fopen("new.c","r");
    fp2 = fopen("www.c","w");
    //while((temp = fgetc(fp1)) != EOF)
    //fputc(temp,fp2);
    //while(1)
    //{
    //temp = fgetc(fp1);
    //if(feof(fp1))
    //break;
    //fputc(temp,fp2);
    //}
    while(1)
    {
        printf("%d",fread(pt,1,1,fp1));
        if(feof(fp1))
            break;
        fwrite(pt,1,1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
