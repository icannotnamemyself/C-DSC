#ifndef NODE_H
#define NODE_H
#include "type.h"
//节点数据结构
typedef struct node{
    ElemType data;  //数据域
    struct node * next; //下一个节点的指针
}LNode;


/**
 * @brief 新建节点
 * @param e : 节点存储的数据
 * @param next : 节点指向的下一个节点
 * @return 指向该节点的指针
 */
LNode* CreateNode(ElemType e, LNode* next);

/**
 * @brief 清空释放节点
 * @param node: 需要清空释放的节点
 * @return 释放成功正常返回OK状态码
 */
Status DestoryNode(LNode * node);

/**
 * @brief 在prev节点 与 node节点之间插入新的节点
 * @param prev : 前一个节点
 * @param e : 插入节点的数据
 * @return 正常返回OK
 */
Status InsertAfter(LNode* prev , ElemType e);


#endif // NODE_H
