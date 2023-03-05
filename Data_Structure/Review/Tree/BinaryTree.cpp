#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <math.h>
#include <time.h>
#include <string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 // 存储空间初始分配量

typedef int Status;

// 构造二叉树
int treeIndex = 1;
typedef char String[24];
string str;

Status StrAssign(string T, string chars)
{
    int i;
    if (chars.length() > MAXSIZE)
        return ERROR;
    else
    {
        T[0] = chars.length();
        for (i = 1; i <= T[0]; i++)
            T[i] = chars[i];
        return OK;
    }
}

/*============================================*/
typedef char TElemtype;
TElemtype Nil = ' ';

Status visit(TElemtype e)
{
    printf("%c", e);
    return OK;
}

typedef struct BiTNode
{
    TElemtype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 构造空的二叉树
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

// 销毁二叉树
void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)
        {
            DestroyBiTree(&(*T)->lchild);
        }
        if ((*T)->rchild)
        {
            DestroyBiTree(&(*T)->rchild);
        }
        free(*T);
        *T = NULL;
    }
}

void CreateBiTree(BiTree *T)
{
    // cout << "6666";
    TElemtype ch;
    cin >> ch;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == nullptr)
        {
            cout << "failed" << endl;
            exit(-1);
        }
        else
        {
            (*T)->data = ch;
            CreateBiTree(&((*T)->lchild));
            CreateBiTree(&((*T)->rchild));
        }
    }
}

Status BiTreeEmpty(BiTree T)
{
    if (T)
        return FALSE;
    else
        return TRUE;
}

int BiTreeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    int ldepth = BiTreeDepth(T->lchild);
    int rdepth = BiTreeDepth(T->rchild);
    if (ldepth < rdepth)
    {
        return rdepth + 1;
    }
    else
    {
        return ldepth + 1;
    }
}

TElemtype Root(BiTree T)
{
    if (T != NULL)
    {
        return T->data;
    }
    else
    {
        return Nil;
    }
}

TElemtype Value(BiTree T)
{
    return T->data;
}

void PreOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c ", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

void InOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    InOrder(T->lchild);
    printf("%c ", T->data);
    InOrder(T->rchild);
}

void PostOrder(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrder(T->lchild);
    printf("%c ", T->data);
    PostOrder(T->rchild);
}

void LevelOrder(BiTree T)
{
    // cout << "6666";
    BiTree P;
    P = new BiTNode;
    queue<BiTree> q;
    q.push(T);
    while (!q.empty())
    {
        cout << q.front()->data << " ";

        if (q.front()->lchild != NULL)
        {
            q.push(q.front()->lchild);
        }
        if (q.front()->rchild != NULL)
        {
            q.push(q.front()->rchild);
        }
        q.pop();
    }
}

int CountLeves(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    if (T != NULL)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            return 1;
        }
    }
    return CountLeves(T->lchild) + CountLeves(T->rchild);
}

int main()
{
    int i;
    BiTree T;
    InitBiTree(&T);

    StrAssign(str, "ABDH#K###E##CFI###G#J##");
    CreateBiTree(&T);
    // cout << T->data;
    // cout << T->lchild->lchild->lchild->data;
    // cout << T->rchild->data;
    LevelOrder(T);
    cout << endl;
    PreOrder(T);
    cout << endl;
    InOrder(T);
    cout << endl;
    PostOrder(T);
    cout << endl;
    cout << BiTreeDepth(T) << endl;
    cout << CountLeves(T) << endl;
}