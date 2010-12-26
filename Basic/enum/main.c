#include <stdio.h>
#include <string.h>
enum week {
    Mon=0,Tue,Wen,Thu,Fri,Sat,Sun
};

int main(int argc, const char *argv[])
{
    enum week day;
    day = Sun;
    printf("%d\n",sizeof(day));
    printf("%d\n",day);
    return 0;
}
