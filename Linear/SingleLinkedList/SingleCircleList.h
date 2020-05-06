#ifndef SINGLECIRCLELIST_H
#define SINGLECIRCLELIST_H
#include "node.h"
#include "Type.h"

typedef struct singleCircleList{
    LNode * head;   //哨兵头节点
    LNode * last;  //指向最后一个元素
    LNode* cur;  //记录当前指向的节点
}*SingleCircleList;



Status initSingleCircleList(SingleCircleList list);





Status insertListEnd(SingleCircleList list, ElemType e);



#endif // SINGLECIRCLELIST_H
