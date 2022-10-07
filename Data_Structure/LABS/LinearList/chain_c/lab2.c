#include <stdio.h>
#include "chain(带头结点).h"
Status Union(LinkList L, LinkList La, LinkList Lb)
{
    int len_a, len_b;
    len_a = ListLength(La);
    len_b = ListLength(Lb);
    LinkList pa, qa, pb, qb;
    pa = La->next;
    pb = Lb->next;
    // printf("%d %d\n", pa->data, pb->data);
    // printf("la:%d  lb:%d\n",len_a,len_b);
    while (pa != NULL)
    {

        while (pb != NULL)
        {
            printf("%d %d", pa->data, pb->data);
            qa = pa->next;
            qb = pb->next;
            // if (pb->data > pa->data && pb->data < qa->data)
            // {
            //     pb->next = qa;
            //     pa->next = pb;
            // }
            pa = qa;
            pb = qb;
        }
    }
    // ListTraverse(La);
    return OK;
}
Status Join(LinkList L, LinkList La, LinkList Lb)
{
    return OK;
}

Status Sub(LinkList L, LinkList La, LinkList Lb)
{
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
    // ListTraverse(La);

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
    // ListTraverse(Lb);
    status = Union(L, La, Lb);
}