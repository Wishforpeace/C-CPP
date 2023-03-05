#include <iostream>
#include "binaryTree.h"
#include "11_lab.cpp"
#include "11_binaryTreeTraversals.h"
using namespace std;

int main()
{
    binaryTreeNode<char> *root;
    CreateTree(&root);
    inOrder(root);
}
