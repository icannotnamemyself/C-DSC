#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "error.h"


LNode* CreateNode(ElemType e, LNode* next){
        LNode * newNode= (LNode*)malloc(sizeof(LNode));
        if(!newNode)
        {
            printf("alloc error.....");
            //分配错误直接退出
            exit(ALLOC_ERROR);
        }
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
   prev->next = node;
    return OK;
}
