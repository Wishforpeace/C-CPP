#include <stdio.h>
#include "arrayList.h"
Status Union(SqlList *La, SqlList *Lb, SqlList *L_join)
{
    int len1 = La->length;
    int len2 = Lb->length;
    // printf("%d %d\n",len1,len2);
    int i, j;
    for (i = 0; i < len2; i++)
    {
        L_join->elem[i] = Lb->elem[i];
        L_join->length++;
    }
    // ListTraverse(L_join);
    int location;
    ElemType e;
    // for (i = 0; i <len1; i++)
    // {
    //     for (j = 0; j < len2; j++)
    //     {

    //         if (La->elem[i] == Lb->elem[j])
    //         {
    //             e = La->elem[i];
    //             location = LocateElem(L_join,e);
    //             ListDelete(L_join, location , &e);
    //         }

    //     }
    // }
    ListTraverse(L_join);
    printf("len:%d\n", L_join->length);
    for (i = 0; i < L_join->length; i++)
    {
        for (j = 0; j < La->length; j++)
        {
            if (L_join->elem[i] == La->elem[j])
            {
                continue;
            }
            if (L_join->elem[0] > La->elem[j])
            {
                ListInsert(L_join, 1, La->elem[j]);
                continue;
            }
            if (L_join->elem[i] < La->elem[j] && L_join->elem[i + 1] > La->elem[j])
            {
                ListInsert(L_join, i + 2, La->elem[j]);
                continue;
            }
            // ListInsert(L_join,L_join->length,La->elem[j]);
        }
    }
    printf("A并B: ");
    ListTraverse(L_join);
    return OK;
}
Status Join(SqlList *La, SqlList *Lb, SqlList *L_join)
{
    int i, j;
    int k = 0;
    int flag = 0;
    for (i = 0; i < La->length; i++)
    {
        for (j = 0; j < Lb->length; j++)
        {
            if (La->elem[i] == Lb->elem[j])
            {
                L_join->elem[k] = La->elem[i];
                k++;
                L_join->length += 1;
                flag = 1;
            }
        }
    }
    if(!flag)
    {
        printf("A交B为空");
        return FALSE;
    }
    printf("A交B: ");
    ListTraverse(L_join);
    return OK;
}

Status Sub(SqlList *La, SqlList *Lb, SqlList *L_join)
{
    int i,j;
    for(i=0;i<La->length;i++)
    {
        L_join->elem[i] = La->elem[i];
        L_join->length++;
    }

    int location;
    ElemType e;
    for (i=0;i<La->length;i++)
    {
        for(j=0;j<Lb->length;j++)
        {
            if(La->elem[i]==Lb->elem[j])
            {
                location = LocateElem(L_join,La->elem[i]);
                ListDelete(L_join,location,&e);
            }
        }
    }
    
    ListTraverse(L_join);
    return OK;
}
int main()
{
    SqlList La, Lb, L_join;
    Status status;
    status = InitList(&La);
    PrintStatus(status, "Init LinearList");
    status = InitList(&Lb);
    PrintStatus(status, "Init LinearList");
    status = InitList(&L_join);
    PrintStatus(status, "Init LinearList");
    printf("------------Input A------------\n");
    int num;
    printf("num = ");
    scanf("%d", &num);
    int i;
    printf("elem A = ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &La.elem[i]);
        La.length++;
    }
    ListTraverse(&La);
    printf("------------Input B------------\n");
    printf("num = ");
    scanf("%d", &num);
    printf("elem B = ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &Lb.elem[i]);
        Lb.length++;
    }
    ListTraverse(&Lb);
    status = Union(&La, &Lb, &L_join);
    PrintStatus(status, "Union");
    status = ClearList(&L_join);
    PrintStatus(status, "Clear");
    status=Join(&La, &Lb, &L_join);
    PrintStatus(status,"Join");
    PrintStatus(status, "Union");
    status = ClearList(&L_join);
    PrintStatus(status, "Clear");
    printf("A差B:");
    status= Sub(&La,&Lb,&L_join);
    PrintStatus(status,"Sub");
    status = ClearList(&L_join);
    printf("B差A:");
    Sub(&Lb,&La,&L_join);
}