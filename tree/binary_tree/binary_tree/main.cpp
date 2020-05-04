#include <vector>
#include "binnode.h"
#include "bintree.h"
#include "binTreeLib.h"

using namespace std;



template <typename T>
class A{
public:
    A(){}
    ~A(){}

};


void myPrint(int a){
    cout<<a<<endl;
}

int main()
{
    vector<int> v(3);
    cout<<v.size();
    v.push_back(3);
    cout<<v.size();
    cout<<v[3]<<endl;
    v[0] = 88;
    cout<<v[0]<<endl;



    return 0;
}
