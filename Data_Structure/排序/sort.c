#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/malloc.h>
void PrintArray(int *a, int len);
int Partition(int *a, int low, int high);
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 插入排序
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
// 希尔排序
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

// 快速排序
void QuickSort1(int *a, int start, int end)
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
    QuickSort1(a, start, x - 1);
    QuickSort1(a, x + 1, end);
}

void QuickSort2(int *a, int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(a, low, high);
        QuickSort2(a, low, pivotpos - 1);
        QuickSort2(a, pivotpos + 1, high);
    }
}

int Partition(int *a, int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
        {
            high--;
        }
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    // PrintArray(a, 10);
    return low;
}
// 冒泡排序

void BubbleSort(int *a, int len)
{
    // PrintArray(a, len);
    int i, j, tmp;
    int flag;
    // i是a[j]的最终定位，先确定第0个，然后再+1
    for (i = 0; i < len - 1; i++)
    {
        flag = 0;
        for (j = len - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
                flag = 1;
            }
        }
        // PrintArray(a, len);
        if (!flag)
        {
            return;
        }
    }
}

void SelectSort(int *a, int len)
{
    int i, j;
    int min;
    int tmp;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
        // PrintArray(a, len);
    }
}

// int *b = (int *)malloc(sizeof(int) * 11);
void Merge(int *a, int low, int mid, int high)
{
}
void MergeSort(int *a, int low, int high, int len)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, (low + high + 1) / 2, len);
        MergeSort(a, mid + 1, high, len);
    }
}

// 堆排序
void Heapify(int *a, int len, int i)
{
    // 记录根结点
    int largest = i;
    // 根据树在顺序表中的存储，找到左右孩子
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;
    if (lson < len && a[largest] < a[lson])
        largest = lson;
    if (rson < len && a[largest] < a[rson])
        largest = rson;
    // 如果最大值不是根结点，进行交换
    if (largest != i)
    {
        Swap(&a[largest], &a[i]);
        Heapify(a, len, largest); // 递归调用，维护交换过的位置
    }
}

void HeapSort(int *a, int len)
{
    // 建堆
    int i;
    for (i = len / 2 - 1; i >= 0; i--)
    {
        Heapify(a, len, i);
    }

    // 排序
    for (i = len - 1; i > 0; i--)
    {
        Swap(&a[0], &a[i]);
        Heapify(a, i, 0);
    }
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
    int array1[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    int len = sizeof(array1) / sizeof(array1[0]);
    printf("Original:\n");
    PrintArray(array1, len);

    int array2[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("InsertSort:\n");
    InsertSort(array2, len);
    PrintArray(array2, len);

    int array3[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("ShellSort:\n");
    ShellSort(array3, len);
    PrintArray(array3, len);

    int array4[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("QuickSort1:\n");
    QuickSort1(array4, 0, len - 1);
    PrintArray(array4, len);

    int array5[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("QuickSort2:\n");
    QuickSort2(array5, 0, len - 1);
    PrintArray(array5, len);

    int array6[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("BubbleSort:\n");
    BubbleSort(array6, len);
    PrintArray(array6, len);

    int array7[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("SelectSort:\n");
    SelectSort(array7, len);
    PrintArray(array7, len);

    int array8[10] = {9, 5, 3, 1, 4, 7, 8, 0, 2, 6};
    printf("HeapSort:\n");
    HeapSort(array8, len);
    PrintArray(array8, len);
}