#include <stdio.h>
typedef struct ss{
    int id;
    int chinese;
    char name[256];
}stu;
void swap(stu *a,stu *b)
{
    stu temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, const char *argv[])
{
    stu stu1={1,98,"ZhangSan"};
    stu stu2={2,87,"Lisi"};
    printf("%d\t%d\t%s\n",stu1.id,stu1.chinese,stu1.name);
    printf("%d\t%d\t%s\n",stu2.id,stu2.chinese,stu2.name);
    swap(&stu1,&stu2);
    printf("%d\t%d\t%s\n",stu1.id,stu1.chinese,stu1.name);
    printf("%d\t%d\t%s\n",stu2.id,stu2.chinese,stu2.name);
    return 0;
}
