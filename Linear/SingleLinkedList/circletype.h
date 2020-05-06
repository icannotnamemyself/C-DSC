#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H
#include "node.h"

typedef int ElemType;


typedef struct singleCircleList{
    LNode * head;   //哨兵头节点
    LNode * last;  //指向最后一个元素
    LNode* cur;  //记录当前指向的节点
}*SingleCircleList;


#endif // CIRCLETYPE_H
