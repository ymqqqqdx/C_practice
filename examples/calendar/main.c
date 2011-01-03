#include <stdio.h>
#include <stdlib.h>
int dat_table[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int dat_table_l[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int leap_year(int year)
{
    if((year % 400 == 0) ) return 1;
    if((year % 100) != 0 && (year % 4) == 0) return 1;
    return 0;
}
int day_of_beginning(int year,int month)
{
    int i,temp = 0;
    for(i = 0;i < month - 1;i++)
    {
        if(leap_year(year)) temp += dat_table_l[i];
        else temp += dat_table[i];
    }
    year = (year - 1)/4 + year - 2 + temp;
    return year % 7 + 1;
}
int main(int argc, const char *argv[])
{
    int year,i,j,k,t;
    int date[12][6][7];
    printf("Please input the year whose calendar you want to know:");
    scanf("%d",&year); getchar();
    for(i = 0;i < 12;i++)
        for(j = 0;j < 6;j++)
            for(k = 0;k < 7;k++)
                date[i][j][k] = 0;
    for(i = 0;i < 12;i++)
    {
        for(j = day_of_beginning(year,i + 1) - 1,k = 1;;)
        {
            date[i][j++/7][j%7] = k++;
            if(k - 1 == (leap_year(year) ? dat_table_l[i] : dat_table[i])) break;
        }
    }
    for(i = 0;i < 12;i++)
    {
        printf("                        *%d*                             \n",i+1);
        printf("MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN\t\n");
        for(j = 0;j < 6;j++)
        {
            for(k = 0;k < 7;k++)
                (t = date[i][j][k])?printf("%d\t",t):printf("%c\t",' ');
            puts("");
        }
    }
    return 0;
}
