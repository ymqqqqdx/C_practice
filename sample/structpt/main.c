#include <stdio.h>
struct inf{
    int seg1;
    char seg2;
    int seg3;
};
struct inf stu1;
int main(int argc, const char *argv[])
{
    struct inf *pt = &stu1;
    printf("%d\n",sizeof(pt));
    pt->seg1 = 23;
    printf("%d\n",pt->seg1);
    return 0;
}
