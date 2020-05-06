#ifndef TYPE_H
#define TYPE_H

typedef struct person{
    int index;   //每个人的索引
    int pass;   //每个人手中的密码
}*Person;

/**
 * @brief CreatePerson
 * @param pass
 * @param index
 * @return
 */
Person CreatePerson(int pass, int index);

typedef Person ElemType;

typedef int Status;

#define FALSE 0
#define TRUE 1


//差错控制
#define INPUT_ERROR -3 //输入错误
#define PARAM_ERROR -4 //函数参数错误
#define ALLOC_ERROR -5//内存分配错误
#define NOT_FOUND -2 //未找到错误
#define ERROR -1  //表示未知错误
#define OK 1  //表示返回正确


#endif // TYPE_H
