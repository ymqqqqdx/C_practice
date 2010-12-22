#include <stdio.h>
#define N 100
#define M 3
int head=N;
int tail=0;
struct people{
  int ID;
  char out;
}arr[N];
void tailhead()
{
   int k;
   for(k=N-1;k>=0;k--)
   {
        if(!arr[k].out)
        {
            tail=k+1;
            break;
        }
   }
   for(k=0;k<N;k++)
   {
        if(!arr[k].out)
        {
            head=k;
            break;
        }
   }
}
int main(int argc, const char *argv[])
{
    int i,j,k;
    int count=0;
    int temp=0;
    for(i=0;i<N;i++,arr[i].ID=i,arr[i].out=0);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;)
        {
           tailhead();
           while(arr[temp++].out)
           {
                tailhead();
                if(temp==tail)
                    temp=head;
           }
            if(temp==tail)
            {
                j++;
                if(j==M)
                    break;
                temp=head;
                continue;
            }
           j++;
        }
        arr[temp-1].out=1;
        printf("%3d: %3d out%c",count,temp,++count%5==0?'\n':'\t');
        if(temp==tail)
            temp=head;
    }
    return 0;
}
