#include "iostream"
#include <queue>
#include "../../数据结构、算法与应用/11.BinaryTree/binaryTreeNode.h"
// #include "../../数据结构、算法与应用/11.BinaryTree/binaryTreeTraversals.h"
#include "../../数据结构、算法与应用/11.BinaryTree/lab.cpp"

using namespace std;
template <class T>
bool IsCompleteBiTree(binaryTreeNode<T> *t)
{
    if (t == NULL)
    {
        return true;
    }
    queue<binaryTreeNode<T> *> cbt_q;
    cbt_q.push(t);
    binaryTreeNode<T> *front = NULL;
    while (front = cbt_q.front())
    {
        cbt_q.push(front->leftChild);
        cbt_q.push(front->rightChild);
        cbt_q.pop();
    }
    while (!cbt_q.empty())
    {
        if (cbt_q.front != NULL)
        {
            return false;
        }
        cbt_q.pop();
    }
    return true;
}

int main()
{
    binaryTreeNode<char> *root;
    CreateTree(&root);
    cout << IsCompleteBiTree(root) << endl;
}