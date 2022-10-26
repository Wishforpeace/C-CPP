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
    *L = NULL;
    return OK;
}

Status ListEmpty(LinkList L)
{
    if (L)
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

// 返回线性表长度
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L;
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
    p = L;
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
    printf("%d\n", *e);
    return OK;
}

int LocateElem(LinkList L, Elemtype e)
{
    int i = 0;
    LinkList p = L;
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
    q = (*L);
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
    LinkList p = L;
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
    int length = ListLength(*L);
    if (i < 1 || (length != 0 && i > length))
    { //若i不合法，返回false
        return FALSE;
    }
    if (i == 1)
    { //插入第一个结点的操作与其它结点不同
        LinkList s;
        s = (LinkList)malloc(sizeof(Node));
        s->data = e;
        s->next = *L;
        *L = s;
        return TRUE;
    }
    int j;
    j = 0;
    LinkList p;
    p = (*L);
    while (j < i)
    {
        p = p->next;
        j++;
    }
    LinkList s, q;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListInsertNode(LinkList *L, Elemtype e)
{
    LinkList p, q, s;
    p = (*L)->next;
    s = (LinkList)malloc(sizeof(Node));
    if (s == NULL)
    {
        return FALSE;
    }
    s->data = e;
    s->next = p;
    (*L)->next = s;
    return OK;
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
//     ListTraverse(L);
//     PrintStatus(status, "InitList");
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
//     ListInsert(&L, 2, 3);
//     ListTraverse(L);
//     ListDelete(&L, 3, &e);
//     ListTraverse(L);
//     status = ClearList(&L);
//     PrintStatus(status, "Clear");
// }