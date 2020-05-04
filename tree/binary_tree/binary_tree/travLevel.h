#ifndef TRAVLEVEL_H
#define TRAVLEVEL_H

#include "binnode.h"
#include "bintree.h"
#include "../../../Linear/Queue/queue.h"
template <typename T> template<typename VST >
void BinNode<T>::travLevel(VST & visit){
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this);
    while(!Q.empty()){
        BinNodePosi(T) x = Q.dequeue();
        visit(x->data);
        //左右孩子入队
        if(HasLChild(*x) ) Q.enqueue(x->lChild);
        if(HasRChild(*x) ) Q.enqueue(x->rChild);
    }

}






#endif // TRAVLEVEL_H
