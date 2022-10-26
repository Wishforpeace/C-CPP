#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int Elemtype;

Status visit(Elemtype c)
{
    printf("%d ", c);
    return OK;
}

typedef struct Node
{
    Elemtype data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

//初始化链式线性表
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    if (!(*L))
    {
        return ERROR;
    }
    (*L)->next = NULL;

    return OK;
}

Status ListEmpty(LinkList L)
{
    if (L->next)
        return FALSE;
    else
        return TRUE;
}

Status DestroyList(LinkList *L)
{
    LinkList p;
    if (*L == NULL)
    {
        return ERROR;
    }
    while (*L)
    {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
    return OK;
}

Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

// 返回线性表长度
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, Elemtype *e)
{
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    *e = p->data;
    printf("eeeeee%d\n", *e);
    return OK;
}

int LocateElem(LinkList L, Elemtype e)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (p->data == e)
        {
            return i;
        }
        p = p->next;
    }
    return 0;
}

Status PriorElem(LinkList L, Elemtype cur_e, Elemtype *pre_e)
{
    LinkList p, q;
    //头节点指向空
    p = L;
    while (p->next)
    {
        q = p->next;
        if (q->data == cur_e)
        {
            break;
        }
        p = p->next;
    }
    *pre_e = p->data;
    return OK;
}

Status NextElem(LinkList L, Elemtype cur_e, Elemtype *next_e)
{
    LinkList p, q;
    p = L;
    while (p->next)
    {
        p = p->next;
        q = p->next;
        if (p->data == cur_e)
        {
            break;
        }
    }
    *next_e = q->data;
    return OK;
}

Status ListDelete(LinkList *L, int i, Elemtype *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

Status ListDeleteNode(LinkList *L, LinkList p)
{
    LinkList q;
    q = (*L)->next;
    while (q->next != p)
    {
        q = q->next;
    }
    q->next = p->next;
    free(p);
    return OK;
}

Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

//插入元素
Status ListInsert(LinkList *L, int i, Elemtype e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    // 如果找不到第i个元素
    if (!p || j > i)
    {
        return ERROR;
    }
    // 分配新节点，插入到最后
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListInsertNode(LinkList *L, Elemtype e)
{
    LinkList p, s;
    p = (*L)->next;
    s = (LinkList)malloc(sizeof(Node));
    if (s == NULL)
    {
        return FALSE;
    }
    s->data = e;
    s->next = p;
    (*L)->next = s;
    return OK
}

void PrintStatus(Status status, char s[])
{
    if (!status)
    {
        printf("%s failed\n", s);
    }
    else
    {
        printf("%s succeeded\n", s);
    }
}

// int main()
// {
//     LinkList L;
//     Elemtype e;
//     Status status;
//     int j, k;
//     int length;
//     status = InitList(&L);
//     PrintStatus(status, "InitList");
//     //随机插入
//     for (j = 1; j <= 5; j++)
//     {
//         status = ListInsert(&L, 1, j);
//         if (!status)
//         {
//             PrintStatus(status, "ListInsert");
//         }
//     }
//     PrintStatus(status, "ListInsert");
//     ListTraverse(L);

//     //获取线性表长度
//     length = ListLength(L);
//     printf("线性表长度为:%d\n", length);
//     //获取元素
//     status = GetElem(L, 3, &e);
//     PrintStatus(status, "GetElem");
//     printf("线性表第4个元素为%d\n", e);
//     //定位元素
//     int location;
//     location = LocateElem(L, 2);
//     printf("元素2的位置为:%d\n", location);
//     //前驱元素
//     PriorElem(L, 3, &e);
//     printf("元素3的前驱元素为:%d\n", e);
//     //后继元素
//     NextElem(L, 3, &e);
//     printf("元素3的后继元素为:%d\n", e);
//     //删除第四个元素
//     ListDelete(&L, 4, &e);
//     PrintStatus(status, "ListDelete");
//     printf("Succeeded deleting element %d\n", e);
//     ListTraverse(L);

//     //清空链表
//     status = ClearList(&L);
//     PrintStatus(status, "ClearList");
//     length = ListLength(L);
//     printf("线性表长度为:%d\n", length);
//     //销毁链表
//     status = DestroyList(&L);
//     PrintStatus(status,"DestroyList");
//     length = ListLength(L);
//     printf("线性表长度为:%d\n", length);
// }