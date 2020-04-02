#include "Bitree.cpp"
#include <iostream>
using namespace std;
int main()
{
    cout << "请输入二叉树的前序排序!" << endl;
    BiTree<char> Tree;
    cout << endl
         << "二叉树的图形为(其中'#'表示为空)：" << endl;
    Tree.BiTreeDepth();
    Tree.Sequence_traversal();
    int depth = Tree.printTree();
    cout << endl
         << "该二叉树的叶子节点有：" << Tree.PuTheLeafNodes() << "个." << endl
         << "二叉树的深度为：" << depth << endl;

    return 0;
}
