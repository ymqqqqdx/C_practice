#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define EMPTY  80
void random_poker(void)
{
    int issued[54] = {0};
    int count = 0;
    int timer = 0;
    int temp = 0;
    int i = 0, j = 0;
    int card[4][14];
    char suit[5][20] = {"Heart", "Spade", "Club", "Diamond", "King"};

    for(i = 0; i < 4; i++)
        for(j = 0; j < 14; j++)
            card[i][j] = EMPTY;

    srand((unsigned)time(NULL));
    while(count != 54)
    {
        temp = rand() % 54;
        timer++;
        if(!issued[temp])
        {
            card[count % 4][count / 4] = temp;
            issued[temp] = 1;
            count++;
        }
        if(timer == 1000)
        {
            srand((unsigned)time(NULL));
            timer = 0;
        }
    }

    for(i = 0; i < 4; i++)
    {
        printf("\nPlayer%d:\n\n", i + 1);
        for(j = 0; j < 14; j++)
        {
            if(card[i][j] == EMPTY)
            {
                printf("\n");
                continue;
            }
            printf("%7s %d%c", suit[card[i][j] / 13], card[i][j] % 13 + 1, (j + 1) % 7 ? '\t' : '\n');
        }
    }
}
int main(int argc, const char *argv[])
{
    random_poker();    
    return 0;
}
