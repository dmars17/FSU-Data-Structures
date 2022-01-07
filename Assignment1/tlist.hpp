#ifndef TLIST_HPP
#define TLIST_HPP

#include "tlist.h"

template <typename T>
TList<T>::TList() {
    size = 0;
    first = last = nullptr;
}

template<typename T>
TList<T>::TList(T val, int num) {
    size = 0;
    first = last = nullptr;
    for (int i = 0; i < num; i++){
        InsertBack(val);
    }
}


template<typename T>
TList<T>::~TList() {
    Clear();
}

template<typename T>
TList<T>::TList(const TList &L) {
    auto itr = L.GetIterator();
    size = 0;
    first = last = nullptr;
    for (int i = 0; i < L.GetSize(); i++){
        InsertBack(itr.GetData());
        itr.Next();
    }

}

template<typename T>
TList<T> &TList<T>::operator=(const TList &L) {
    Clear();
    auto itr = L.GetIterator();
    for (int i = 0; i < L.GetSize(); i++){
        InsertBack(itr.GetData());
        itr.Next();
    }
    return *this;
}

template<typename T>
TList<T>::TList(TList &&L) {
    first = L.first;
    last = L.last;
    size = L.size;
}

template<typename T>
TList<T> &TList<T>::operator=(TList &&L) {
    int temp = 0;
    Node<T> *tPtr = first;
    first = L.first; // move value of L.first
    L.first = tPtr;    // switch pointers for "first"
    tPtr = last;  // switch the ptrs for "last"
    last = L.last;
    L.last = tPtr;
    temp = size;  // copy the list sizes to temp variable
    size = L.size;
    L.size = temp;
    return *this;
}


template<typename T>
bool TList<T>::IsEmpty() const {
    if (size == 0)
        return true;
    else
        return false;
}

template<typename T>
void TList<T>::Clear() {
    while (!IsEmpty()){
        RemoveBack();
    }
}


template<typename T>
int TList<T>::GetSize() const {
    return size;
}

template<typename T>
void TList<T>::InsertFront(const T &d) {
    auto *temp = new Node<T>(d);

    if (size == 0){
        first = temp;
        last = temp;
        size++;
    }
    else{
        temp->next = first;
        first->prev = temp;
        first = temp;
        size++;
    }

}

template<typename T>
void TList<T>::InsertBack(const T &d) {
    auto *temp = new Node<T>(d);

    if (size == 0){
        first = temp;
        last = temp;
        size++;
    }
    else {
        temp->prev = last;
        last->next = temp;
        last = temp;
        size++;
    }

}

template<typename T>
void TList<T>::RemoveFront() {
    if (first == nullptr)
        return;
    if (first->next == nullptr){
        delete first;
        first = nullptr;
        last = nullptr;
        size--;
    }
    else{
        Node<T> * _nextfirst = first->next;
        delete first;
        first = _nextfirst;
        size--;
    }
}

template<typename T>
void TList<T>::RemoveBack() {
    if (first == nullptr)
        return;
    if (first->next == nullptr){
        delete first;
        first = nullptr;
        last = nullptr;
        size--;
    }
    else {
        Node<T> *_newend = last->prev;
        _newend->next = nullptr;
        delete last;
        last = _newend;
        size--;

    }
}




template<typename T>
void TList<T>::Print(std::ostream &os, char delim) const {
    Node<T> * _temp = first;
    for(int i=0;i<size; i++) {
        os << _temp->data << delim;
        _temp = _temp->next;
    }
}

template<typename T>
T &TList<T>::GetFirst() const {
    return first->data;
}

template<typename T>
T &TList<T>::GetLast() const {
    return last->data;
}

template<typename T>
TListIterator<T> TList<T>::GetIterator() const {
    TListIterator<T> itr;
    itr.ptr = first;
    return itr;
}

template<typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const {
    TListIterator<T> itr;
    itr.ptr = last;
    return itr;
}

template<typename T>
void TList<T>::Insert(TListIterator<T> pos, const T &d) {
    auto * node = new Node<T>(d);
    if (pos.ptr == first)
        InsertFront(node->data);
    else if (pos.ptr == last)
        InsertBack(node->data);
    else {
        node->prev = pos.ptr->prev;
        node->next = pos.ptr;
        pos.ptr->prev->next = node;
        pos.ptr->prev = node;
        size++;
    }

}

template<typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos) {
    Node<T> *node = pos.ptr;
    TListIterator<T> temp = pos.Next();
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    size--;
    return temp;

}




//*********************************************************************

template <typename T>
TListIterator<T>::TListIterator() {
    ptr = nullptr;
}

template<typename T>
bool TListIterator<T>::HasNext() const {
    if (ptr->next == nullptr)
        return false;
    else
        return true;
}

template<typename T>
bool TListIterator<T>::HasPrevious() const {
    if (ptr->prev == nullptr)
        return false;
    else
        return true;
}

template<typename T>
TListIterator<T> TListIterator<T>::Next() {
    if (HasNext()){
        ptr = ptr->next;
    }
    return *this;
}

template<typename T>
TListIterator<T> TListIterator<T>::Previous() {
    if (HasPrevious()){
        ptr = ptr->prev;
    }
    return *this;
}

template<typename T>
T &TListIterator<T>::GetData() const {
    return ptr->data;
}


#endif

