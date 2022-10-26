#include <stdio.h>
#include <string.h>
#include "chain(带头结点).h"
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
    pa = La->next;
    pb = Lb->next;
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
            pl->next = s;
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            printf("%d\n", pb->data);
            s = (LinkList)malloc(sizeof(Node));
            s->data = pb->data;
            s->next = NULL;
            pl->next = s;
            pb = pb->next;
        }
        else if (pa->data == pb->data)
        {
            printf("%d\n", pa->data);
            s = (LinkList)malloc(sizeof(Node));
            s->data = pa->data;
            s->next = NULL;
            pl->next = s;
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
        pl->next = s;
        pl = pl->next;
        pa = pa->next;
    }

    while (pb != NULL)
    {

        s = (LinkList)malloc(sizeof(Node));
        s->data = pb->data;
        s->next = NULL;
        pl->next = s;
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
    pa = (*La)->next;
    pb = (*Lb)->next;
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
                pl->next = s;
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
    pa = La->next;
    pb = Lb->next;
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
    LinkList La, Lb, L, p, s;
    Elemtype e;
    Status status;
    status = InitList(&L);
    PrintStatus(status, "InitList");
    status = InitList(&La);
    PrintStatus(status, "InitList");
    status = InitList(&Lb);
    PrintStatus(status, "InitList");
    int num;
    printf("------------Input A------------\n");
    printf("num: ");
    scanf("%d", &num);
    printf("elem A = ");
    p = La;
    while (num--)
    {
        s = (LinkList)malloc(sizeof(Node));
        scanf("%d", &e);
        s->data = e;
        p->next = s;
        p = p->next;
    }
    ListTraverse(La);

    printf("------------Input B------------\n");
    printf("num: ");
    scanf("%d", &num);
    printf("elem B = ");
    p = Lb;
    while (num--)
    {
        s = (LinkList)malloc(sizeof(Node));
        scanf("%d", &e);
        s->data = e;
        p->next = s;
        p = p->next;
    }
    ListTraverse(Lb);
    status = Union(&L, La, Lb);
    ClearList(&L);
    status = Intersection(&L, &La, &Lb);
    ClearList(&L);
    printf("A-B:");
    status = Sub(&L, La, Lb);
    ClearList(&L);
    printf("B-A:");
    status = Sub(&L, Lb, La);
}