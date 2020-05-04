#include "SingleLinkedList.h"
#include "stdlib.h"
#include "stdio.h"


Status InitList(SingleLinkedList  * list, ElemType * e, int length){
    //数据为null,指向null
    *list= CreateNode(NULL, NULL);
    //建立头节点
    LNode * header  =* list;

    //头插法插入元素
    for(int i = 0 ; i < length; i++){
        //新建节点, 头插法因此指向头节点下一个元素
        LNode * newNode = CreateNode(e[i] , header->next);
        if(newNode == NULL)
            return ALLOC_ERROR;

        //更新首元素节点
        header->next = newNode;
    }

    return OK;
}

/**
 * @brief ListDelete, 删除第i个位置(从0开始)的元素
 * @param list
 * @param i
 * @return  返回被删除的元素的数据
 */
ElemType ListDelete(SingleLinkedList  list, int i){
    //保存上一个节点
    LNode * prev = list;
    //保存寻找到的节点
    LNode * node = list->next;

    //寻找节点
    while(i--){
        prev = node;
        node = node->next;
    }

    prev->next = node->next;   //更新上一个节点的next指针

    ElemType data = node->data;

    DestoryNode(node);   //销毁node

    return data;
}


/**
 * @brief ListInsert: 在目标节点之后插入节点
 * @param list
 * @param i : 插入位置, 若为负数代表插入第一个节点之后, 若超出链表长度则在末尾插入
 * @param e
 * @return  返回状态信息
 */
Status ListInsert(SingleLinkedList list, int i , ElemType e){
    //查找到节点
    //保存上一个节点
    LNode * prev = list;
    //保存寻找到的节点
    LNode * node = list->next;

    //寻找节点
    while(i-- >=0 &&node!=NULL){
        prev = node;
        node = node->next;
    }
    //插入节点
    return InsertAfter(prev, e);
}

ElemType GetElem(SingleLinkedList list, int i){
    //保存寻找到的节点
    LNode * node = list->next;

    //如果没有元素直接退出
    if(node == NULL){
        printf("list is empty");
        exit(1);
    }

    //寻找节点
    while(i-- >0 && node->next !=NULL){
        node = node->next;
    }
    return node->data;
}

/**
 * @brief 查找元素
 * @param list
 * @param e
 * @return 找不到返回NOT_FOUND, 找到返回索引
 */
int FindElem(SingleLinkedList list, ElemType e){
    int i = 0;
    int find = FALSE;  //默认未找到
    LNode * first= list->next;
    while(first!=NULL){
        if(first->data == e){
            find = TRUE;
            break;
           }
        first = first->next;
        i++;
    }

    return find?i:NOT_FOUND;
}


Status ClearList(SingleLinkedList  list){
    LNode * node = list->next;
    if(node == NULL)
        return  OK;

    LNode *next = node->next;

    while(next != NULL){
        DestoryNode(node);
        node = next;
        next = next->next;
    }
    list->next = NULL;


    return OK;
}

Status DestroyList(SingleLinkedList  list){
    ClearList(list);
    DestoryNode(list);  //头节点也删除掉, 需要重新初始化才可以使用了
    list = NULL;//重新置为未初始化
}
// 打印链表
Status printList(SingleLinkedList list){
    LNode *  first= list->next;

    printf("  list->");
    while(first){
        if(first->next !=NULL)
            printf("[%d] ->", first->data);
        else
            printf("[%d] ", first->data);
        first = first->next;
    }
    putchar('\n');
    return OK;
}


ElemType travelList(SingleLinkedList list, int (*visit)(ElemType e)){
    // 返回1 时停止
    LNode * first = list->next;

    while(first){
        //若返回TRUE(1)停止访问
        if(visit(first->data))
            return first->data;
        first= first->next;
    }
    return NULL;
}

ElemType getEqualElem(SingleLinkedList list ,ElemType e, int (*isequal)(ElemType e1, ElemType e2)){
    // 返回1 时停止
    LNode * first = list->next;

    while(first){
        //若相等停止访问, 返回元素
        if(isequal(first->data, e))
            return first->data;
        first= first->next;
    }
    return NULL;
}

ElemType travelCityInCircle(SingleLinkedList list ,
                            int r,
                            int longtitude,
                            int latitude,
                            int (*visit)(ElemType e)
                            ){
    // 返回1 时停止
    LNode * first = list->next;

    while(first){
        //若在圈子里则访问元素
        ElemType city = first->data;
        if((    (city->latitude - latitude )*(city->longtitude - latitude)
                +(city->longtitude - longtitude)*(city->longtitude - longtitude))
                <r*r)
            visit(city);

        first = first->next;
    }

    return NULL;
}
