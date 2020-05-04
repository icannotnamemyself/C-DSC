#ifndef CITYLIST_H
#define CITYLIST_H

#include <string.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

/**
 * @brief CreateCity
 * @param name
 * @param longtitude
 * @param latitude
 * @return
 */
City CreateCity(char * name , int longtitude, int latitude);


/**
 * @brief 初始化城市, 有一些默认数据
 * @param list
 * @return 状态信息
 */
int InitCity(SingleLinkedList* list);

/**
 * @brief 删除链表中的城市
 * @param list
 * @param pos
 * @return 状态信息
 */
ElemType DeleteCity(SingleLinkedList list, City city);

/**
 * @brief 在指定索引处插入城市
 * @param list
 * @param pos 指定的索引
 * @param city
 * @return 状态信息
 */
int InsertCity(SingleLinkedList list, City city);

/**
 * @brief 根据索引来查找城市
 * @param list
 * @param pos
 * @return
 */
City FindCity(SingleLinkedList list , City city);

/**
 * @brief UpdateCity
 * @param list
 * @param city 要寻找的与该city数据相同的city
 * @param newCity
 * @return  状态信息
 */
Status UpdateCity(SingleLinkedList list ,City city, City newCity);


/**
 * @brief 判断城市是否相等
 * @param c1
 * @param c2
 * @return
 */
int IsEqualCity(City c1 , City c2);

/**
 * @brief 根据坐标来查找城市
 * @param list
 * @return
 */

City FindCityByPosition(SingleLinkedList list, int longtiude, int latitude);


/**
 * @brief 根据名称来查找城市
 * @param list
 * @param name
 * @return
 */
City FindCityByName(SingleLinkedList list,  char * name);


/**
 * @brief printCity
 * @param city
 * @return
 */
Status printCity(City city);
#endif // CITYLIST_H
