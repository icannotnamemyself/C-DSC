#ifndef EDGE_OPT_H
#define EDGE_OPT_H
#include "graph_matrix.h"
#include "vertex.h"
#include "edge.h"

template <typename Tv, typename Te>
bool GraphMatrix<Tv, Te>::exists(int i , int j){
    return (0<=i && i<n) && (0<=j && j<n) && \
            E[i][j] !=NULL;
}

template <typename Tv, typename Te>
Te & GraphMatrix<Tv, Te>::edge(int i  , int j)
{
    return E[i][j]->data;
}

/**
 * 添加一条边
 */
template <typename Tv, typename Te>
void GraphMatrix<Tv, Te>::insert(Te const & edge, int w, int i ,int j){
    if(exists(i,j)) return ;
    E[i][j] = new Edge<Te>(edge, w);
    e++;
    this->V[i].outDegree++;
    this->V[i].inDegree++;
}

/******
 *  删除一条边
 * */
template <typename Tv, typename Te>
Te GraphMatrix<Tv, Te>::remove(int i ,int j){
    Te eBak = edge(i,j);
    delete  E[i][j]; E[i][j] = NULL; //删除边

    e--;
    this->V[i].outDegree--;
    this->V[i].inDegree--;
    return eBak;
}





#endif // EDGE_OPT_H
