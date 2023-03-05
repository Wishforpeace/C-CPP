#include <iostream>
#include "11_binaryTreeNode.h"

using namespace std;

template <class T>

void infix(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        cout << "(";
        infix(t->leftChild);
        cout << t->element;
        infix(t->rightChild);
        cout << ")";
    }
}

// int main(void)
// {
//     binaryTreeNode<int> x, y, z;
//     x.element = 1;
//     y.element = 2;
//     z.element = 3;
//     x.leftChild = &y;
//     x.rightChild = &z;
//     y.leftChild = y.rightChild = z.leftChild = z.rightChild = 0;
//     infix(&x);
//     cout << endl;
// }