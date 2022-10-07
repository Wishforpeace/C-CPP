#include <stdio.h>

int main()
{
    int x = 0;
    int i, j;
    for (i = 1; i < 6; i++)
    {
        for (j = 1; j <= 6 - i; j++)
        {
            x++;
        }      
    }
    printf("%d\n", x);
}