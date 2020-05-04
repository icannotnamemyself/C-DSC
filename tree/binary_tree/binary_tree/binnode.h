#ifndef BINNODE_H
#define BINNODE_H

#include <vector>
#include <iostream>
using namespace std;


#define BinNodePosi(T) BinNode<T>* //节点位置
#define stature(p) ((p)? (p) -> height : -1) //节点高度

/***
 * BinNode 状态与性质判断
 * 默认x为 对象, 不是对象指针
 * **/

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x)->parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x)->parent->rChild))
#define HasParent(x) (!IsRoot(x))

#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))


/**
  * BinNode 具有特定关系的节点与指针
  * */
#define sibling(p) ( IsLChild(*(p))? (x) ->parent->rChild:(x)->parent->lChild)

#define uncle(x) ( IsLChild(*((x)) ->parent)?(x)->parent->parent->rChild: (x) ->parent->parent->lChild )

#define FromParentTo(x) ( IsRoot(x) ? _root: (IsLChild(x) ? (x).parent->lChild:(x).parent->rChild) )


typedef enum{ RB_RED, RB_BLACK} RBColor;

//struct 与class 基本画等号, 区别是 struct 默认是public class默认是private
template <typename T>
struct BinNode
{
public :
    T data; //数值
    BinNodePosi(T) parent;
    BinNodePosi(T) lChild;
    BinNodePosi(T) rChild;

    int height; //高度通用
    int npl; //Null Path Length (左式堆, 也可直接用height 代替)
    RBColor color; //颜色(红黑树)
  //构造函数
    BinNode() : parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED){ }
    BinNode(T e, BinNodePosi(T) p=NULL, BinNodePosi(T) lc=NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED)
        :data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {}

    //操作接口
    int size(); //统计当前节点后代总数, 也就是以其为根的子树的规模

    BinNodePosi(T) insertAsLC(T const& d){ return this->lChild = new BinNode(d,this);} //作为当前节点的左节点插入新节点
    BinNodePosi(T) insertAsRC(T const & d){return this->rChild = new BinNode(d,this);} //作为当前节点的右孩子插入新节点 BinNodePosi(T) succ(); //取当前节点的直接后继


    template <typename VST> void travLevel(VST &); //子树层次遍历
    template <typename VST> void travPre(VST &);// 子树先序遍历
    template <typename VST> void travIn(VST &); //子树中序遍历
    template <typename VST> void travPost(VST &); //子树后序遍历
    //比较器, 判等器(各列其一, 其余自行补充
    bool operator<(BinNode const& bn){ return data < bn.data;} //小于

    bool operator==(BinNode const& bn){ return data < bn.data;} //等于

};




/**
 * 二叉树中序遍历五种方法
 */
template<class T> template<typename VST> //元素类型, 操作器
void BinNode<T>::travIn(VST & visit) //子树中序遍历
{
    switch (rand() % 5) { //次数暂随机选择以做测试, 共五种选择
    case 1: travIn_1(this, visit);  break;
    case 2: travIn_2(this, visit);  break;
    case 3: travIn_3(this, visit);  break;
    case 4: travIn_4(this, visit);  break;
    case 5: travIn_5(this, visit);  break;
    }
}


#endif // BINNODE_H
