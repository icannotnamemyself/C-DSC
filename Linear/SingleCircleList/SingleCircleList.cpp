#include <stdio.h>
#include <stdlib.h>
#include "SingleCircleList.h"

Status initSingleCircleList(SingleCircleList* list){
      //不指向节点也不保存数据

      *list = (SingleCircleList)malloc(sizeof (struct singleCircleList)) ;
     (*list)->last =   (*list)->head = CreateNode(NULL,NULL);
      return OK;
}

Status insertListEnd(SingleCircleList list, ElemType e){
    if(list->last == list->head){
        //如果还没有元素, 建立指向自己的新节点
        LNode * newNode = CreateNode(e,NULL);
        //移动末元素指针
        newNode->next = newNode;
        list->head->next = newNode;
        list->last = newNode;
        return OK ;
    }
    //调用LNode函数接口, 插入到last后面

    LNode * node =  CreateNode(e, list->head->next);
    list->last->next = node;

    list->last = node;   //更新last位置
    return OK;
}

Status ClearCircleList(SingleCircleList list){
    list->last->next = NULL;

    LNode * node =list->head->next;
    if(node == NULL)
        return  OK;

    LNode *next = node->next;

    for(;;){
        DestoryNode(node);
        node = next;
        if(node == NULL)
            break ;
        next = next->next;
    }

    list->last = list->head;
    list->head->next = NULL;

    return OK;
}

Status DestroyList(SingleCircleList list){
    ClearCircleList(list);
    free(list->head); // 释放头节点
    free(list);  // 释放链表节点
    return OK;
}

Status printCircleList(SingleCircleList list){
    //假定以及初始化

    printf("[index | pass]:");
    LNode *  node= list->head;
    if(!node)  //如果没有元素直接返回
        return OK;
    printf("head->");

    while(node != list->last){
         node = node->next;
        printf("[ %d | %d ]->", node->data->index,node->data->pass);
     }

    return OK;
}

Status ListDeleteNode(SingleCircleList list,LNode * prev, LNode*node){
    //更新前驱指针的指向
    prev->next = node->next;
    //如果是尾元素节点
    if(node == list->last)
    {

        list->last->next = NULL;

        //如果last就是head->next, 那么last就直接变成head(prev可能不是head而与node相等)
        if(list->last == list->head->next)
            list->last = list->head;
        else
             list->last = prev;
    }

    //如果node是首元素节点..
    if(node == list->head->next)
        list->head->next = node->next;
    //内存清空
    free(node->data);
    free(node);
    return  OK;
}
//Status VisitCircleList(SingleCircleList list, int (*visit)(ElemType e)){

//    LNode * first = list->head->next;

//   for(;;){
//       visit(first->data);
//        first = first->next;
//       if(first == list->last)
//           break;
//    }
//}


int ListIsEmpty(SingleCircleList list){
    //若头节点指向空则链表为空
    if(!list->head->next )
        return TRUE;
    return FALSE;
}


void PlayJoseph(SingleCircleList list, int m){
    LNode * prev = list->head;
    LNode * node = list->head->next;

    while(!ListIsEmpty(list)){

         //如果到0, 那么就更新m的值并且删除节点
        if(!--m){
            m = node->data->pass;
            printf("%d  ",node->data->index);


            //删除释放node
            ListDeleteNode(list ,prev ,node);

            //prev 不移动, node往前移动

            node = prev->next;

        }else{
            //往前移动
            prev = prev->next;
            node = node->next;
        }
    }
}

