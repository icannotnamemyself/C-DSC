#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include "SingleCircleList.h"

//初始化链表
void MenuInitList(SingleCircleList *);

//选择玩约瑟夫环
void MenuPlay(SingleCircleList);

//选择退出
void MenuExit(SingleCircleList list);


void init() {
    char c;
    SingleCircleList list = NULL;
    printf(" initalizing .......\n");
    MenuInitList(&list);
    while(1) {
        printf("*  *  *  *  *  *  *  *  *  *  a.play joseph           *  *  *  *  *  *  *  * \n");
        printf("*  *  *  *  *  *  *  *  *  *  b.exit                    *  *  *  *  *  *  *  * \n");
        //初始化菜单
        putchar('\n');
        printf("Please enter a option:");
        scanf("%c", &c);
        printf("\n");

        switch(c) {
            case 'a' :{
                MenuPlay(list);
                getchar();
                printf("\n");
            } break;
            case 'b' :{
            MenuExit(list);
            }
        }
        printf("enter something to continue.....");
        getchar();
    }

}




#endif // MENU_H
