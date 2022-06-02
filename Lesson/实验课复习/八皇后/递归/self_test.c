#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NUM 8
int chess[NUM] = {0};
void try(int i);
int place(int i, int j);
void printresult();
void try(int i)
{
    int j;
    for (j = 0; j < NUM; j++)
    {
        if (place(i, j) == 1)
        {
            chess[i] = j;
            if (i == NUM - 1)
            {
                printresult();
            }
            else
            {
                try(i + 1);
            }
        }
    }
}

int place(int i, int j)
{
    int k;
    for (k = 0; k < i; k++)
    {
        if(abs(chess[k]==j||abs(k-i)==abs(chess[k]-j)))
        {
            return 0;
        }
    }
    return 1;
}

void printresult()
{
    static int s=1;
    printf("*****第%d种结果*****",s++);
    int i;
    for(i=0;i<NUM;i++)
    {
        printf("第%d行的皇后放在第%d列\n",i+1,chess[i]+1);
    }
    printf("\n");
}

int main()
{
    try(0);
    return 0;
}