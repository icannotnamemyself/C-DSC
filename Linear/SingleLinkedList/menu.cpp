#include "SingleLinkedList.h"
#include "Type.h"

# if 0
//菜单选择初始化链表:测试成功
void MenuInitList(SingleLinkedList * list){
    printf("initializing----\n");
    printf("insert some default data: 1 2 3 4 5 6 \n");
    int arr[] = {1,2,3,4	,5,6};
    if(InitList(list, arr, 6)==OK)
    {
        printf("successfully initialized\n");
        printList(*list);
    }
    else{
        printf("initialization failed\n");
    }
}

//菜单选择打印链表
void MenuPrintList(SingleLinkedList list ){
    if(list == NULL)
    {
        printf("please init the list");
        return ;
    }
    printf("list is shown below\n");
    printList(list);
}

//菜单选择插入链表
void MenuInsert(SingleLinkedList list ){
    if(list == NULL)
    {
        printf("please init the list");
        return ;
    }
    printf("please enter the position to insert after: -1 if you want to insert after the header\n");
    int i = 0;
    scanf("%d", &i);

    printf("Please enter the element you want to insert:");
    int e = 0 ;
    scanf("%d",&e);
    if(ListInsert(list , i, e ) == OK)
    {
        printf("insert successfully");
        printList(list);
    }
    else{
        printf("insert failed");
    }
}

//菜单选择查找链表
void MenuFind(SingleLinkedList list ){
    if(list == NULL)
    {
        printf("please init the list");
        return ;
    }
    printf("Please enter the element you want to find:");
    ElemType i = 0;
    scanf("%d", &i);

    int index = -1;
    if((index= FindElem(list ,i)) == NOT_FOUND){
        printf("the element is not exits in the list");
    }
    else{
        printf("the index of the element is:%d",index);
    }
}

//菜单选择删除链表
void MenuDelete(SingleLinkedList list ){
    if(list == NULL)
    {
        printf("please init the list");
        return ;
    }
    printf("please enter the position of element\n");
    int i = 0;
    scanf("%d", &i);

    ElemType e= ListDelete(list, i);
    printf("deleted successfully!!\n");
    printf("now the list is :");
    printList(list);

    printf("the element you deleted is :%d", e);
}

void MenuGetElem(SingleLinkedList list){
    if(list == NULL)
    {
        printf("please init the list");
        return ;
    }

    printf("please enter the position of element\n");
    int i = 0;
    scanf("%d", &i);

    ElemType e = GetElem(list , i);

    printf("the element is : %d", e);

}

//菜单选择清空链表
void MenuClear(SingleLinkedList list ){
    if(list == NULL)
    {
        printf("please init the list");
        return ;
    }
    if(ClearList(list) == OK)
        printf("clear succesfully");
    else{
        printf("clear failed");
    }
}



#endif


