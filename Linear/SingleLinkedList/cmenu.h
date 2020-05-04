#ifndef CMENU_H
#define CMENU_H
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

//更新城市链表
void MenuUpdate(SingleLinkedList );



void init() {
    char c;
    SingleLinkedList list = NULL;
    printf("city data initalizing .......\n");
    MenuInitList(&list);
    while(1) {
        printf("*  *  *  *  *  *  *  *  *  *  a.print city list            *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  b.insert city             *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  c.find city                 *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  d.delete city            *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  e.find city in circle         *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  f.update city               *  *  *  *  *  *  *  *\n");
        printf("*  *  *  *  *  *  *  *  *  *  g.exit                    *  *  *  *  *  *  *  * \n");
        //初始化菜单
        putchar('\n');
        MenuPrintList(list);
        printf("Please enter a option:");
        scanf("%c", &c);
        printf("\n");

        switch(c) {
            case 'a' :{
                MenuPrintList(list);
                getchar();
                printf("\n");
            } break;
            case 'b' :{
                MenuInsert(list);
                getchar();
                printf("\n");
            } break;
            case 'c' :{
                MenuFind(list);
                getchar();
                printf("\n");
            } break;
            case 'd' :{
                MenuDelete(list);
                getchar();
                printf("\n");
            } break;
            case 'e' :{
                MenuGetElem(list);
                getchar();
                printf("\n");
            } break;

            case 'f' :{
                MenuUpdate(list);
                getchar();
                printf("\n");
            } break;
            case 'g' :{
            DestroyList(list);
                exit(0);
            }
        }

        printf("enter something to continue.....");
        getchar();
    }

}







#endif // CMENU_H
