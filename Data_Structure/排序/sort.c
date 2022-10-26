#include <stdio.h>
void InsertSort(int *a, int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (tmp < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = tmp;
    }
}
void ShellSort(int *a, int length)
{
    int i, j, tmp, h;
    // h是间隔长度
    for (h = length / 2; h > 0; h /= 2)
    {
        for (i = h; i < length; i++)
        {
            tmp = a[i];
            for (j = i - h; j >= 0; j -= h)
            {
                if (tmp < a[j])
                {
                    a[j + h] = a[j];
                }
                else
                {
                    break;
                }
            }
            a[j + h] = tmp;
        }
    }
}

void QuickSort(int *a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int x = start;
    int y = end;
    int base = a[start];
    while (x < y)
    {
        while (a[y] > base && x < y)
        {
            y--;
        }
        if (x < y)
        {
            a[x++] = a[y];
        }
        while (a[x] < base && x < y)
        {
            x++;
        }
        if (x < y)
        {
            a[y--] = a[x];
        }
    }
    a[x] = base;
    QuickSort(a, start, x - 1);
    QuickSort(a, x + 1, end);
}

void PrintArray(int *a, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int array[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    int len = sizeof(array) / sizeof(array[0]);
    printf("Original:\n");
    PrintArray(array, len);
    InsertSort(array, len);
    printf("InsertSort:\n");
    PrintArray(array, len);
    printf("ShellSort:\n");
    ShellSort(array, len);
    PrintArray(array, len);
    printf("QuickSort:\n");
    QuickSort(array, 0, len - 1);
    PrintArray(array, len);
}