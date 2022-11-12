#include <iostream>
#include "binaryTreeNode.h"
#include "../../codes/myExceptions.h"
#include "../../codes/arrayQueue.h"
using namespace std;

template <class T>
void visit(binaryTreeNode<T> *x)
{
    cout << x->element << " ";
}

//先序遍历
template <class T>
void preOrder(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

//中序遍历
template <class T>
void inOrder(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->rightChild);
    }
}

template <class T>
void postOrder(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

//层次遍历
template <class T>
void levelOrder(binaryTreeNode<T> *t)
{
    //先定一个数组队列，类型为bTree
    arrayQueue<binaryTreeNode<T> *> q;
    while (t != NULL)
    {
        visit(t);

        if (t->leftChild != NULL)
        {
            //左孩子入队
            q.push(t->leftChild);
        }
        if (t->rightChild != NULL)
        {
            //右孩子进队
            q.push(t->rightChild);
        }
        // try 块中放置可能抛出异常的代码，try 块中的代码被称为保护代码。
        try
        {
            t = q.front();
        }
        // catch 块跟在 try 块后面，用于捕获异常。
        catch (queueEmpty)
        {
            return;
        }
        q.pop();
    }
}
int main(void)
{

    binaryTreeNode<int> *x, *y, *z;
    y = new binaryTreeNode<int>(2);
    z = new binaryTreeNode<int>(3);
    x = new binaryTreeNode<int>(1, y, z);

    cout << "Inorder sequence is ";
    inOrder(x);
    cout << endl;
    cout << "Preorder sequence is ";
    preOrder(x);
    cout << endl;
    cout << "Postorder sequence is ";
    postOrder(x);
    cout << endl;
    cout << "Level order sequence is ";
    int i;
    binaryTreeNode<int> *l, *r, *p;
    // for (i = 7; i >= 1; i--)
    // {
    //     l = new binaryTreeNode<int>(2 * i + 1);
    //     r = new binaryTreeNode<int>(2 * i);
    //     p = new binaryTreeNode<int>(i, l, p);
    // }
    levelOrder(x);
    cout << endl;
}