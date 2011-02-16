#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int guess(void)
{
    int issued[10] = {0};    
    int count = 0;
    char goon;
    int temp = 0;
    int key[4];
    int ans[4];
    int AT = 0, BT = 0;
    int i, j;
    int Timer = 0;
    srand((unsigned)time(NULL));
    while(count != 4)
    {
        temp = rand() % 10;
        if(!issued[temp])
        {
            key[count] = temp;
            //printf("%d\n",key[count]);
            issued[temp] = 1;
            count++;
        }
    }
    while(AT != 4)
    {
        AT = 0; BT = 0;
start:  printf("Please Enter four numbers:\n");
        scanf("%d,%d,%d,%d", &ans[0], &ans[1], &ans[2], &ans[3]);
        getchar();
        if(!(ans[0] - ans[1]) || !(ans[0] - ans[2]) || !(ans[0] - ans[3]) || !(ans[1] - ans[2]) || !(ans[1] - ans[3]) || !(ans[2] - ans[3]) || ans[0] > 9 || ans[1] > 9 || ans[2] > 9 || ans[3] > 9)
        {
            printf("Input error,please retry!\n");
            goto start;
        }
        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < 4; j++)
            {
                if(ans[i] == key[j])
                {
                    if(i == j)
                        AT++;
                    else
                        BT++;
                }
            }
        }
        printf("Result:\n%dA\t%dB\n", AT, BT);
        Timer++;
        if(Timer % 10 == 0)
        {
            printf("You have tried %d time..........Continue?(n to check answer,other to continue):", Timer);
            goon = getchar();
            if(goon == 'n')
            {
                printf("The key is:\n");
                for(i = 0; i < 4; i++)
                    printf("%d\t", key[i]);
                printf("\n");
                return 0;
            }
        }
    }
    printf("Congratulations!!\n");
    return 0;

}
int main(int argc, const char *argv[])
{
    guess();    
    return 0;
}
