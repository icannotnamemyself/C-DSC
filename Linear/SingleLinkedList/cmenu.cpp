#include "cityList.h"

//菜单选择打印链表
void MenuPrintList(SingleLinkedList list ){
    printf("------------------------------------------------------------------\n");
    travelList(list , printCity);
    printf("--------------------------------------------------------------------\n");
}
//菜单选择初始化链表
void MenuInitList(SingleLinkedList * list){
    InitCityList(list);
}


//菜单选择插入链表
void MenuInsert(SingleLinkedList list ){

   char name[20];
   int longtitude  = 0;
   int latitude = 0;
   printf("Please enter the city name: ");
   scanf("%s" , name);

   printf("Please enter the longtitude of the city: ");
   scanf("%d", &longtitude);

   printf("Please enter the latitude of the city: ");
   scanf("%d", &latitude);

   ListInsert(list , -1, CreateCity(name , longtitude, latitude));
}


void MenuFindByName(SingleLinkedList list){
    char name[20];
   printf("Please enter the city name: ");
   scanf("%s" , name);

   City city  = FindCityByName(list , name);
   if(city)
    {
   printf("found city: ");
   printCity(city);
   }
   else
       printf("city not found");
}
void MenuFindByPosition(SingleLinkedList list){

   int longtitude  = 0;
   int latitude = 0;

   printf("Please enter the longtitude of the city: ");
   scanf("%d", &longtitude);

   printf("Please enter the latitude of the city: ");
   scanf("%d", &latitude);

   City city = FindCityByPosition(list , longtitude ,latitude);


   if(city)
    {
   printf("found city: ");
   printCity(city);
   }
   else
       printf("city not found");
}


//菜单选择查找链表
void MenuFind(SingleLinkedList  list){
    int i = 0 ;
    printf("Please enter 1 or 0.....\n   0 search by position, others search by name: ");
    scanf("%d", &i);
    i?MenuFindByName(list):MenuFindByPosition(list);
}


void MenuUpdate(SingleLinkedList list){

    char oldname[20];
    printf("Please enter the city name: ");
    scanf("%s" , oldname);

    //根据名称来查找
    City city = FindCityByName(list, oldname);


    //看是否存在
    if(city)
     {
    printf("found city: ");
    printCity(city);
    }
    else
    {
        printf("city not found");
        return ;
       }


    //输入新数据
    char name[20];

    int longtitude  = 0;
    int latitude = 0;
    printf("Please enter the new city name: ");
    scanf("%s" , name);

    printf("Please enter the new longtitude of the city: ");
    scanf("%d", &longtitude);

    printf("Please enter the new latitude of the city: ");
    scanf("%d", &latitude);


    City newcity = CreateCity(name , longtitude, latitude);

    UpdateCity(list, city,newcity);


}

//菜单选择获取范围内的城市
void MenuGetElem(SingleLinkedList list ){
    int longtitude  = 0;
    int latitude = 0;
    int distance = 0;
    printf("Please enter the longtitude: ");
    scanf("%d", &longtitude);

    printf("Please enter the latitude: ");
    scanf("%d", &latitude);


    printf("Please enter the distance: ");
    scanf("%d", &distance);


    //打印在范围内的城市信息
    travelCityInCircle(list, distance, longtitude, latitude, printCity);
}

void MenuDeleteByPosition(SingleLinkedList list){
   int longtitude  = 0;
   int latitude = 0;

   printf("Please enter the longtitude of the city: ");
   scanf("%d", &longtitude);

   printf("Please enter the latitude of the city: ");
   scanf("%d", &latitude);

   City city = FindCityByPosition(list , longtitude ,latitude);

    if(city)
     {
    printf("delete city: ");
    printCity(city);
    DeleteCity(list , city);
    }
    else
        printf("city not found");

}

void MenuDeleteByName(SingleLinkedList list){
    char name[20];
   printf("Please enter the city name: ");
   scanf("%s" , name);

   City city  = FindCityByName(list , name);

    if(city)
     {
    printf("delete city: ");
    printCity(city);
    DeleteCity(list , city);
    }
    else
        printf("city not found");

}

//菜单选择删除链表
void MenuDelete(SingleLinkedList list ){
    int i = 0 ;
    printf("Please enter 1 or 0.....\n   0 search by position, others search by name: ");
    scanf("%d", &i);
    i?MenuDeleteByName(list):MenuDeleteByPosition(list);
    MenuPrintList(list); //打印
}

void MenuGetDistance(SingleLinkedList list){
    printf("Please enter two city in the list (separated by space)): ");

    char name1[20];
    char name2[20];
    scanf("%s %s", name1, name2);

    City city1 = FindCityByName(list , name1);
    City city2 = FindCityByName(list , name2);

    //有一个是空就返回
    if(!city1 || !city2){
        printf("city doesn't exist in the list");
        return ;
    }

    printf("The distance between two city is : %lf", CalcCityDistance(city1, city2));
}
