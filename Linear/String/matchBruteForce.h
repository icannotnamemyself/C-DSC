#ifndef STRING_MATCH_H
#define STRING_MATCH_H

#include <cstring>

/***
 * Brute Force 版本一 在 T 中搜索P
 * 向前搜索, 有不同就回退, i动j动
 * P: pattern
 * T: String search in
 * */
# if 0
int match(char *P , char *T){
    int  n = strlen(T) , i = 0; //i 代表 T当前搜索位置
    int m = strlen(P), j = 0;  //j 代表P当前搜索位置

    while(j<m && i < n){

        if(T[i] == P[j])
        {
            i++;
            j++;
        }
        else{
            i -= j-1; // j-1代表先前移动的距离, 利用它进行回退
            j = 0;  //让P从头再开始搜索
        }
    }

    return i - j;   // i -j 代表搜索到的位置, 也即对齐位置
}

# endif


/**
   Brute Force: i 不动, j 动
 * @brief match
 * @param P : pattern searching
 * @param T : String search in
 * @return 搜索到的位置 i
 */

int match(char *P , char *T){
    int  n = strlen(T) , i = 0; // T[i] 与 P[0] 对齐
    int m = strlen(P), j = 0;  //T[i + j] 与 P[j] 对齐


    for( i = 0; i <n - m +1 ; i++){  //T 从 第 i 个字符起, 与
        for ( j = 0;j < m ; j++) // P中对应的字符逐个比对
        {
            if(T[ i + j] != P[j]) break; //若失配, P整体右移一个字符, 重新比对
            if(  m <= j ) break; //找到匹配子串
        }
    }
    return i ;   // i 代表搜索到的位置, 也即对齐位置
}




#endif // STRING_MATCH_H
