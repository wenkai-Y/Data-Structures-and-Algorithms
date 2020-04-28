/***
 * 哈密顿图就是从一点出发,经过所有的必须且只能一次,
 * 最终回到起点的路径.图中有的边可以不经过,但是不会有边被经过两次.
 * */
// #ifdef ALGraph_H //避免重复包含ALGrph.h头文件
// #define ALGraph_H
const int MAXSIZE = 10; //图中最大的顶点数
#include <cstring>
#include <string>

struct ArcNode
{
    /* data */
    int adjvex; //临界点域
    ArcNode *next;
};

template <class DataType>
struct VertexNode
{
    /* data */
    DataType vertex; //定义顶点表结点
    ArcNode *firstedge;
};

template <class DataType>
class ALGraph
{
private:
    /* data */
    VertexNode<DataType> adjlist[MAXSIZE]; //存放顶点表的数组
    void Hamiltonian_path(int vertex);     //哈密顿路径问题
    int vertexNum, arcNum;                 //存放图的顶点和边数
    int arc[MAXSIZE][MAXSIZE];             //存放图中边的数组
    int visited[MAXSIZE] = {0};
    int visited_H[MAXSIZE] = {0};
    int vis[MAXSIZE + 1];
    std::string input[MAXSIZE + 1];

public:
    ALGraph(DataType data[], int vertex, int brim); //构造函数
    ~ALGraph();                                     //析构函数
    void DFSTraverse(int vertex);                   //深度优先遍历
    void IsHamiltonian_path();                      //是否为哈密顿路径
    void ChangeToMGraph();                          //将有向图的邻接表改为无向图邻接矩阵
};

// #endif