#include <iostream>
#include "SingleLinkedList.h"
#include "cmenu.h"

using namespace std;

int main()
{
    //City city = CreateCity("name" ,30,30);
    init();

    //printCity(city);

    return 0;
}


void testList(){
    SingleLinkedList SList = NULL;
    int arr[] = {1,2,3,4	,5,6};
    int arr1[] = {6};

    //InitList(&SList, arr1, 1);
    //InitList(&SList, arr, 6);
    printList(SList);
    ListDelete(SList, 0);
    printList(SList);
    //ListInsert(SList,323,3);
    printList(SList);

    //printf("find element index:%d",FindElem(SList,  3));


}
