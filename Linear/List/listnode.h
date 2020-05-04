#ifndef LISTNODE_H
#define LISTNODE_H
#include <cstdlib>

typedef int Rank; //秩
#define ListNodePosi(T) ListNode<T>* //列表节点位置


template< typename T>
class ListNode
{
public:
    //构造函数
    ListNode();
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
        : data(e) , pred(p) , succ(s) {}


    //公有成员
    T data;
    ListNodePosi(T) pred; //前驱
    ListNodePosi(T) succ; //后继


    //操作接口
    ListNodePosi(T) insertAsPred(T const& e); //紧靠当前节点之前插入新节点
    ListNodePosi(T) insertAsSucc(T const& e); //紧随当前节点之后插入新节点
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e){
    ListNodePosi(T) x = new ListNode<T>(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e){
    ListNodePosi(T) x = new ListNode<T>(e,this,succ);
    succ->pred = x;
    succ = x;
    return x;
}


#endif // LISTNODE_H
