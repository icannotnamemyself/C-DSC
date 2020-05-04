#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include "Type.h"
#include "node.h"
#include "error.h"


//单向链表类型
typedef LNode *SingleLinkedList;


/**
 * @brief InitList , 头插法初始化链表
 * @param list  需要初始化的链表
 * @return 状态信息 -1表示出错, 1表示正常
 */
Status InitList(SingleLinkedList * list, ElemType*e, int length);


/**
 * @brief 链表元素删除
 * @param list: 操作的链表
 * @param i : 要删除的位置, 从0开始计数
 * @return 返回删除节点的数据元素
 */
ElemType ListDelete(SingleLinkedList  list, int i);

/**
 * @brief 在目标节点后面插入元素
 * @param list
 * @param i  要插入的位置, -1代表在头节点后面插入 , i太大时直接在末尾插入
 * @param e  要插入的数据元素
 * @return  返回状态码
 */
Status ListInsert(SingleLinkedList list, int i , ElemType e);


/**
 * @brief  根据索引获取值
 * @param list
 * @param i  获取的索引
 * @return
 */
ElemType GetElem(SingleLinkedList list, int i);


/**
 * @brief 查找元素为e的节点的索引, -1表示未查找到
 * @param list
 * @param e 所查找的元素
 * @return   返回元素的索引位置
 */
int FindElem(SingleLinkedList list, ElemType e);
/**
 * @brief 清空释放整个链表
 * @param list
 * @return
 */
Status DestroyList(SingleLinkedList  list);


/**
 * @brief 清空整个链表(不包括头节点)
 * @param list
 * @return 状态信息
 */
Status ClearList(SingleLinkedList  list);


/**
 * @brief printList 打印链表
 * @param list
 * @return
 */
Status printList(SingleLinkedList list);


/**
 * @brief 提供遍历该单向链表的接口
 * @param list
 * @return
 */
ElemType travelList(SingleLinkedList list, int (*visitor)(ElemType e));


/**
 * @brief 寻找相等的元素
 * @param 函数指针, 判断两个元素是否相等的指针, 相等时返回TRUE , 不相等时返回FALSE
 * @param list
 * @return
 */
ElemType getEqualElem(SingleLinkedList list ,ElemType e, int (*isequal)(ElemType e1, ElemType e2));



/**
 * @brief 遍历在圈里的所有城市, 可以指定遍历的方式
 * @param list
 * @param r : 半径
 * @param longtitude  : 经度
 * @param latitude  : 纬度
 * @return
 */
ElemType travelCityInCircle(SingleLinkedList list ,
                            int r,
                            int longtitude,
                            int latitude,
                            int (*visit)(ElemType e));




#endif // SINGLELINKEDLIST_H
