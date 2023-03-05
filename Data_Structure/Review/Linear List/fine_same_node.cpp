#include <iostream>

using namespace std;
#define OK 1
#define FALSE 0
#define ERROR 0
#define TRUE 1
typedef int Status;
typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct Node *LinkList;
Status InitStack(LinkList *L)
{
    L = new LinkList;
    if (!(*L))
    {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}
Status Empty(LinkList L)
{
    if (L->next == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

int ListLength(LinkList L)
{
    LinkList p;
    p = L->next;
    int count = 0;
    while (p != nullptr)
    {
        count++;
    }

    return count;
}

int DeleteNode(LinkList *L, int i, int *e)
{
    LinkList p;
    p = p->next;
    int index = 1;
    while (index < i)
    {
        index++;
        p = p->next;
    }
}
int main()
{
}