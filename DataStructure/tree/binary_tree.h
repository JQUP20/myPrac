#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <class T>
struct BinaryTreeNode {
    BinaryTreeNode() : left_child(nullptr), right_child(nullptr) {}
    BinaryTreeNode(T data, BinaryTreeNode<T>* left_child = nullptr, BinaryTreeNode<T>* right_child = nullptr) : m_data(data), m_pLeftChild(left_node), m_pRightChild(right_child) {}
    
    T m_data;
    BinaryTreeNode<T>* m_pLeftChild;
    BinaryTreeNode<T>* m_pRightChild;
};

/*
 *@brief 后序遍历栈结点模板类
 *
 */
template <class T>
struct PostOrderStackNode {
    explicit PostOrderStackNode(NinaryTreeNode<T>* node = nullptr) {
        this->node = node;
        tag = LEFT;
    }

    BinaryTreeNode<T>* node;
    enum { LEFT, RIGHT } tag;
};

template <class T>
class BinaryTree {
public:
    BinaryTree() : root_(NULL) {}
    BinaryTree(T data)  { this->SubTreeInsert_(this->root_, data); }
    BinaryTree(const BinaryTree<T>& bin_tree) { this->root_ = this->Copy_(bin_tree.Root()); }
    ~BinaryTree() { this->SubTreeDestroy_(root_); }

    bool Insert(T data) { return this->SubTreeInsert_(this->root_, data) };

    //递归
    //前序遍历
    void PreOrder(void (*visit)(BinaryTreeNode<T>* node))
    {
        this->SubTreePreOrder_(this->root_, visit);
    }

    void Inorder(void (*visit)(BinTreeNode<T>* node)) 
    { 
        this->SubTreeInOrder_(this->root_, visit); 
    }

    void PostOrder(void (*visit)(BinTreeNode<T>* node))
    {
        this->SubTreePostOrder_(this->SubTreePostOrder_(this->root_, visit));
    }

    //非递归
    //前序遍历
    void PreOrderNonRecursive( void (*visit)(BinTreeNode<T>* node ))
    {
        this->SubTreePreOrderNonRecursive_(this->root_, visit);
    }

    void INOrderNonRecursive(void (*visit)(BinaryTreeNode<T>* node)) {
        this->SubTreeInorderNonRecursive_(this->root_, visit);
    }
    
    void PostOrderNonRecursive(void (*visit)(BinTreeNode<T>* node))
    {
        this->SubTreePostOrderNonRecursive_(this->root_, visit);
    }

    //层序遍历
    void LevelOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreeLeveklOrder_(this->root_, visit); }

    //使用前序遍历和中序遍历结果，创建二叉树
    void CreateBinTreeByPreAndInOrderString(T* pre_order_str, T* in_order_str, int str_length)
    {
        this->CreateSubBinTreeByPreAndInOrderString_(pre_order_str, in_order_str, str_length, this->root_);
    }

    void Print() { this->SubTreePrint_(this->root_); };

    //使用输入流创建二叉树
    void CreateBinTree(istream &in) { this->CreateBinTree_(in, this->root_); }

protected:
    BinTreeNode<T>* root_;


};







