#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** 
* @brief copy file1 to file2
* 
* @param argc
* @param argv[] command file1 file2
* 
* @return 
*/
int main(int argc, const char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "intput:<%s> src_file dest_file\n",argv[0]);
        exit(1);
    }
    FILE *fp1,*fp2;
    if(!(fp1 = fopen(argv[1],"r")))
    {
        fprintf(stderr, "open file %s:%s\n",argv[1],strerror(errno));
        exit(1);
    }
    if(!(fp2 = fopen(argv[2],"w")))
    {
        fprintf(stderr, "open file %s:%s\n",argv[2],strerror(errno));
        exit(1);
    }
    char buff[1024];
    while(fgets(buff,1024,fp1))
    {
        fputs(buff,stdout);
        fputs(buff,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;

}
