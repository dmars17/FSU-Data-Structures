#ifndef STACK_H
#define STACK_H
// Created by David A Gaitros on 10/15/19.
// ********************************************************************
// * Name: Stack Class                                                *
// * Description: A template Stack class designed to be used with     *
// * any simple C++ type to include floating point, double            *
// * floating point, character, and Boolean.                          *
// * The stack pointer, as is the convention, points to the last      *
// * or highest element in the array. So if you allocate 100          *
// * elements of type "T" then the first empty element will be 99.    *
// * Author: Dr. David A. Gaitros                                     *
// * Date: January 19, 2019                                           *
// ********************************************************************
#include <iostream>
using namespace std;

const int DEFAULTSIZE=100;
template <typename T> class Stack;
template <typename T> ostream & operator <<(ostream & os,  Stack<T> &obj);
template <typename T>
class Stack {
public:
    Stack();                    // Default Constructor, stack is size 100.
    Stack(const int size);      // Constructor, creates stack of size "size"
    Stack(const Stack & Obj);   // Copy constructor
    ~Stack();                   // Destructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    int Number();               // Return the number of elements stored
    T Top();                    // Returns the top element, does not pop it
    bool Push (const T item);   // Put an item on the stack
    bool Pop();                 // Pop an item off and display to std out
    Stack<T> &operator = (Stack<T> & s); // = operator overload.
    friend ostream &operator << <T>(ostream & os, Stack<T> &s);

protected:
    T * _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node
    int _number;                // The number of elements in the stack.
};


// **********************************************************************
// ** Name: Stack()                                                     *
// ** Description: Default Constructor                                  *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
Stack<T>::Stack() {
    _size = DEFAULTSIZE;
    _stack = new T[_size];
    _top = -1;
    _number = 0;
}

// **********************************************************************
// ** Name: Stack<T>::Stack(const int size)                             *
// ** Description: Constructor with a given size                        *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
Stack<T>::Stack(const int size) {
    _size = size;
    _stack = new T[_size];
    _top = -1;
    _number = 0;
}

// **********************************************************************
// ** Name: Stack<T>::Stack(const Stack &Obj)                           *
// ** Description: Copy Constructor                                     *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
Stack<T>::Stack(const Stack &Obj) {
    _size = Obj._size;
    _top = -1;
    _number = 0;
    _stack = new T[_size];
    for (int i = 0; i < _size; i++){
        _top++;
        _stack[_top]=Obj._stack[i];
        _number++;
    }
}

// **********************************************************************
// ** Name: Stack<T>::~Stack()                                          *
// ** Description: Destructor                                           *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
Stack<T>::~Stack() {
    delete[] _stack;
}

// **********************************************************************
// ** Name: bool Stack<T>::Full()                                       *
// ** Description: Returns true if the stack is full                    *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
bool Stack<T>::Full() {
    if (_number == _size)
        return true;
    else
        return false;
}

// **********************************************************************
// ** Name: bool Stack<T>::Empty()                                      *
// ** Description: Returns true if the stack is empty                   *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
bool Stack<T>::Empty() {
    if (_number == 0)
        return true;
    else
        return false;
}

// **********************************************************************
// ** Name: int Stack<T>::Size()                                        *
// ** Description: Returns the size of the stack                        *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
int Stack<T>::Size() {
    return _size;
}

// **********************************************************************
// ** Name: int Stack<T>::Number()                                      *
// ** Description: Returns the number of elements in the stack          *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
int Stack<T>::Number() {
    return _number;
}

// **********************************************************************
// ** Name: T Stack<T>::Top()                                           *
// ** Description: Returns the top element on the stack                 *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
T Stack<T>::Top() {
    return _stack[_top];
}

// **********************************************************************
// ** Name: bool Stack<T>::Push(const T item)                           *
// ** Description: Checks if the stack is full. If full returns false   *
// **   and shows an error. If not full, increases top, adds item to    *
// **   the top of the stack, increases the number of elements and      *
// **   returns true.                                                   *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
bool Stack<T>::Push(const T item) {
    if (Full()){
        cout << "Error. Stack Overflow." << endl;
        return false;
    }
    else {
        _stack[++_top] = item;
        _number++;
        return true;
    }
}

// **********************************************************************
// ** Name: bool Stack<T>::Pop()                                        *
// ** Description: Checks if the stack is empty. If empty, returns      *
// **   false and outputs an error. If not empty, decreases top,        *
// **   decreases number of elements, and returns true.                 *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
bool Stack<T>::Pop() {
    if (Empty()) {
        cout << "Error. Stack is Empty" << endl;
        return false;
    } else {

//        cout << Top();
        _top--;
        _number--;
        return true;
    }
}

// **********************************************************************
// ** Name: Stack<T> &Stack<T>::operator=(Stack<T> &s)                  *
// ** Description: Assignment operator. Sets size to s.size, top to     *
// **   the default top, and number to 0; Creates a new stack, then     *
// **   proceeds through the old stack moving each element to the new   *
// **   stack, using the s.Number() for the number of elements to move  *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// **********************************************************************
template<typename T>
Stack<T> &Stack<T>::operator=(Stack<T> &s) {
    _size = s._size;
    _top = -1;
    _number = 0;
    _stack = new T[_size];
    for (int i = 0; i < s.Number(); i++){
        _top++;
        _stack[_top]=s._stack[i];
        _number++;
    }
}

// **********************************************************************
// ** Name: ostream &operator << (ostream & os, Stack<T> &s)            *
// ** Description: << ostream overload. First checks if the stack is    *
// **   empty. If empty output the stack is empty. If not empty, check  *
// **   if stack is full or not and output the result. Then outputs     *
// **   all information of the stack. Then pops the top item, then      *
// **   proceeds to output the rest of the stack seperated by a " ".    *
// ** Author: Dustin Marsden                                            *
// ** Date: January 6, 2022                                             *
// ***********************************************************************
template <typename T>
ostream &operator << (ostream & os, Stack<T> &s){
    if (s.Empty()){
        os << "Error. Stack Empty." << endl;
    }
    else {
        if (s.Full())
            os << "The stack is full." << endl;
        else
            os << "The stack is not full." << endl;
        os << "The top element of the stack is -> " << s.Top() << endl;
        os << "The size of the stack is: " << s.Size() << endl;
        os << "The number of elements the stack is holding is: " << s.Number() << endl;
        s.Pop();
        os << "The contents of the sack are: ";
        int t = s._top;
        while (t > -1) {
            os << s._stack[t] << " ";
            t--;
        }
    }
        os << endl;
        return os;
}
//#include "stack.hpp"
#endif


