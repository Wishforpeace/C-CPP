#ifndef linkedBinaryTree_
#define linkedBinaryTree_

using namespace std;

#include <iostream>
#include "binaryTree.h"
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "../../codes/myExceptions.h"
#include "../../codes/booster.h"

template <class E>

// BinaryTree的抽象派生类，结点类型为binaryTreeNode
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
public:
    linkedBinaryTree()
    {
        root = NULL;
        treeSize = 0;
    }
    ~linkedBinaryTree() { erase(); }

    //利用静态方法dispose
    // dispose最为函数指针visit方法
    void erase()
    {
        postOrder(dispose);
        root = NULL;
        treeSize = 0;
    }

    //前序遍历
    void preOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        preOrder(root);
    }
    //中序遍历
    void inOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        inOrder(root);
    }
    //后序遍历
    void postOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        postOrder(root);
    }
    //层次遍历
    void levelOrder(void (*)(binaryTreeNode<E> *));

    void preOrderOutput()
    {
        preOrder(output);
        cout << endl;
    }

    void inOrderOutput()
    {
        inOrder(output);
        cout << endl;
    }

    void postOrderOutput()
    {
        postOrder(output);
        cout << endl;
    }

    void levelOrderOutput()
    {
        levelOrder(output);
        cout << endl;
    }

    //表示不可修改class数据成员
    int height() const { return height(root); }

protected:
    //两个数据成员实例
    // root指向二叉树结点的指针
    binaryTreeNode<E> *root;
    int treeSize;
    //函数指针visit，静态数据成员，接受参数为binaryTreeNode
    static void (*visit)(binaryTreeNode<E> *);
    static int count;
    static void preOrder(binaryTreeNode<E> *t);
    static void inOrder(binaryTreeNode<E> *t);
    static void postOrder(binaryTreeNode<E> *t);
    static void countNodes(binaryTreeNode<E> *t)
    {
        visit = addToCount;
        count = 0;
        preOrder(t);
    }
    //删除一个结点
    static void dispose(binaryTreeNode<E> *t)
    {
        delete t;
    }
    //输出
    static void output(binaryTreeNode<E> *t)
    {
        cout << t->element << "  ";
    }
    static void addToCount(binaryTreeNode<E> *t)
    {
        count++;
    }
    static int height(binaryTreeNode<E> *t);
};


void (*linkedBinaryTree<int>::visit)(binaryTreeNode<int>*);
void(*linkedBinaryTree<int>::visit)(binaryTreeNode<booster>*);
void(*linkedBinaryTree<pair<int,int>>::visit)(binaryTreeNode<pair< int,int>>*);
void(*linkedBinaryTree<pair<const int ,char>>::visit)(binaryTreeNode<pair<const int,char>>*);



#endif