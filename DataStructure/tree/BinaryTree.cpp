#include <iostream>
#include <stack>
#include <queue>
#include "BinaryTree.h"

using namespace std;


BinaryTree::BinaryTree(int data)
{

}

BinaryTree::BinaryTree(const BinaryTree& bin_tree)
{

}

BinaryTree::~BinaryTree()
{
    //DestroyTree(m_root);
}

BinaryTreeNode* BinaryTree::CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void BinaryTree::ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void BinaryTree::PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        cout << "value of this node is --> " << pNode->m_nValue << endl;

        if(pNode->m_pLeft != nullptr)
            cout << "value of its left child is --> " << pNode->m_pLeft->m_nValue << endl;
        else
            cout << "left child is nullptr." << endl;

        if(pNode->m_pRight != nullptr)
            cout << "value of its right child is : --> " << pNode->m_pRight->m_nValue << endl;
        else
            cout << "right child is nullptr." << endl;
    }
    else
        cout << "this node is nullptr." << endl;

    cout << endl;
}

void BinaryTree::PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void BinaryTree::DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

void BinaryTree::PreOrderRecursive(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    PrintTreeNode(pRoot);

    PreOrderRecursive(pRoot->m_pLeft);
    PreOrderRecursive(pRoot->m_pRight);
}

void BinaryTree::InOrderRecursive(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    InOrderRecursive(pRoot->m_pLeft);
    PrintTreeNode(pRoot);
    InOrderRecursive(pRoot->m_pRight);
}

void BinaryTree::PostOrderRecursive(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    PostOrderRecursive(pRoot->m_pLeft);
    PostOrderRecursive(pRoot->m_pRight);
    PrintTreeNode(pRoot);
}

void BinaryTree::PreOrderNonRecursive(BinaryTreeNode* pRoot)
{
    stack<BinaryTreeNode*> pre_traverse_stack;
    pre_traverse_stack.push(pRoot);

    while(!pre_traverse_stack.empty())
    {
        BinaryTreeNode* cur_node_ptr = pre_traverse_stack.top();
        pre_traverse_stack.pop();

        PrintTreeNode(cur_node_ptr);


        if(cur_node_ptr->m_pRight != nullptr)
        {
            pre_traverse_stack.push(cur_node_ptr->m_pRight);
        }

        if(cur_node_ptr->m_pLeft != nullptr)
        {
            pre_traverse_stack.push(cur_node_ptr->m_pLeft);
        }
    }
}

void BinaryTree::InOrderNonRecursive(BinaryTreeNode* pRoot)
{
    stack<BinaryTreeNode*> in_traverse_stack;
    BinaryTreeNode* cur_node = pRoot;

    while( cur_node != nullptr || !in_traverse_stack.empty())
    {
        while(cur_node != nullptr)
        {
            in_traverse_stack.push(cur_node);
            cur_node = cur_node->m_pLeft;
        }

        if(!in_traverse_stack.empty())
        {
            cur_node = in_traverse_stack.top();
            in_traverse_stack.pop();

            PrintTreeNode(cur_node);

            cur_node = cur_node->m_pRight;
        }
    }

}

void BinaryTree::PostOrderNonRecursive(BinaryTreeNode* pRoot)
{
    stack<BinaryTreeNode*> post_traverse_stack;

    BinaryTreeNode* cur_node = pRoot;
    BinaryTreeNode* pre_node = nullptr;

    post_traverse_stack.push(cur_node);
    while(!post_traverse_stack.empty())
    {
        cur_node = post_traverse_stack.top();
        if((cur_node->m_pLeft == nullptr && cur_node->m_pRight == nullptr) ||
                (pre_node != nullptr && (pre_node == cur_node->m_pLeft || pre_node == cur_node->m_pRight)))
        {
            PrintTreeNode(cur_node);
            post_traverse_stack.pop();
            pre_node = cur_node;
        }
        else
        {
            if(cur_node->m_pRight != nullptr)
                post_traverse_stack.push(cur_node->m_pRight);
            if(cur_node->m_pLeft != nullptr)
                post_traverse_stack.push(cur_node->m_pLeft);
        }
    } 
}

void BinaryTree::LevelOrder(BinaryTreeNode* pRoot)
{
    queue<BinaryTreeNode*> level_traverse_queue;

    BinaryTreeNode* cur_node = pRoot;

    level_traverse_queue.push(cur_node);

    while(!level_traverse_queue.empty())
    {
        cur_node = level_traverse_queue.front();
        level_traverse_queue.pop();

        PrintTreeNode(cur_node);

        if(cur_node->m_pLeft != nullptr)
        {
            level_traverse_queue.push(cur_node->m_pLeft);
        }

        if(cur_node->m_pRight != nullptr)
        {
            level_traverse_queue.push(cur_node->m_pRight);
        }
    } 
}

void BinaryTree::PrintInLine(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    queue<BinaryTreeNode*> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while(!nodes.empty())
    {
        BinaryTreeNode* pNode = nodes.front();
//        PrintTreeNode(pNode);
        cout << pNode->m_nValue;

        if(pNode->m_pLeft != nullptr)
        {
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        if(pNode->m_pRight != nullptr)
        {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }
        nodes.pop();
        --toBePrinted;
        if(toBePrinted == 0)
        {
            cout << endl;
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}

void BinaryTree::PrintInZigzag(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    stack<BinaryTreeNode*> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();

        cout << pNode->m_nValue << " ";

        if(current == 0)
        {
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else
        {
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }

        if(levels[current].empty())
        {
            cout << endl;
            current = 1 - current;
            next = 1 - next;
        }
    }
}






















































































