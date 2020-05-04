#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H
#include "graph.h"
#include "../../Linear/Queue/queue.h"


template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int & clock){
    Queue <int> Q; status(v) = DISCOVERED; // 初始化, 并指定一个节点作为起点开始层次搜索
    while(!Q.empty()){

        int v = Q.dequeue(); //开始处理当前节点
        dTime(v) = ++clock;
        for(int u = firstNbr(v); -1<u;u = nextNbr(v,u)) //遍历每个邻居节点
        {
            if( status(u) == UNDISCOVERED){
                status(u) = DISCOVERED; Q.enqueue(u);
                status(v, u ) = TREE; parent(u) = v;
            }else status(v, u) = CROSS;

        }



    status(v) = VISITED;

    }
}


#endif // GRAPH_BFS_H
