#include "iostream"
#include "../../数据结构、算法与应用/11.BinaryTree/binaryTreeNode.h"
#include "../../数据结构、算法与应用/11.BinaryTree/binaryTreeTraversals.h"
#include "../../数据结构、算法与应用/11.BinaryTree/lab.cpp"

template <class T>
int Depth(binaryTreeNode<T> *t)
{
    int m, n;
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        m = Depth(t->leftChild);
        n = Depth(t->rightChild);
        if (m > n)
        {
            return (m + 1);
        }
        else
        {
            return (n + 1);
        }
    }
}
int main()
{
    binaryTreeNode<char> *root;
    CreateTree(&root);
    cout << Depth(root->rightChild) << endl;
}

// AB#C##DE##FG#H##I##