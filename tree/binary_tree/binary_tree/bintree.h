#ifndef BINTREE_H
#define BINTREE_H

#include "binnode.h"
#include "../../../Linear/Stack/Stack/stack.h"


// BinTree -> BinTree<T>   BinTree * -> BinTree<T> *
template<typename T>
class BinTree
{
protected:
    int _size; //规模
    BinNodePosi(T) _root; //根节点
    virtual int updateHeight(BinNodePosi(T) x); //更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x); //更新节点x及其祖先的高度


public:
    BinTree()
        :_size(0), _root(NULL)
    {}
    ~BinTree(){ if ( 0<_size) remove(_root);}
    bool empty() { return !_root; }
    int size(){return _size;}
    BinNodePosi(T) root() const { return _root;} //

    BinNodePosi(T) insertAsRoot(T const & e); //插入根节点

    BinNodePosi(T) insertAsLC(BinNodePosi(T) , T const & e);//e作为x的左孩子(原来没有)插入
    BinNodePosi(T) insertAsRC(BinNodePosi(T) , T const & e);//e作为x的右孩子(原来没有)插入
    BinTree<T> * attachAsLT(BinNodePosi(T)  , BinTree<T> * );//T作为x的左子树插入
    BinTree<T> * attachAsRT(BinNodePosi(T), BinTree<T>*);//T作为x的右子树插入
    int remove( BinNodePosi(T) x);//删除以位置x处节点为根的子树, 返回该子树原先的规模
    BinTree<T> * secede( BinNodePosi(T) x );//将子树x从当前树中摘除, 并将其转换为一颗独立子树



    template<typename VST>//层次遍历
    void travLevel(VST & visit){if(_root) _root->travLevel(visit); }

    template<typename VST>//先序遍历操作器
    void travPre(VST & visit);
    template <typename VST> void travPre_I1(BinNodePosi(T) , VST &);// 子树先序遍历 iterator_1
    template <typename VST> void travPre_I2(BinNodePosi(T) , VST &);// 子树先序遍历 iterator_1



    template<typename VST>
    void travIn(VST & visit);//中序遍历操作器
    template<typename VST>
    void travPost(VST & visit);//后序遍历操作器
    //比较器、判等器(各列其一, 其余自行补充)
    bool operator==(BinTree<T> const & t){ return    _root && t._root && (_root ==  t._root); }
    bool operator<(BinTree<T> const & t){ return    _root && t._root && lt(_root, t._root); }
    bool operator>(BinTree<T> const & t){ return    _root && t._root && rt(_root, t._root); }







};


/***
 * 实现: 因模板类定义与声明必须在一块, 故一起写在这
 *
 ******/
    /***
     * 高度更新
     * 1. 每个二叉树节点的高度等于其后代最大高度加一
     * 2. 一旦有节点加入或离开二叉树, 则更新其所有祖先的高度
     *
     * **/
template <typename  T>
int BinTree<T>::updateHeight(BinNodePosi(T) x){
    return x->height = 1+max(stature(x->lChild) , stature(x->rChild));
}
template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x){
    while(x) { updateHeight(x); x = x->parent; }
}

/***
 * 二叉树节点插入
 * 有三种情况插入
 * **/

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const & e){
    _size = 1;
    return _root   = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x , T const & e){
    _size++; x->insertAsLC(e); updateHeightAbove(x); return x->lChild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const & e){
    _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rChild;
}

//历程函数1
template<typename T , typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST & visit,vector<BinNodePosi(T) >& S){
while(x){
    visit(x->data);
    S.push_back(x->rChild);
    x = x->lChild;
}
}


//历程函数2, 随历程压栈

template<typename T , typename VST>
static void goAlongLeftBranch(BinNodePosi(T) x,vector<BinNodePosi(T) >& S){
while(x){
    S.push_back(x->rChild);
    x = x->lChild;
}
}

//先序遍历
template <class T, typename VST>
void travPre_I1(BinNodePosi(T) x, VST & visit)// 子树先序遍历 iterator_1
{
    vector<BinNodePosi(T)> v;
    if(x) v.push_back(x);
    while(!v.empty()){
        x = v.back(); v.pop_back();
        visit(x->data);
        if(x->rChild) v.push_back(x->rChild);
        if(x->lChild) v.push_back(x->lChild);
    }
}

template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST & visit)// 子树先序遍历 iterator_1
{
    vector<BinNodePosi(T)> v;
    while(true){
        visitAlongLeftBranch(x, visit, v);
        if(v.empty()) break;
        x = v.end();
        v.pop_back();
    }
}




#endif // BINTREE_H
