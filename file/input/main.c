#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
typedef struct stu{
    int id;
    char name[80];
    int chinese;
    int math;
    int english;
    float aver;
    struct stu *next;
}student;
student *create(student *pro,int id,char *name,int chinese,int math,int english,float average)
{
    student *p = malloc(sizeof(student));
    p->id = id;
    strcpy(p->name,name);
    p->chinese = chinese;
    p->math = math;
    p->english = english;
    p->aver = average;
    p->next = NULL;    
    if(pro) pro->next = p;
    return p;
}
void travel(student *head)
{
    student *p = head;
    fprintf(stdout, "Name%-11sID\tChinese\tMath\tEnglish\tAverage\n","");
    while(p)
    {
        fprintf(stdout, "%-15s\t%d\t%d\t%d\t%d\t%.1f\t\n",p->name,p->id,p->chinese,p->math,p->english,p->aver);
        p = p->next;
    }
}
int main(int argc, const char *argv[])
{
    FILE *fp1;
    if(!(fp1 = fopen("database.txt","r")))
    {
        fprintf(stderr, "file open error\n");
        exit(1);
    }
    char name[80];
    int i = 1,id,chinese,math,english;float aver;
    student *head = NULL,*p = malloc(sizeof(student));
    fscanf(fp1,"%d %s %d %d %d %f\n",&id,name,&chinese,&math,&english,&aver);
    aver = (float)(chinese + math + english)/3;
    head = create(head,id,name,chinese,math,english,aver);
    while(!feof(fp1))
    {
        fscanf(fp1,"%d %s %d %d %d %f\n",&id,name,&chinese,&math,&english,&aver);
        aver = (float)(chinese + math + english)/3;
        p = create((i++-1)?p:head,id,name,chinese,math,english,aver);
    }
    travel(head);
    fclose(fp1);
    return 0;
}
