#ifndef QUEUE_H
#define QUEUE_H

#include "Deque.h"

//#define DEFAULT_CAPACITY 2
template <typename T>
class Queue
{
private:
    Deque<T> queue_;
   
public:

    Queue(void) {};
    ~Queue() = default;

    // Queue container pushes to the back of the queue
    void push(const T& item)
    {
        queue_.push_back(item);
        return;
    }

    // Queue container pops front only
    void pop()
    {
        queue_.pop_front();
        return;
    }

    // +top():T&
    T& top()
    {
        return queue_.front();
    }

    // +size():size_t
    size_t size()
    {
        return queue_.size();
    }

    // +at(size_t):T&
    T& at(size_t position)
    {
        return queue_.at(position);
    }

    // +toString() const:string
    string toString() const
    {
        return queue_.toString();
    }

    // Friend operator
    friend std::ostream& operator<< (ostream& os, const Queue& q)
    {
        os << q.toString();
        return os;
    } // end operator<<

};

#endif // QUEUE_H
