#ifndef STACK_H
#define STACK_H
#include <vector>

using std::vector;


template <typename T>
class Stack : public vector<T>
{
public:

    void push(T const & e){this->push_back(e); }
    T pop() {T e =this->at(this->size() - 1) ;  this->pop_back(); return e;}
    T & top() { return (*this)[this->size() - 1]; }
};

#if 0
void convert( Stack<char> & S , long n , int base )
{
   static char digit[] = { '0', '1' ,'2','4','5','6','7','8','9','A','B','C','D','E','F'  };
   while(n > 0)
   {
    S.push(digit[ n % base ]);
    n /= base;
   }
}
#endif


#if 0
bool paren(const char exp[] , int lo, int hi) //exp[lo , hi)
{
    Stack <char> S;
    for( int i = lo ; i < hi ; i++)
    {
        if( '(' == exp[i] ) S.push(exp[i]);
        else if(!S.empty() ) S.pop();
        else return false;
    }
    return S.empty();
}

#endif

#endif // STACK_H
