#include "SingleCircleList.h"
#include "error.h"




Status initSingleCircleList(SingleCircleList list){
      //不指向节点也不保存数据
      list->last =  list->head = CreateNode(NULL,NULL);
      if(list->last == NULL)
          return  ALLOC_ERROR;

      return OK;
}

Status insertListEnd(SingleCircleList list, ElemType e){

    if(list->last == list->head){
        //如果还没有元素, 建立指向自己的新节点
        LNode * newNode = CreateNode(e,newNode);
        if(!newNode)
            return ALLOC_ERROR;
        //移动末元素指针
        list->last = newNode;
        return OK ;
    }

    //调用LNode函数接口, 插入到last后面
    if(InsertAfter(list->last,e)==ALLOC_ERROR)
        exit(-1);   //分配错误直接退出.

    list->last = list->last->next;
}
