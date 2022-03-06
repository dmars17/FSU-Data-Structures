#ifndef STACK_HPP
#define STACK_HPP
using namespace std;
#include "stack.h"

template<typename T>
Stack<T>::Stack() {
    init();
}

template<typename T>
Stack<T>::~Stack() {
    list.Clear();
}

template<typename T>
Stack<T>::Stack(const Stack & s) {
    list = s.list;
}

template<typename T>
Stack<T>::Stack(Stack &&s) {
    list = s.list;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &s) {
    list = s.list;
    return *this;
}

template<typename T>
Stack<T> &Stack<T>::operator=(Stack &&s) {
    list = s.list;
    return *this;
}

template<typename T>
bool Stack<T>::empty() const {
   return list.IsEmpty();
}

template<typename T>
void Stack<T>::clear() {
    while(!empty()){
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T &x) {
    list.InsertFront(x);
}

template<typename T>
void Stack<T>::push(T &&x) {
    list.InsertFront(x);
}

template<typename T>
void Stack<T>::pop() {
    list.RemoveFront();
}

template<typename T>
T &Stack<T>::top() {
    return list.GetFirst();
}

template<typename T>
const T &Stack<T>::top() const {
    return list.GetFirst();
}

template<typename T>
int Stack<T>::size() {
    return list.GetSize();
}

template<typename T>
void Stack<T>::print(ostream &os, char ofc) const {
    list.Print(os, ofc);
}

template<typename T>
void Stack<T>::init() {
    list.Clear();
}
#endif //ASSIGNMENT4_STACK_HPP

