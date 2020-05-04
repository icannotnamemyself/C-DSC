#ifndef BIN_TRAVIN_H
#define BIN_TRAVIN_H
#include "binnode.h"
#include "bintree.h"
#include "../../../Linear/Stack/Stack/stack.h"

template  <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST & visit){
    Stack<T> S;
    while(true){
        goAlongLeftBranch(x,S);
        if(S.empty()) break;
        x = S.pop();
        visit(x->data);
        x = x->rChild;
    }
}









#endif // BIN_TRAVIN_H
