
#ifndef STACK_H
#define STACK_H
#include "tlist.h"
namespace cop4530{
template <typename T>
class Stack{
private:
    TList<T> list;

public:
    Stack();
    ~Stack();
    Stack(const Stack & rhs);
    Stack(Stack && rhs);
    Stack &operator=(const Stack & rhs);    // copy assignment operator=.
    Stack &operator=(Stack && rhs);         // move assignment operator=
    bool empty() const;                 // checks if empty
    void clear();                       // delete all elements from the stack.
    void push(const T &x);              // adds x to the Stack. copy version.
    void push(T &&x);                   // adds x to the Stack. move version.
    void pop();                         // removes and discards the most recently added element of the Stack.
    T &top();                           // returns a reference to the most recently added element of the Stack (as a modifiable L-value).
    const T &top() const;               // accessor that returns the most recently added element of the Stack (as a const reference)
    int size();

    void print(std::ostream &os, char ofc = ' ') const;

    void init();

    //StackIterator<T> *begin();

    friend std::ostream &operator<<(std::ostream &os, const Stack<T> &a) {      //invokes the print() method
        a.print(os);
        return os;
    };
};

#include "stack.hpp"
};
#endif //STACK_H

