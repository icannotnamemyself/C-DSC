#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "graph.h"
#include "vertex.h"
#include "edge.h"

template <typename Tv, typename Te>
class GraphMatrix: public Graph<Tv,Te>
{
private:
    vector<Vertex<Tv>> V; //顶点集
    vector< vector<   Edge<Te >*> >E; // 由邻接矩阵表示的边集

public:
//顶点总数
    int n ;
    int e;
    // 顶点
int insert ( Tv const& ) = 0; //插入顶点，返回编号
Tv remove ( int ) = 0; //删除顶点及其关联边，返回该顶点信息
Tv& vertex ( int ) = 0; //顶点v的数据（该顶点的确存在）
int inDegree ( int ) = 0; //顶点v的入度（该顶点的确存在）
int outDegree ( int ) = 0; //顶点v的出度（该顶点的确存在）
int firstNbr ( int ); //顶点v的首个邻接顶点
int nextNbr ( int, int ); //顶点v的（相对于顶点j的）下一邻接顶点
VStatus& status ( int ){

} ; //顶点v的状态
int& dTime ( int ) = 0; //顶点v的时间标签dTime
int& fTime ( int ) = 0; //顶点v的时间标签fTime
int& parent ( int ) = 0; //顶点v在遍历树中的父亲
int& priority ( int ) = 0; //顶点v在遍历树中的优先级数

// 边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
//边总数
bool exists ( int, int ) = 0; //边(v, u)是否存在
void insert ( Te const&, int, int, int ) = 0; //在顶点v和u之间插入权重为w的边e
Te remove ( int, int ) = 0; //删除顶点v和u之间的边e，返回该边信息
EStatus& status(int u, int v) {
    return E[u][v]->status;
}
//EType & type ( int, int ) = 0; //边(v, u)的类型
Te& edge ( int, int ) = 0; //边(v, u)的数据（该边的确存在）
int& weight ( int, int ) = 0; //边(v, u)的权重
    GraphMatrix(){n = e = 0;}
    ~GraphMatrix(){
        for(int j = 0; j < n; j++)
            for(int k = 0 ; k< n ; k++)
                delete  E[j][k];
}
    // 算法
       void bfs ( int ); //广度优先搜索算法
       void dfs ( int ); //深度优先搜索算法
       void bcc ( int ); //基于DFS的双连通分量分解算法
       Stack<Tv>* tSort ( int ); //基于DFS的拓扑排序算法
       void prim ( int ); //最小支撑树Prim算法
       void dijkstra ( int ); //最短路径Dijkstra算法
       template <typename PU> void pfs ( int, PU ); //优先级搜索框架
};


#endif // GRAPH_MATRIX_H
