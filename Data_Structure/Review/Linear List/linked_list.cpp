#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct Node *LinkList;

Status InitLinkList(LinkList *L)
{
    *L = new Node;
    if (!(*L))
    {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

int main()
{
    LinkList L;
}