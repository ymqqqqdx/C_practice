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
FILE *fp1;
int id,chinese,math,english;float aver;
char name[80];
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
    fprintf(stdout, "ID\tName%-11sChinese\tMath\tEnglish\tAverage\n-------------------------------------------------------\n","");
    FILE *fp1 = fopen("database.txt","w");
    while(p)
    {
        fprintf(stdout, "%d\t%-15s\t%d\t%d\t%d\t%.1f\t\n",p->id,p->name,p->chinese,p->math,p->english,p->aver);
        fprintf(fp1, "%d %s %d %d %d %.1f\n",p->id,p->name,p->chinese,p->math,p->english,p->aver);
        p = p->next;
    }
    fclose(fp1);
}
int delete(student *p)
{
    student *temp = p;
    char ch;
st: fprintf(stdout, "************Menu*************\nPlease choose the way:\n1.Delete by ID.\n2.Delete by name\n3.Exit\n*****************************\n");
re: fprintf(stdout, "Input your choice:");
    ch = getchar();
    if(ch != '\n')
        getchar();
    else goto re;
    if(ch == '1')
    {
        fprintf(stdout, "Input the ID:");
        scanf("%d",&id);getchar();
        while(p)
        {
            temp = p;
            p = p->next;
            if(p)
            {
                if(p->id == id)
                {
                    temp->next = p->next;
                    return 0;
                }
            }
        }
    }
    else if(ch == '2')
    {
        fprintf(stdout, "Input the name:");
        scanf("%s",name);getchar();
        while(p)
        {
            temp = p;
            p = p->next;
            if(p)
            {
                if(!strcmp(p->name,name))
                {
                    temp->next = p->next;
                    return 0;
                }
            }
        }
    }
    else if(ch == '3')
        return 1;
    fprintf(stdout, "**************error****************\nNo match item! Try again.\n***********************************\n");
    goto st;
    return 1;
}
void insert(student *head,student *p)
{
st: fprintf(stdout, "Please input the new info(ID name chinese math english average)\n");
    scanf("%d %s %d %d %d %f",&id,name,&chinese,&math,&english,&aver);
    getchar();
    while(head)
    {
        if(head->id == id)
        {
            fprintf(stderr, "**************error***************\nID %d already exists!Try again!\n**********************************\n",id);
            goto st;
        }
        head = head->next;
    }
    p = create(p,id,name,chinese,math,english,aver);
}
student* str_copy(student *org,student *tar)
{
    tar->id = org->id;
    tar->chinese = org->chinese;
    tar->math = org->math;
    tar->english = org->english;
    tar->aver = org->aver;
    strcpy(tar->name,org->name);
}
student * sort(student *lp)
{
    student *head,*tail,*temp;
    student *p,*t;
    char ch;
    fprintf(stdout, "***********Menu************\nPlease choose the way:\n1.Sort by ID\n2.Sort by Average\n***************************\n");
re: fprintf(stdout, "Input your choice:");
    ch = getchar();
    if(ch != '\n')
        getchar();
    else goto re;
    head = malloc(sizeof(student));
    tail = malloc(sizeof(student));
    str_copy(lp,head);
    lp = lp->next;
    if((ch == '1')?lp->id >= head->id:lp->aver >= head->aver)
        str_copy(lp,tail);
    else
    {
        str_copy(head,tail);
        str_copy(lp,head);
    }
    head->next = tail;
    while(lp)
    {
        lp = lp->next;
            if(!lp) break;
        temp = malloc(sizeof(student));
        str_copy(lp,temp);
        if((ch == '1')?lp->id >= tail->id:lp->aver >= tail->aver)
        {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
        else if((ch == '1')?lp->id <= head->id:lp->aver <= head->aver)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            p = head;
            while(p)
            {
                t = p;
                p = p->next;
                if(!p) break;
                if(((ch == '1')?lp->id >= t->id:lp->aver >= t->aver) && ((ch == '1')?lp->id <= p->id:lp->aver <= p->aver))
                {
                    t->next = temp;
                    temp->next = p;
                    break;
                }
            }
        }
    }
    return head;
}
int main(int argc, const char *argv[])
{
    if(!(fp1 = fopen("database.txt","r")))
    {
        fprintf(stderr, "file open error\n");
        exit(1);
    }
    int i = 1;
    char ch;
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
    fclose(fp1);
start:    fprintf(stdout, "*************Main Menu***************\nPlease select the option:\n1.Display all students' info\n2.Sort by average or ID\n3.Insert a new info\n4.Delete a record\n5.Quit\n*************************************\n");
re: fprintf(stdout, "Input your choice:");
    ch = getchar();
    if(ch != '\n')
        getchar();
    else goto re;
    if(ch == '1')
        travel(head);
    else if(ch == '3')
    {
        insert(head,p);
        travel(head);
    }
    else if(ch == '2')
        travel(sort(head));
    else if(ch == '4')
    {
        if(!delete(head))
            travel(head);
    }
    else if(ch == '5' || ch == 'q')
        return 0;
    goto start;
    return 0;
}
