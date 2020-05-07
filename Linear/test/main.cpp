#include <iostream>
#include <time.h>
using namespace std;


/**
 * @brief main
 * @return
 *  账号、姓名、开户年月日、储蓄类型、存入累加数、利息、帐面总数。
 */


typedef struct account{
    char number[12];   //账号
    char name[20]; //姓名

    enum {
        CURRENT,  //活期存储
        FIXED   //定期存储
    }DepositType;  //存储类型

    int openYear;  //开户年
    int openMonth; //开户月
    int openDay; //开户日

    double depTotal; //存入类加数

    double  interest;// 利息

    double value;//账户面值
}Account;

int main()
{
    Account a;
    a.DepositType  = a.FIXED;

    cout << "Hello World!" << endl;
    return 0;
}
