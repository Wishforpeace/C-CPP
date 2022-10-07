#include<iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE

#define MAXSIZE 20
typedef int ElemType;
typedef int Status;

Status visit(ElemType c)
{
    cout<<c<<endl;
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; // 定义LinkList

//初始化链式线性表
Status InitList(LinkList *L)
{
    // 产生头结点，使L指向此处的头结点
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L)) //内存分配失败
    {
        return ERROR;
    }
    // 指针域为空
    (*L)->next = NULL;
    return OK;
}

int ListLength(LinkList L)
{
    int i = 0;
    LinkList p= L->next;
    while (p)
    {
        i++;
        p = p->next;
    }

    return i;
    
}

//执行插入操作
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while (p && j<1)
    {
       p = p->next;
       ++j;
    }
    //找不到第i个元素
    if(!p|| j>i)
    {
        return ERROR;
    }
    // 产生新结点
    s = (LinkList)malloc(sizeof(Node))
    
}


int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i = InitList(&L);
    cout<<"初始化后LinkList长度为"<<ListLength(L)<<endl;

    for(j=1;j<=5;j++)
    {
        i = ListIn
    }
}