#ifndef MATCHKMP_H
#define MATCHKMP_H
#include <cstring>

int * buildNext(char *P);

int match(char * P , char * T){
    int * next = buildNext(P);  //构造next表

    int n = (int ) strlen(T) , i = 0 ;
    int m = (int) strlen(P) , j = 0;

    while( j < m && i< n){   // j 为 P中指针要移动过去对齐去的位置, -1表示整体右移一位
        if(0>j || T[i] == P[j]){       // 如果匹配上, 则 指针都向右移动一位
            i++;
            j++;
        }
        else{
            j = next[j];  //如果没有匹配上, 就去移动j到下一个搜索位置
        }

    }


    delete [] next;
    return i - j;
}

int * buildNext(char *P){  //构造串P的 next表
    // 整个算法相当于自我匹配
    int  m = strlen(P) , j = 0;
    int * N = new int[m];

    int t = N[0] = -1;  //模式串指针( P[-1] 通配符 )

    while(j < m - 1){
        if(0 > t || P[j] == P[t])   //匹配
        {
            j ++; t++;
            N[j] = P[j] !=P[t]? t:N[t];
            // N[++j]  = ++t;  //如果和前缀相同 则不断前移计算出移动位数N[j]
        }
        else   //失配时, 即与前缀(继续)匹配时
            t = N[t];  // 如果不同, 则
    }
    return N;
}
# if 0
// 此方法有缺陷
int * buildNext(char *P){  //构造串P的 next表
    // 整个算法相当于自我匹配
    int  m = strlen(P) , j = 0;
    int * N = new int[m];

    int t = N[0] = -1;  //模式串指针( P[-1] 通配符 )

    while(j < m - 1){
        if(0 > t || P[j] == P[t])   //匹配
            N[++j]  = ++t;  //如果和前缀相同 则不断前移计算出移动位数N[j]
        else   //失配时, 即与前缀(继续)匹配时
            t = N[t];  // 如果不同, 则
    }

    return N;

}

#endif
#endif // MATCHKMP_H
