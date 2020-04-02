#include "BiTree.h"  //引入类Bitree的声明
#include <algorithm> //引入算法
#include <iostream>  //引入输入输出流
#include <queue>     //引入队列
#include <stdio.h>   //引入输入输出流
using namespace std;

template <typename Type> //模板类 Type
Type Tree[31];           //全局变量

// 以下是类Bitree的成员的声明
template <typename Type> //模板类 Type
/**
 * 函数功能：构造二叉树;
 * 输入参数：BiNode<Type> *bt;
 * 输出参数：无；
 * 返回值：bt;
 * 调用函数:main.cpp中调用
 * */
BiNode<Type> *BiTree<Type>::Great(BiNode<Type> *bt)
{
    Type ch;
    cout << "请前序输入创建一个二叉树的结点数据（#为空）：";
    cin >> ch;
    if (ch == '#')
    {
        return NULL;
    }
    else
    {
        bt = new BiNode<Type>; //生成新结点
        bt->data = ch;
        bt->lChild = Great(bt->lChild); //递归建立左子树
        bt->rChild = Great(bt->rChild); //递归建立左子树
    }
    return bt; //返回指针
}

template <typename Type> //模板类 Type
/**
 * 函数功能：析构二叉树;
 * 输入参数：BiNode<Type> *bt;
 * 输出参数：无；
 * 返回值：无;
 * 调用函数:main.cpp中调用
 * */
void BiTree<Type>::Release(BiNode<Type> *bt)
{
    if (bt != NULL)
    {
        Release(bt->lChild); //释放左子树
        Release(bt->rChild); //释放右子树
        delete bt;
        bt = NULL;
    }
}

template <typename Type> //模板类 Type
/**
 * 函数功能：计算二叉树的叶子结点;
 * 输入参数：BiNode<Type> *bt;
 * 输出参数：无；
 * 返回值：count;
 * 调用函数:main.cpp中调用
 * */
int BiTree<Type>::PrTheLeafNodes(BiNode<Type> *bt)
{
    static int count = 0; //设置静态整形变量
    if (bt != NULL)
    {
        if (bt->lChild == NULL && bt->rChild == NULL)
            ++count;
        PrTheLeafNodes(bt->lChild); //累计左子树上的叶数
        PrTheLeafNodes(bt->rChild); //累计右子树上的叶数
    }
    return count;
}

template <typename Type> //模板类 Type
/**
 *函数功能：计算二叉树的深度;
 * 输入参数：BiNode<Type> *bt;
 * 输出参数：无；
 * 返回值：int;
 * 调用函数:main.cpp中调用
 * */
int BiTree<Type>::PrBiTreeDepth(BiNode<Type> *bt)
{
    static int hl = 0, hr = 0; // 设置静态整形变量
    if (bt == NULL)
        return 0;
    else
    {
        hl = PrBiTreeDepth(bt->lChild);
        hr = PrBiTreeDepth(bt->rChild);
        return max(hl, hr) + 1; //返回hl hr中最大的
    }
}

template <typename Type> //模板类 Type
/**
 *函数功能：层序遍历二叉树;
 * 输入参数：BiNode<Type> *bt;
 * 输出参数：无；
 * 返回值：无;
 * 调用函数:main.cpp中调用
 * */
void BiTree<Type>::PrSequence_traversal(BiNode<Type> *bt)
{
    queue<BiNode<Type> *> q; // 引入队列
    int longs = 0;
    if (bt != NULL)
    {
        // 根节点入队
        q.push(bt);
    }
    // 当队列不空时
    while (q.empty() == false)
    {
        Tree<Type>[longs++] = q.front()->data;
        if (q.front()->lChild != NULL) //如果有左孩子，入队
        {
            q.push(q.front()->lChild);
        }
        else
        {
            Tree<Type>[2 * longs - 1] = '#'; //运用数学的推理易得为二倍关系
        }
        if (q.front()->rChild != NULL) //如果有右孩子，入队
        {
            q.push(q.front()->rChild);
        }
        else
        {
            Tree<Type>[2 * longs] = '#'; //运用数学的推理易得为二倍关系
        }
        q.pop();
    }
}

template <typename Type> //模板类 Type
/**
 * 函数功能：画出二叉树;
 * 输入参数：无;
 * 输出参数：无；
 * 返回值：int depth;
 * 调用函数:main.cpp中调用
 * */
int BiTree<Type>::printTree() //打印树
{
    int i, j, k, depth = LONGS;
    for (j = 0; j < depth; j++)
    {
        static int H = 0; //设置静态整型变量
        int w = 1 << (depth - j + 1);
        if (j == 0)
            printf("%*c\n", w, '_');
        else
        {
            for (i = 0; i < 1 << (j - 1); i++)
            {
                printf("%*c", w + 1, ' ');
                for (k = 0; k < w - 3; k++)
                    printf("_");
                printf("/ \\");
                for (k = 0; k < w - 3; k++)
                    printf("_");
                printf("%*c", w + 2, ' ');
            }
            printf("\n");
            for (i = 0; i < 1 << (j - 1); i++)
                printf("%*c/%*c_%*c", w, '_', w * 2 - 2, '\\', w, ' ');
            printf("\n");
        }
        for (i = 0; i < 1 << j; i++)
        {
            printf("%*c", w - 1, '(');
            cout << Tree<Type>[H++];
            printf(")%*c", w - 1, ' ');
        }
        printf("\n");
    }
    return depth;
}
