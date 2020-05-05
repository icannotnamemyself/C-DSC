#ifndef CMENU_H
#define CMENU_H
#include "SingleLinkedList.h"

//菜单选择初始化城市链表
void MenuInitList(SingleLinkedList *);

//菜单选择打印城市链表
void MenuPrintList(SingleLinkedList );

//菜单选择插入城市链表
void MenuInsert(SingleLinkedList );

//菜单选择在链表中查找城市
void MenuFind(SingleLinkedList );

//菜单选择获取某一范围内的城市
void MenuGetElem(SingleLinkedList );

//菜单选择删除城市链表中的指定城市
void MenuDelete(SingleLinkedList );


//更新城市链表的某一城市
void MenuUpdate(SingleLinkedList );

//获取城市间距离
void MenuGetDistance(SingleLinkedList list);


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
        printf("*  *  *  *  *  *  *  *  *  *  g.get city  distance             *  *  *  *  *  *  *  *\n");
        printf("*  *  *  *  *  *  *  *  *  *  h.exit                    *  *  *  *  *  *  *  * \n");
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
                MenuGetDistance(list);
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







#endif // CMENU_H
