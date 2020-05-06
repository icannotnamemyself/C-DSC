#ifndef SINGLECIRCLELIST_H
#define SINGLECIRCLELIST_H
#include <stdlib.h>
#include "node.h"
#include "type.h"

typedef struct singleCircleList{
    LNode * head;   //哨兵头节点
    LNode * last;  //指向最后一个元素
}*SingleCircleList;



/**
 * @brief 使用链表进行约瑟夫环的实验
 * @param list
 * @param m 初始密码
 */
void PlayJoseph(SingleCircleList list,int m);

/**
 * @brief 初始化链表
 * @param list
 * @return 状态信息
 */
Status initSingleCircleList(SingleCircleList* list);

/**
 * @brief 使用尾插法插入链表末尾
 * @param list
 * @param e
 * @return 状态信息
 */
Status insertListEnd(SingleCircleList list, ElemType e);

/**
 * @brief 删除链表节点
 * @param list
 * @param prev  所删除节点的前一个节点
 * @param node 要删除的节点
 * @return 状态信息
 */
Status ListDeleteNode(SingleCircleList list,LNode * prev, LNode*node);


/**
 * @brief 链表判空
 * @param list
 * @return 1 为空, 0为非空
 */
int ListIsEmpty(SingleCircleList list);



/**
 * @brief ClearCircleList
 * @param list
 * @return
 */
Status ClearCircleList(SingleCircleList list);

/**
 * @brief DestroyList
 * @param list
 * @return
 */
Status DestroyList(SingleCircleList list);



/**
 * @brief printCircleList
 * @param list
 * @return
 */
Status printCircleList(SingleCircleList list);



#endif // SINGLECIRCLELIST_H
