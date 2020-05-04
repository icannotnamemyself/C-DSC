
#include "binnode.h"

//操作接口
int size(); //统计当前节点后代总数, 也就是以其为根的子树的规模

template<typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& lc) //作为当前节点的左节点插入新节点
{
    return this->rChild = new BinNode(lc, this);
}
template<typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const & rc) //作为当前节点的右孩子插入新节点
{
    return this->rChild = new BinNode(rc, this);
}
template<typename T>
BinNodePosi(T) succ(); //取当前节点的直接后继


template <typename VST> void travLevel(VST &); //子树层次遍历
template <typename VST> void travPre(VST &);// 子树先序遍历
template <typename VST> void travIn(VST &); //子树中序遍历
template <typename VST> void travPost(VST &); //子树后序遍历
//比较器, 判等器(各列其一, 其余自行补充
