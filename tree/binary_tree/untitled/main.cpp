#include <vector>
#include "binnode.h"
#include <cstdlib>

using namespace std;

int main()
{
    BinNode<int>* root = new BinNode<int>();
    root->data = 3;
    root->insertAsLC(3);
    root->insertAsRC(3);



    return 0;
}
