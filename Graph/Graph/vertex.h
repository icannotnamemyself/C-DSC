#ifndef VERTEX_H
#define VERTEX_H
#include "graph.h"

//typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //顶点状态

template <typename Tv> struct Vertex{
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    int dTime, fTime;
    int parent;
    int priority;
    Vertex(Tv const & d):
        data(d), inDegree(0),outDegree(0), status(UNDISCOVERED),
        dTime(-1), fTime(-1), parent(-1),
        priority(INT_MAX){}


};

#endif // VERTEX_H
