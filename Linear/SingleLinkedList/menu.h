#ifndef MENU_H
#define MENU_H
#include "SingleLinkedList.h"


//菜单选择初始化链表
void MenuInitList(SingleLinkedList *);

//菜单选择打印链表
void MenuPrintList(SingleLinkedList );

//菜单选择插入链表
void MenuInsert(SingleLinkedList );

//菜单选择查找链表
void MenuFind(SingleLinkedList );

//菜单选择获取
void MenuGetElem(SingleLinkedList );

//菜单选择删除链表
void MenuDelete(SingleLinkedList );

//菜单选择清空链表
void MenuClear(SingleLinkedList );




void init() {
    char c;
    SingleLinkedList list = NULL;
    while(1) {
        printf("*  *  *  *  *  *  *  *  *  *  a.init list              *  *  *  *  *  *  *  *\n");
        printf("*  *  *  *  *  *  *  *  *  *  b.print list            *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  c.insert element    *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  d.find element       *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  e.delete element   *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  f.get element        *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  g.clear list 	     	*  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  h.exit                    *  *  *  *  *  *  *  * \n");
        printf("Please enter a option:");
        scanf("%c", &c);
        printf("\n");
        switch(c) {
            case 'a' :{
                MenuInitList(&list);
                getchar();
                printf("\n");
            } break;
            case 'b' :{
                MenuPrintList(list);
                getchar();
                printf("\n");
            } break;
            case 'c' :{
                MenuInsert(list);
                getchar();
                printf("\n");
            } break;
            case 'd' :{
                MenuFind(list);
                getchar();
                printf("\n");
            } break;
            case 'e' :{
                MenuDelete(list);
                getchar();
                printf("\n");
            } break;
            case 'f' :{
                MenuGetElem(list);
                getchar();
                printf("\n");
            } break;

            case 'g' :{
                MenuClear(list);
                getchar();
                printf("\n");
            } break;

            case 'h' :{
            DestroyList(list);
                exit(0);
            }
        }

        printf("enter something to continue.....");
        getchar();
    }

}



#endif // MENU_H
