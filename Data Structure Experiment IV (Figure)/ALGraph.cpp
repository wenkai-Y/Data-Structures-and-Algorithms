#include "ALGraph.h"
#include <iostream>
using namespace std;

// 构造函数 存取图
template <class DataType>
ALGraph<DataType>::ALGraph(DataType data[], int vertex, int brim)
{
    ArcNode *s;
    int i, j, k;
    vertexNum = vertex;
    arcNum = brim;
    for (i = 0; i < vertexNum; ++i)
    {
        adjlist[i].vertex = data[i];
        adjlist[i].firstedge = NULL;
    }
    // 依次输入每一条边
    for (k = 0; k < arcNum; ++k)
    {
        cout << "请输入边的两个顶点的序号：";
        cin >> i >> j;
        s = new ArcNode;
        s->adjvex = j;
        s->next = adjlist[i].firstedge;
        adjlist[i].firstedge = s;
    }
}

// 析构函数 销毁图
template <class DataType>
ALGraph<DataType>::~ALGraph()
{
    ArcNode *p;
    for (int i = 0; i < vertexNum; ++i)
    {
        p = adjlist[i].firstedge;
        while (p != NULL)
        {
            adjlist[i].firstedge = p->next;
            delete p;
            p = NULL;
            p = adjlist[i].firstedge;
        }
    }
}

// DFS深度查找算法
template <class DataType>
void ALGraph<DataType>::DFSTraverse(int vertex)
{
    ArcNode *p = NULL;
    int j;
    cout << adjlist[vertex].vertex << " ";
    visited[vertex] = 1;
    p = adjlist[vertex].firstedge;
    while (p != NULL)
    {
        j = p->adjvex;
        if (visited[j] == 0)
            DFSTraverse(j);
        p = p->next;
    }
}

// 从一个结点是否为哈密顿图
template <class DataType>
void ALGraph<DataType>::Hamiltonian_path(int vertex)
{
    static int count = 0;
    int j = 0;
    visited_H[vertex] = 1;
    input[count++] = adjlist[vertex].vertex;
    // s.push(vertex);
    vis[count - 1] = vertex;
    for (j = 0; j < vertexNum; ++j)
        if (arc[vertex][j] == 1 && visited_H[j] == 0)
            Hamiltonian_path(j);
    if (j == vertexNum)
    {
        visited_H[vertex] = 0;
        --count;
    }
}

// 将有向图的邻接表改为无向图邻接矩阵
template <class DataType>
void ALGraph<DataType>::ChangeToMGraph()
{
    int i, j;
    // 初始化
    for (i = 0; i < vertexNum; ++i)
    {
        for (j = 0; j < vertexNum; ++j)
        {
            arc[i][j] = 0;
        }
    }
    // 录入数据
    ArcNode *p;
    for (i = 0; i < vertexNum; ++i)
    {
        p = adjlist[i].firstedge;
        while (p != NULL)
        {
            j = p->adjvex;
            arc[i][j] = 1;
            arc[j][i] = 1;
            p = p->next;
        }
    }
    cout << "该图的无向邻接矩阵：" << endl;
    cout << "\t";
    // 输出邻接矩阵
    for (int i = 0; i < vertexNum; ++i)
        cout << i << '\t';
    cout << endl;
    for (int i = 0; i < vertexNum; ++i)
    {
        for (int j = 0; j < vertexNum; ++j)
        {
            if (j == 0)
                cout << i << "\t";
            cout << arc[i][j] << "\t";
        }
        cout << endl;
    }
}

// 判断改图是否为哈密顿图
template <class DataType>
void ALGraph<DataType>::IsHamiltonian_path()
{
    int flage = 0, Ham_v = 0;
    do
    {
        Hamiltonian_path(Ham_v);
        int count = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (vis[i] > 10 || vis[i] < 0)
                break;
            else
                ++count;
        }
        if (count == vertexNum && arc[vis[count - 1]][Ham_v] == 1)
        {
            ++flage;
            break;
        }
        else
        {
            ++Ham_v;
            continue;
        }
    } while (Ham_v < vertexNum);
    if (flage)
    {
        cout << "改图是哈密顿路径，起点为：";
        cout << Ham_v << endl;
        cout << "路径为：";
        for (int i = 0; i < vertexNum; ++i)
        {
            cout << adjlist[i].vertex << "->";
        }
        cout << adjlist[vertexNum].vertex << endl;
    }
    else
    {
        cout << "改图不是哈密顿路径" << endl;
    }
}