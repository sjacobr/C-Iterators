#ifndef VECTOR_H
#define VECTOR_H


#include "Deque.h"

template <typename T>
class Vector
{
private:
    Deque<T> vector_;

public:

    Vector(void) {};
    ~Vector() = default;

    //push_back(const T&):void
    void push_back(const T& data)
    {
        vector_.push_back(data);
        return;
    }

    // +pop_back():void
    void pop_back()
    {
        vector_.pop_back();
        return;
    }

    // +back():T&
    T& back()
    {
        return vector_.back();
    }

    // +size():size_t
    size_t size()
    {
        return vector_.size();
    }

    // +at(size_t):T&
    T& at(size_t position)
    {
        return vector_.at(position);
    }

    // +toString() const:string
    string toString() const
    {
        return vector_.toString();
    }

    // Friend operator
    friend std::ostream& operator<< (ostream& os, const Vector& v)
    {
        os << v.toString();
        return os;
    } // end operator<<

};

#endif // VECTOR_H
