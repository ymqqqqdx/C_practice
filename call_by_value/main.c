#include <stdio.h>
void set_to_zero_pt(int *);
void set_to_zero(int);
int main(int argc, const char *argv[])
{
    int i;
    i = 1;
    set_to_zero(i);
    printf("%d\n",i);
    set_to_zero_pt(&i);
    printf("%d\n",i);
    return 0;
}
void set_to_zero_pt(int *k)
{
    *k = 0;
}
void set_to_zero(int k)
{
    k = 0;
}
