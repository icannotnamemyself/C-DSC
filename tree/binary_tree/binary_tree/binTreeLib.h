#ifndef BINTREELIB_H
#define BINTREELIB_H
#include "bintree.h"



    //preorder recursive traverse  先序递归遍历
    template<typename T, typename VST>
    void traverse(BinNodePosi(T) x , VST & visit){
        if(!x) return;
        visit(x->data);
        traverse(x->lChild, visit);
        traverse(x->rChild , visit);
    }



#endif // BINTREELIB_H
