#include <stdio.h>
typedef struct Student
{
    int ID;
    int StudentID;
    char Name[20];
    int Score[2];
    struct Node *next;

} Student;

Status InitStudent(Student **stu, int num)
{
    *stu = (struct Student *)malloc(num * sizeof(Student));
    if (stu == NULL)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}

void PrintStatus(Status status, char *string)
{
    if (status)
    {
        printf("%s successeded\n", string);
    }
    else
    {
        printf("%s failed\n", string);
    }
}

void RadixSort(Student **stu, int num)
{
    int count[10];
    struct Student *tmp;
    InitStudent(&tmp, num);
    int i, j, m, k;
    int radix = 1;
    // 因为是两位数，所以进行两次排序
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            count[j] = 0;
        }
        //统计每个桶中的记录数
        for (j = 0; j < num; j++)
        {
            k = (*stu)[j].Score[radix];
            count[k]++;
        }
        // 将前面的count值加到后一位上
        for (j = 1; j < 10; j++)
        {
            count[j] = count[j - 1] + count[j];
        }
        for (j = num - 1; j >= 0; j--)
        {
            k = (*stu)[j].Score[radix];
            tmp[count[k] - 1] = (*stu)[j];
            count[k]--;
        }
        for (j = 0; j < num; j++)
        {
            (*stu)[j] = tmp[j];
        }
        radix--;
    }
}