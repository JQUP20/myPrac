#include "BinaryTree.h"
#include <iostream>

using namespace std;

void Test1()
{
    cout << "=======Test1 starts:=======" << endl;
    BinaryTree bTree;

    BinaryTreeNode* pNode8 = bTree.CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = bTree.CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = bTree.CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = bTree.CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = bTree.CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = bTree.CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = bTree.CreateBinaryTreeNode(11);

    bTree.ConnectTreeNodes(pNode8, pNode6, pNode10);
    bTree.ConnectTreeNodes(pNode6, pNode5, pNode7);
    bTree.ConnectTreeNodes(pNode10, pNode9, pNode11);

    bTree.PrintTree(pNode8);

    cout << "先序遍历（递归）" << endl;
    bTree.PreOrderRecursive(pNode8);

    cout << "先序遍历（非递归）" << endl;
    bTree.PreOrderNonRecursive(pNode8);

    cout << "中序遍历（递归）" << endl;
    bTree.InOrderRecursive(pNode8);

    cout << "中序遍历（非递归）" << endl;
    bTree.InOrderNonRecursive(pNode8);


    cout << "后序遍历（递归）" << endl;
    bTree.PostOrderRecursive(pNode8);

    cout << "后序遍历（非递归）" << endl;
    bTree.PostOrderNonRecursive(pNode8);

    cout << "层序遍历" << endl;
    bTree.LevelOrder(pNode8);

    cout << "分行打印" << endl;
    bTree.PrintInLine(pNode8);

    cout << "之字形打印" << endl;
    bTree.PrintInZigzag(pNode8);

}

int main()
{
    Test1();
}

