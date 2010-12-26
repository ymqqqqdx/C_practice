#include <stdio.h>
#include <string.h>
void print_1(){puts("*");}
void print_2(){puts("#");}
struct stu_t{
    char name[100];
    int id;
    int chinese;
    void (*funp_t)(void);
};
int main(int argc, const char *argv[])
{
   struct stu_t arr[5];
   int i;
   for(i=0;i<5;i++)
   {
        printf("Enter name of No.%d\n",i+1);
        arr[i].id = i+1;
        scanf("%s",arr[i].name);
        printf("Enter the performance of Chinese of No.%d\n",i+1);
        scanf("%d",&arr[i].chinese);
        if(arr[i].chinese>=80)
            arr[i].funp_t=print_1;
        else
            arr[i].funp_t=print_2;
   }
   printf("Name\t\tID\t\tChinese\t\tLevel\n");
   for(i=0;i<5;i++)
   {
        printf("%s\t\t%d\t\t%d\t\t",arr[i].name,arr[i].id,arr[i].chinese);
        arr[i].funp_t();
   }
   return 0;
}
