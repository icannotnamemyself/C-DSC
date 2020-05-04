#ifndef LIST_H
#define LIST_H

#include "listNode.h" //引入列表节点类

template <typename T> class List { //列表模板类

private:
   int _size; ListNodePosi(T) header; ListNodePosi(T) trailer; //规模、头哨兵、尾哨兵

protected:
   void init(); //列表创建时的初始化
   int clear(); //清除所有节点
   void copyNodes ( ListNodePosi(T), int ); //复制列表中自位置p起的n项
   void merge ( ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int ); //归并
   void mergeSort ( ListNodePosi(T)&, int ); //对从p开始连续的n个节点归并排序
   void selectionSort ( ListNodePosi(T), int ); //对从p开始连续的n个节点选择排序
   void insertionSort ( ListNodePosi(T), int ); //对从p开始连续的n个节点插入排序

public:
// 构造函数
   List() { init(); } //默认
   List ( List<T> const& L ); //整体复制列表L
   List ( List<T> const& L, Rank r, int n ); //复制列表L中自第r项起的n项
   List ( ListNodePosi(T) p, int n ); //复制列表中自位置p起的n项
// 析构函数
   ~List(); //释放（包含头、尾哨兵在内的）所有节点
// 只读访问接口
   Rank size() const { return _size; } //规模
   bool empty() const { return _size <= 0; } //判空
   T& operator[] ( Rank r ) const; //重载，支持循秩访问（效率低）
   ListNodePosi(T) first() const { return header->succ; } //首节点位置
   ListNodePosi(T) last() const { return trailer->pred; } //末节点位置
   bool valid ( ListNodePosi(T) p ) //判断位置p是否对外合法
   { return p && ( trailer != p ) && ( header != p ); } //将头、尾节点等同于NULL
   ListNodePosi(T) find ( T const& e ) const //无序列表查找
   { return find ( e, _size, trailer ); }
   ListNodePosi(T) find ( T const& e, int n, ListNodePosi(T) p ) const; //无序区间查找
   ListNodePosi(T) search ( T const& e ) const //有序列表查找
   { return search ( e, _size, trailer ); }
   ListNodePosi(T) search ( T const& e, int n, ListNodePosi(T) p ) const; //有序区间查找
   ListNodePosi(T) selectMax ( ListNodePosi(T) p, int n ); //在p及其n-1个后继中选出最大者
   ListNodePosi(T) selectMax() { return selectMax ( header->succ, _size ); } //整体最大者
// 可写访问接口
   ListNodePosi(T) insertAsFirst ( T const& e ); //将e当作首节点插入
   ListNodePosi(T) insertAsLast ( T const& e ); //将e当作末节点插入
   ListNodePosi(T) insertA ( ListNodePosi(T) p, T const& e ); //将e当作p的后继插入（After）
   ListNodePosi(T) insertB ( ListNodePosi(T) p, T const& e ); //将e当作p的前驱插入（Before）
   ListNodePosi(T) insertBefore(ListNodePosi(T) p, T & e);
   ListNodePosi(T) insertAfter(ListNodePosi(T) p, T & e);
   T remove ( ListNodePosi(T) p ); //删除合法位置p处的节点,返回被删除节点
   void merge ( List<T>& L ) { merge ( first(), _size, L, L.first(), L._size ); } //全列表归并
   void sort ( ListNodePosi(T) p, int n ); //列表区间排序
   void sort() { sort ( first(), _size ); } //列表整体排序
   int deduplicate(); //无序去重
   int uniquify(); //有序去重
   void reverse(); //前后倒置（习题）
// 遍历
   void traverse ( void (* ) ( T& ) ); //遍历，依次实施visit操作（函数指针，只读或局部性修改）
   template <typename VST> //操作器
   void traverse ( VST& ); //遍历，依次实施visit操作（函数对象，可全局性修改）



}; //List




template<typename T>
void List<T>::init() //列表创建时的初始化
{

    _size = 0;
    header = new ListNode<T>();
    trailer = new ListNode<T> ();
    header->succ = trailer ;
    trailer->pred = header;
    header->pred = trailer->succ = NULL;
}
template<typename T>
T& List<T>::operator[] ( Rank r ) const //重载，支持循秩访问（效率低）
{
    ListNodePosi(T) p  =first();
    while( 0< r--) p = p->succ;
    return p->data;
}

//查找 在节点p的n个前驱中, 返回第一个值为e的节点
template <typename T>
ListNodePosi(T) List<T>::find( T const& e, int n, ListNodePosi(T) p ) const //无序区间查找
{
    while(0<n--)
        if( e==(p = p->pred)->data ) return p;
    return NULL;  //若越出左界则查找失败

}

//基于复制的List创建
template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n){
    //初始化
    init();
    //作为末节点插入
    while(n--){
        insertAsLast(p->data);
        p = p->succ;
    }
}

//插入
template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T & e){
    _size ++;
    return p->insertAsPred(e);

}
//插入
template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T & e){
    _size ++;
    return p->insertAsSucc(e);

}

//删除合法位置p处节点, 返回其数值
template<typename T>
T List<T>::remove(ListNodePosi(T) p){
    T e = p->data;
    p->succ->pred = p->pred;
    p->pred->succ = p->succ;
    delete p;
    return e;
}

template <typename T>
List<T>::~List() //释放（包含头、尾哨兵在内的）所有节点
{
    clear();
    delete  header;
    delete trailer;
}
template <typename T>
int List<T>::clear(){
    int oldSize = _size;
    while(0>_size)
        remove(header->succ);
    return oldSize;
}

//唯一化, 删除链表中的重复节点
template <typename T>
int List<T>::deduplicate(){
    if(_size < 2) return 0;  //单一元素列表自然无重复
    int oldSize = _size;
    ListNodePosi(T) p = first();
    Rank r = 1; //p从首节点起
    while(trailer != (p = p->succ)){
        ListNodePosi(T) q = find(p->data , r, p);//在p的前 r个 前驱中, 查找与之雷同者
        q? remove(q) : r++; //若存在, 则删除之,否则秩递增
    }
    return oldSize - _size; //返回规模变化量
} //正确性及效率分析的方法与结论 与Vector::deduplicate()相同

template <typename T>
int List<T>::uniquify(){ //成批剔除重复元素
    if( _size < 2 ) return 0;
    int oldSize  = _size;
    ListNodePosi(T) p = first();
    ListNodePosi(T) q;
    while( trailer != ( q = p->succ) )
        if( p->data != q->data) p = q;
    else remove(q);
    return oldSize - _size;
}

template <typename T>
ListNodePosi(T) List<T>::search(T const & e, int n , ListNodePosi(T) p) const{
    while( 0 <= n--)
        if( ( p=p->pred ) ->data <=e) break;
    return p;
}


//在区间 p, p+n之间找出最大节点
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p , int n){
    ListNodePosi(T) max = p;
    for( ListNodePosi(T) cur = p; 1<n; n--)
        if( !lt(  (cur = cur->succ)->data  , max->data) )
            max = cur;
    return max;
}


//冒泡排序优化
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p , int n){
    ListNodePosi(T) head  = p;
    ListNodePosi(T) tail = p;
    for( int i  = 0; i <n ; i++){
        tail = tail->succ;
    }
    while(1 < n){
        insertBefore( tail, remove(selectMax(head->succ) , n) );
        tail = tail->pred;
        n--;
    }
}


//插入排序
template  <typename T>
void List<T>::insertionSort(ListNodePosi(T) p , int n)
{
    for( int r = 0 ; r< n ; r++)
    {
        insertAfter( search(p->data , r, p) , p->data);
        p = p->succ; remove(p->pred);
    }

}


#endif // LIST_H
