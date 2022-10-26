#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "radix_sort.h"
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

int main()
{

    int num;
    int score;
    Status status;
    int StudentID;
    char Name[20];
    int Score[2];
    printf("请输入学生人数：");
    scanf("%d", &num);
    struct Student *student;
    status = InitStudent(&student, num);
    PrintStatus(status, "Init List");
    int i, j;
    for (i = 0; i < num; i++)
    {
        student[i].ID = i + 1;
        printf("请输入第%d个学生的学号:", i + 1);
        scanf("%d", &student[i].StudentID);
        printf("请输入第%d个学生的姓名:", i + 1);
        scanf("%s", student[i].Name);
        printf("请输入第%d个学生的成绩:", i + 1);
        scanf("%d", &score);
        for (j = 1; j >= 0; j--)
        {
            student[i].Score[j] = score % 10;
            score = score / 10;
        }
        printf("\n");
    }

    RadixSort(&student, num);
    printf("名次\t学号\t姓名\t成绩\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\t", i + 1);
        printf("%d\t", student[num - i - 1].StudentID);
        printf("%s\t", student[num - i - 1].Name);
        for (j = 0; j < 2; j++)
        {
            printf("%d", student[num - i - 1].Score[j]);
        }
        printf("\n");
    }
}