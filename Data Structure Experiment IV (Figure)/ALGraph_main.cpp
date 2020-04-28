#include "ALGraph.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int vertex, brim, DFS_v;
    cout << "请输入图的节点数：";
    cin >> vertex;
    cout << "请输入图的边数：";
    cin >> brim;
    cout << endl;
    string *data = new string[brim];
    cout << "请输入结点的赋值：";
    for (int i = 0; i < vertex; ++i)
    {
        cin >> data[i];
    }
    cout << endl;
    ALGraph<string> G(data, vertex, brim);
    cout << endl;
    cout << "请输入深度算法的开始结点：";
    cin >> DFS_v;
    cout << "深度算法的输出：";
    G.DFSTraverse(DFS_v);
    cout << endl
         << endl;
    G.ChangeToMGraph();
    cout << endl;
    // 判断该图是否哈密顿图
    G.IsHamiltonian_path();
    cout << endl;
    return 0;
}
