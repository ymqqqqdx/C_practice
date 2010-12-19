#include <stdio.h>
int addtwo(int,int);
int main(int argc, const char *argv[])
{
    int result;
    int (* fun1) (int,int);
    fun1 = addtwo;
    result = (*fun1)(3,5);
    printf("%d\n",result);
    return 0;
}

int addtwo(int i,int j)
{
    return i + j;
}
