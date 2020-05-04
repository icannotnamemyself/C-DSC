#include <stdio.h>
# if 0
typedef struct node{

    int val;
    int id;  // 唯一标识
    int frequency; //查找频率, 初始化时为 0, head 的查找频率始终为-1
    struct node * next;
    struct node * prev;
}Node;
typedef struct list{
    Node * head;
    Node * tail;
}List;


/**
  *指定搜索算法搜索指定节点
  * */
Node * searchNode(List * list, int searchId  ,Node * (*search)(List *,int )){
    // 备份头指针
    Node * head = list->head;

   Node * snode = 	search(list , searchId);
   snode->frequency++;  //查找完毕后频率加1


   // 先找到插入的位置, 也就是从链表最左端开始,跳过频率比当前节点大的位置
   Node *  inserPos = list->tail; //插入位置
   Node * curPos = head; // 当前查找位置
   while(snode->frequency <= curPos->frequency && (curPos != snode))
       curPos = curPos->next;

  // 插入到查找位置的前面
   if(curPos != snode)
   {
        inserPos = curPos;
       inserAfter(inserPos , snode);
   }

   return snode;
}


/**
  * 根据传递进来的函数指针进行访问操作
  **/
void traverse(List list , (*fun)(int a)){
    // 拷贝指针
    Node * cur = list.head;
    while(cur!=NULL){   //若为空则停止遍历
        fun(cur->val);   // 访问值
        cur = cur->next;  //移动指针
    }

}


#endif

int main()
{

    printf("Hello World!\n");
    return 0;
}
