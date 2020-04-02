/***
 * 二叉树的结点 BiNode 构造
 * 二叉链表类 Bitree 的定义
 * */
#ifndef BITREE_H
#define BITREE_H //避免重复包含Bitree.h头文件
/**
 * 二叉链表的结点
 * */
template <typename Type> //模板类 Type
struct BiNode
{
    Type data;                     //存储二叉树的数据元素
    BiNode<Type> *lChild, *rChild; //指向该节点的左孩子与右孩子
};

/**
 * BiTree类的声明
 * */
template <typename Type> //模板类 Type
class BiTree
{
public:
    BiTree() { root = Great(root); }                          //构造函数，建立一棵二叉树
    ~BiTree() { Release(root); }                              //析构函数，释放各个结点的储存空间
    void Sequence_traversal() { PrSequence_traversal(root); } //层序遍历
    int PuTheLeafNodes() { return PrTheLeafNodes(root); }     //求二叉树中叶子结点的个数
    void BiTreeDepth() { LONGS = PrBiTreeDepth(root); }       //求二叉树二点深度
    int printTree();                                          //画出二叉树

private:
    BiNode<Type> *root;                          //指向根结点的头指针
    int LONGS = 0;                               //树的深度
    int PrBiTreeDepth(BiNode<Type> *bt);         //求二叉树深度的调用
    BiNode<Type> *Great(BiNode<Type> *bt);       //构造函数的调用
    void Release(BiNode<Type> *bt);              //析构函数调用
    int PrTheLeafNodes(BiNode<Type> *bt);        //二叉树叶子节点个数调用
    void PrSequence_traversal(BiNode<Type> *bt); //层序遍历调用
};
#endif
