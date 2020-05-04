#include <iostream>
#include <vector>
#include <stack.h>

using namespace std;


int main()
{
    Stack <int> s;
    s.push(3);
    cout<<s.pop();
    s.push(3);
    s.push(4);
    cout<<"here";
    s.push(5);
    s.push(6);
    cout<<s.pop();
    cout<<s.top();
    return 0;
}
