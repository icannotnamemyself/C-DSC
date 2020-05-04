#ifndef VERTEX_OPT_H
#define VERTEX_OPT_H
#include "graph_matrix.h"
#include "vector"
#include "edge.h"


template <typename Tv, typename Te>
int GraphMatrix<Tv,Te>::nextNbr(int i , int j){
    while( (-1<j) && !exists(i,--j) );
    return j;
}

template <typename Tv, typename Te>
int GraphMatrix<Tv,Te>::firstNbr(int i ){
    return nextNbr(i,n);
}
template <typename Tv, typename Te>
int GraphMatrix<Tv,Te>::insert(Tv const & j){
    for(int j = 0; j <n ; j++) E[j].insert(NULL); n++;
    E.insert(vector< Edge<Te>*> ( n, n ,NULL));
    return V.insert(Vertex<Tv>(vertex()));
}





#endif // VERTEX_OPT_H
