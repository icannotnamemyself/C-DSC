#ifndef EDGE_H
#define EDGE_H

typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD }EStatus; //边在遍历树中所属的类型

template <typename Te> struct Edge{

    Te data;
    int weiget;
    EStatus status;
    Edge(Te const & d, int w):
        data(d), weiget(w), status(UNDETERMINED){}
};

#endif // EDGE_H
