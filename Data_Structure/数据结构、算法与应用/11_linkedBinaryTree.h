#ifndef linkedBinaryTree_
#define linkedBinaryTree_

using namespace std;

#include <iostream>
#include "11_binaryTree.h"
#include "arrayQueue.h"
#include "11_binaryTreeNode.h"
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

    //判断二叉树是否为空
    bool empty() const { return treeSize == 0; }
    //获得二叉树大小
    int size() const { return treeSize; }
    //根结点
    E *rootElement() const;
    //生成二叉树
    void makeTree(const E &element,
                  linkedBinaryTree<E> &, linkedBinaryTree<E> &);

    //删除左子树
    linkedBinaryTree<E> &removeLeftSubtree();
    //删除右子树
    linkedBinaryTree<E> &removeRightSubtree();

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

    //前序输出
    void preOrderOutput()
    {
        preOrder(output);
        cout << endl;
    }

    //中序输出
    void inOrderOutput()
    {
        inOrder(output);
        cout << endl;
    }

    //后序输出
    void postOrderOutput()
    {
        postOrder(output);
        cout << endl;
    }

    //层次输出
    void levelOrderOutput()
    {
        levelOrder(output);
        cout << endl;
    }

    //利用静态方法dispose
    // dispose最为函数指针visit方法
    void erase()
    {
        postOrder(dispose);
        root = NULL;
        treeSize = 0;
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
    //通过前序遍历计算结点个数
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

void (*linkedBinaryTree<int>::visit)(binaryTreeNode<int> *);
void (*linkedBinaryTree<int>::visit)(binaryTreeNode<booster> *);
void (*linkedBinaryTree<pair<int, int>>::visit)(binaryTreeNode<pair<int, int>> *);
void (*linkedBinaryTree<pair<const int, char>>::visit)(binaryTreeNode<pair<const int, char>> *);

template <class E>
E *linkedBinaryTree<E>::rootElement() const
{
    if (treeSize == 0)
    {
        return NULL;
    }
    else
    {
        return &root->element;
    }
}

template <class E>
void linkedBinaryTree<E>::makeTree(const E &element,
                                   linkedBinaryTree<E> &left, linkedBinaryTree<E> &right)
{
    root = new binaryTreeNode<E>(element, left.root, right.root);
    treeSize = left.treeSize + right.treeSize + 1;

    left.root = right.root = NULL;
    left.treeSize = right.treeSize = 0;
}

template <class E>
linkedBinaryTree<E> &linkedBinaryTree<E>::removeLeftSubtree()
{
    //删除并返回左子树
    if (treeSize == 0)
    {
        throw emptyTree();
    }
    //分离左子树并保存在
    linkedBinaryTree<E> leftSubtree;
    leftSubtree.root = root->leftChild;
    count = 0;
    leftSubtree.treeSize = countNodes(leftSubtree.root);
    root->leftChild = NULL;
    treeSize -= leftSubtree.treeSize;
    return leftSubtree;
}

template <class E>
linkedBinaryTree<E> &linkedBinaryTree<E>::removeLeftSubtree()
{
    if (treeSize == 0)
    {
        throw emptyTree();
    }
    
}
#endif