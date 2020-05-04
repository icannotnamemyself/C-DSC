#ifndef TYPE_H
#define TYPE_H

typedef struct city {
    char name[20];  //名字
    int latitude;   // 维度
    int longtitude;   // 经度
}*City;

typedef City ElemType;

typedef int Status;

#define FALSE 0
#define TRUE 1

#endif // TYPE_H
