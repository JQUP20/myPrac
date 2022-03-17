#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__


struct BinaryTreeNode
{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};

//template <class T>
class BinaryTree
{
public:
    BinaryTree() {};

    BinaryTree(int data);

    BinaryTree(const BinaryTree& bin_tree);

    ~BinaryTree();

    BinaryTreeNode* CreateBinaryTreeNode(int value);

    void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

    void PrintTreeNode(const BinaryTreeNode* pNode);

    void PrintTree(const BinaryTreeNode* pRoot);

    void DestroyTree(BinaryTreeNode* pRoot);

    void PreOrderRecursive(BinaryTreeNode* pRoot);

    void InOrderRecursive(BinaryTreeNode* pRoot);

    void PostOrderRecursive(BinaryTreeNode* pRoot);

    void PreOrderNonRecursive(BinaryTreeNode* pRoot);
    
    void InOrderNonRecursive(BinaryTreeNode* pRoot);
    
    void PostOrderNonRecursive(BinaryTreeNode* pRoot);    
        
    //层序遍历
    void LevelOrder(BinaryTreeNode* pRoot);
    
    //从上到下分行打印二叉树
    void PrintInLine(BinaryTreeNode* pRoot);
   
    //之字形打印二叉树
    void PrintInZigzag(BinaryTreeNode* pRoot);
private:
    BinaryTreeNode* m_pRoot;
};

#endif
