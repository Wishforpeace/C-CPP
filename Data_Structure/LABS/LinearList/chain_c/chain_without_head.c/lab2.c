#include <stdio.h>
#include <string.h>
#include "chain.h"
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
Status Union(LinkList *L, LinkList La, LinkList Lb)
{
    int len_a, len_b;
    len_a = ListLength(La);
    len_b = ListLength(Lb);
    LinkList pa, qa, pb, qb, pl, s;
    pa = La;
    pb = Lb;
    pl = (*L);
    // printf("%d %d\n", pa->data, pb->data);
    printf("la:%d  lb:%d\n", len_a, len_b);
    while (pa != NULL && pb != NULL)
    {
        printf("%d  %d\n", pa->data, pb->data);
        if (pa->data < pb->data)
        {
            printf("%d\n", pa->data);
            s = (LinkList)malloc(sizeof(Node));
            s->data = pa->data;
            s->next = NULL;
            pl = s;
            pl = pl->next;
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            printf("%d\n", pb->data);
            s = (LinkList)malloc(sizeof(Node));
            s->data = pb->data;
            s->next = NULL;
            pl = s;
            pb = pb->next;
        }
        else if (pa->data == pb->data)
        {
            printf("%d\n", pa->data);
            s = (LinkList)malloc(sizeof(Node));
            s->data = pa->data;
            s->next = NULL;
            pl = s;
            pl = pl->next;
            pa = pa->next;
            pb = pb->next;
        }
        pl = pl->next;
    }

    while (pa != NULL)
    {
        printf("%d\n", pa->data);
        s = (LinkList)malloc(sizeof(Node));
        s->data = pa->data;
        s->next = NULL;
        pl = s;
        pl = pl->next;
        pa = pa->next;
    }

    while (pb != NULL)
    {

        s = (LinkList)malloc(sizeof(Node));
        s->data = pb->data;
        s->next = NULL;
        pl = s;
        pl = pl->next;
        pb = pb->next;
    }

    printf("并集:");
    ListTraverse(*L);
    return OK;
}
Status Intersection(LinkList *L, LinkList *La, LinkList *Lb)
{
    LinkList pa, pb, pl, s;
    pa = (*La);
    pb = (*Lb);
    pl = (*L);
    while (pa != NULL)
    {
        while (pb != NULL)
        {
            if (pa->data == pb->data)
            {
                s = (LinkList)malloc(sizeof(Node));
                s->data = pa->data;
                s->next = NULL;
                pl = s;
                pl = pl->next;
            }
            pb = pb->next;
        }
        pa = pa->next;
        pb = (*Lb)->next;
    }
    printf("交集:");
    ListTraverse(*L);
    return OK;
}

Status Sub(LinkList *L, LinkList La, LinkList Lb)
{
    LinkList pl, pa, pb, s;
    pa = La;
    pb = Lb;
    pl = (*L);
    int flag;
    while (pa != NULL)
    {
        flag = 0;
        while (pb != NULL)
        {
            if (pa->data == pb->data)
            {
                flag = 1;
            }
            pb = pb->next;
        }
        if (flag == 0)
        {
            s = (LinkList)malloc(sizeof(Node));
            s->data = pa->data;
            s->next = NULL;
            pl->next = s;
            pl = pl->next;
        }
        pa = pa->next;
        pb = Lb->next;
    }
    ListTraverse(*L);
    return OK;
}
int main()
{
    LinkList La, Lb, L, pa, pb, p, s;
    int i, j;
    Elemtype e;
    Status status;
    status = InitList(&L);
    PrintStatus(status, "InitList");
    status = InitList(&La);
    PrintStatus(status, "InitList");
    status = InitList(&Lb);
    PrintStatus(status, "InitList");
    int num, tmp;
    printf("------------Input A------------\n");
    printf("num: ");
    scanf("%d", &num);
    tmp = num;
    pa = La;
    printf("elem A = ");
    while (tmp--)
    {
        scanf("%d", &e);
        if (tmp == num - 1)
        {
            s = (LinkList)malloc(sizeof(Node));
            s->next = pa;
            s->data = e;
            pa = s;
        }
        else
        {
            s = (LinkList)malloc(sizeof(Node));
            s->data = e;
            s->next = NULL;
            pa->next = s;
            pa = pa->next;
        }
    }

    ListTraverse(La);
    printf("------------Input B------------\n");
    printf("num: ");
    scanf("%d", &num);
    printf("elem B = ");
    i = 1;
    while (i <= num)
    {
        scanf("%d", &e);
        ListInsert(&Lb, i, e);
        i++;
    }
    ListTraverse(Lb);
    // status = Union(&L, La, Lb);
    // ClearList(&L);
    // status = Intersection(&L, &La, &Lb);
    // ClearList(&L);
    // printf("A-B:");
    // status = Sub(&L, La, Lb);
    // ClearList(&L);
    // printf("B-A:");
    // status = Sub(&L, Lb, La);
}