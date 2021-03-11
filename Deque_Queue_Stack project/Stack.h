#ifndef STACK_H
#define STACK_H

#include "Deque.h"

template <typename T>
class Stack
{
private:
    Deque<T> stack_;
public:

    Stack(void) {};
    ~Stack() = default;

    // +push(const T&):void
    void push(const T& item)
    {
        stack_.push_back(item);
        return;
    }

    // Stack pops the last item in
    void pop()
    {
        stack_.pop_back();
        return;
    }

    // Top of stack is the back (LIFO)
    T& top()
    {
        return stack_.back();
    }

    // +size():size_t
    size_t size()
    {
        return stack_.size();
    }

    // +at(size_t):T&
    T& at(size_t position)
    {
        return stack_.at(position);
    }

    // +toString() const:string
    string toString() const
    {
        return stack_.toString();
    }

    // Friend operator
    friend std::ostream& operator<< (ostream& os, const Stack& s)
    {
        os << s.toString();
        return os;
    } // end operator<<

};

#endif // STACK_H
