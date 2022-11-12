#include <stdio.h>

void SpiralSort(int a[5][5], int row, int column)
{
   //......insert your code
}
int main()
{
    int a[5][5] = {
        {11, 18, 17, 4, 24},
        {10, 1, 16, 5, 20},
        {6, 9, 12, 15, 25},
        {2, 8, 3, 7, 21},
        {14, 13, 19, 22, 23},
    };
    SpiralSort(a, 5, 5);

    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
