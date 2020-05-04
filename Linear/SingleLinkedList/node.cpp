#include "node.h"
#include "error.h"

LNode* CreateNode(ElemType e, LNode* next){
        LNode * newNode= (LNode*)malloc(sizeof(LNode));
        if(!newNode)
            //申请失败返回NULL
            return NULL;
        newNode->data = e;

        newNode->next = next;
        return newNode;
}

Status DestoryNode(LNode * node){
    node->next = NULL;
    node->data = NULL;
    free(node);
    return OK;
}

Status InsertAfter(LNode* prev , ElemType e){
    //新建节点
   LNode * node =  CreateNode(e, prev->next);
   if(node ==NULL)
       return ALLOC_ERROR;
   prev->next = node;
    return OK;
}
