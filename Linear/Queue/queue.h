#ifndef QUEUE_H
#define QUEUE_H
#include "../List/list.h"


template  <typename T>
class Queue : public List<T>
{
public:
    void enqueue(T const & e){ insertAsLast(e); } //入队
    T dequeue() { return ( this->first() );} //出队
    T & front() { return this->first()->data; } //队首
}; //以列表首/末端为队列头/尾
#endif // QUEUE_H
