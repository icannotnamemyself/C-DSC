#include <stdio.h>
#include "SingleCircleList.h"


//初始化
void MenuInitList(SingleCircleList * list){
    initSingleCircleList(list);
    putchar('\n');
}

void MenuPlay(SingleCircleList list){

    //输入m
    printf("Please enter m:");
    int m ;
    scanf("%d", &m);

    printf("Please enter the passwords(separated by space):");

    int count = 1;
    int pass = 0;


    //输入密码列表, 空格隔开
    char ch;
    do{
        scanf("%d", &pass);
        insertListEnd(list,  CreatePerson(pass, count++));
    }while((ch=getchar())!='\n');
    printf("sequence:");
    printCircleList(list);
    putchar('\n');putchar('\n');
    printf("out sequence:");
    PlayJoseph(list , m);

}
void MenuExit(SingleCircleList list){
    DestroyList(list);
    exit(0);
}

