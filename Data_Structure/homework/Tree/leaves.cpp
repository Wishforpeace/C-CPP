#include "iostream"
#include "../../数据结构、算法与应用/11.BinaryTree/binaryTreeNode.h"
#include "../../数据结构、算法与应用/11.BinaryTree/binaryTreeTraversals.h"
#include "../../数据结构、算法与应用/11.BinaryTree/lab.cpp"
using namespace std;
template <class T>
int leaf_num(binaryTreeNode<T> *t)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->leftChild == NULL && t->rightChild == NULL)
    {
        return 1;
    }
    return leaf_num(t->leftChild) + leaf_num(t->rightChild);
}
int main()
{
    binaryTreeNode<char> *root;
    CreateTree(&root);
    cout << leaf_num(root) << endl;
}