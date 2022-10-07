#include <stdio.h>
// #include<iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/malloc.h>
// using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define INITSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int size;
} SqlList;

typedef int Status;

extern Status InitList(SqlList *L)
{
    L->elem = (int *)malloc(INITSIZE * sizeof(int));
    L->length = 0;
    L->size = INITSIZE;
    return OK;
}

Status DestroyList(SqlList *L)
{
    free(L->elem);
    return OK;
}

Status ClearList(SqlList *L)
{
    memset(L->elem, 0, INITSIZE);
    L->length = 0;
    return OK;
}

Status ListEmpty(SqlList *L)
{
    if (L->length == 0)
    {
        return TRUE;
    }
    return FALSE;
}

int ListLength(SqlList *L)
{
    return L->length;
}

Status GetElem(SqlList *L, int i, ElemType *e)
{
    if (ListEmpty(L) || i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->elem[i - 1];
    return OK;
}

// 定位元素位置
int LocateElem(SqlList *L, ElemType e)
{
    int i = 0;
    if (L->length == 0)
    {
        return 0;
    }
    for (i = 0; i < L->length; i++)
    {
        if (L->elem[i] == e)
        {
            break;
        }
    }
    if (i >= L->length)
    {
        return 0;
    }
    return i + 1;
}

//返回元素前驱
Status PriorElem(SqlList *L, ElemType cur_e, ElemType *pre_e)
{
    int i = 0;
    for (i = 0; i < L->length; i++)
    {
        if (L->elem[i] == cur_e)
        {
            break;
        }
    }
    if (i == 0)
    {
        return ERROR;
    }
    if (i >= L->length)
    {
        return ERROR;
    }
    *pre_e = L->elem[i - 1];

    return OK;
}

//返回元素后继
Status NextElem(SqlList *L, ElemType cur_e, ElemType *next_e)
{
    int i = 0;
    for (i = 0; i < L->length; i++)
    {
        if (L->elem[i] == cur_e)
        {
            break;
        }
    }
    if (i == (L->length - 1))
    {
        return ERROR;
    }
    if (i >= L->length)
    {
        return ERROR;
    }
    *next_e = L->elem[i + 1];

    return OK;
}

//插入元素
Status ListInsert(SqlList *L, int i, ElemType e)
{
    // printf("e:%d\n",e);
    int k;
    // 线性表已满
    if (L->length == INITSIZE)
    {
        
        return ERROR;
    }

    // 插入位置小于0或大于length
    if (i < 1 || i > L->length + 1)
    {
       
        return ERROR;
    }
    // 插入数据不在表尾
    if (i <= L->length)
    {
        for (k = L->length - 1; k >= i-1; k--)
        {
            L->elem[k + 1] = L->elem[k];
        }
    }
    L->elem[i - 1] = e;
    L->length += 1;
    
    return OK;
}

//删除元素
Status ListDelete(SqlList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->elem[i - 1];
    if (i < L->length)
    {   
        // printf("%d\n",L->elem[i]);
        for (k = i; k < L->length; k++)
        {
            L->elem[k - 1] = L->elem[k];
        }
    }
    L->length--;
    return OK;
}

void ListTraverse(SqlList *L)
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

//打印操作结果
void PrintStatus(Status status, char string[])
{
    if (!status)
    {
        printf("%s failed\n", string);
    }
    else
    {
        printf("%s succeeded\n", string);
    }
}

// int main()
// {
//     Status status;
//     SqlList L;
//     ElemType e;
//     status = InitList(&L);
//     PrintStatus(status, "Init");
//     int i;
//     for (i = 1; i <= 10; i++)
//     {
//         status = ListInsert(&L, 1, i);
//         if (!status)
//         {
//             break;
//         }
//     }

//     PrintStatus(status, "Insert");

//     status = GetElem(&L,1,&e);
//     PrintStatus(status,"GetElem");
//     printf("elem %d\n",e);
//     ListTraverse(&L);
    
//     int length ;
//     length= ListLength(&L);
//     printf("长度为%d\n",length);

  
//     status = ListDelete(&L,5,&e);
//     printf("删除第5个元素%d\n",e);
//     PrintStatus(status,"Delete");
//     length = ListLength(&L);
//     printf("长度为%d\n",length);
//     ListTraverse(&L);

//     int location;
//     e = 6;
//     location = LocateElem(&L,e);
//     printf("元素6位于第%d个\n",location);

//     status = ListInsert(&L,2,15);
//     printf("在第二个位置插入15\n");
//     PrintStatus(status,"Insert");
//     ListTraverse(&L);

//     int pre,next;
//     pre = PriorElem(&L,4,&e);
//     printf("元素4之前的数为%d\n",e);

//     next = NextElem(&L,8,&e);
//     printf("元素8之后的数为%d\n",e);

//     status = DestroyList(&L);
//     PrintStatus(status, "Destroy");

//     status = ClearList(&L);
//     PrintStatus(status, "Clear");
// }