#include <string.h>
#include "cityList.h"
#include "helper.h"

/**
 * @brief 初始化城市, 有一些默认数据
 * @param list
 * @return 状态信息
 */

Status InitCityList(SingleLinkedList* list){
    City cities[] = {
        CreateCity("BeiJing", 116, 40),
        CreateCity("Shanghai", 121, 35),
        CreateCity("XiaMeng", 118, 24),
        CreateCity("QingDao", 120, 36),
        CreateCity("LanZhou", 103, 36),
        CreateCity("NanChang",115 , 29)
    };

    InitList(list , cities, 6);


}
/**
 * @brief CreateCity
 * @param name
 * @param longtitude
 * @param latitude
 * @return
 */
City CreateCity(char * name , int longtitude, int latitude){
    City city = (City)malloc(sizeof(struct city));

    //数据拷贝
    strcpy(city->name , name);
    city->longtitude = longtitude;
    city->latitude = latitude;
}

/**
 * @brief 删除指定索引的城市
 * @param list
 * @param pos
 * @return 状态信息
 */
ElemType DeleteCity(SingleLinkedList list, City city){
    int pos = FindElem(list , city);

    return ListDelete(list , pos);
}

/**
 * @brief 在开头处插入城市
 * @param list
 * @param city
 * @return 状态信息
 */
Status InsertCity(SingleLinkedList list, City city){
    ListInsert(list , 0,city);
    return OK;
}

/**
 * @brief 根据索引来查找城市
 * @param list
 * @param pos
 * @return
 */
City FindCity(SingleLinkedList list , City city){

    //先用名字找
    City ci = FindCityByName(list,city->name);

    //没找到再用位置找
    return ci?ci : FindCityByPosition(list, city->longtitude, city->latitude);
}

/**
 * @brief 根据索引来更新城市
 * @param list
 * @param pos
 * @param city 新城市信息
 * @return 状态信息
 */

Status UpdateCity(SingleLinkedList list , City city, City newCity){

    //这里的city值与c一样,但是不指向链表中的元素
    City c = FindCity(list , city);
    if(!c)
        //可能未找到
        return NOT_FOUND;

    //查找之后指向链表中的元素
    int pos = FindElem(list , c);

    //调用之前定义的接口来更新(即删除再添加)
    ListDelete(list ,pos);
    ListInsert(list ,pos, newCity);
    return OK;
}


int IsEqualCity(City c1 , City c2){

    if((c1->latitude == c2->latitude && c1->longtitude == c2->longtitude )||
            (strcmp(c1->name , c2->name ) == 0))
        return TRUE;
    return FALSE;
}


/**
 * @brief 根据坐标来查找城市
 * @param list
 * @return
 */
City FindCityByPosition(SingleLinkedList list, int longtiude, int latitude){
    City city =   getEqualElem(list , CreateCity("", longtiude,latitude), IsEqualCity);
    // 若返回NULL则未找到
    return city;
}


/**
 * @brief 根据名称来查找城市
 * @param list
 * @param name
 * @return
 */
City FindCityByName(SingleLinkedList list,  char * name){
    City city =   getEqualElem(list , CreateCity(name, 0,0), IsEqualCity);
    // 若返回NULL则未找到
    return city;
}

Status printCity(City city){

    char str[80];
    char  longt[20];
    char  latit[20];


    strcpy(str, city->name);
    strcat(str, "(");
    strcat(str, itoa(city->latitude,latit,10));
    strcat(str , ",");
    strcat(str, itoa(city->longtitude,longt,10));
    strcat(str, ")");
    printf("%s\n", str);

    return FALSE;
}


double CalcCityDistance(City city1 , City city2){
    return CalcDistance(city1->longtitude, city1->latitude,city2->longtitude, city2->latitude);
}



