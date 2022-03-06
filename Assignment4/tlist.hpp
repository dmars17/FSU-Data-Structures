#ifndef TLIST_HPP
#define TLIST_HPP

#include "tlist.h"

// **********************************************************
// * Name: TList<T>::TList()                                *
// * Description: Default constructor                       *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template <typename T>
TList<T>::TList() {
    size = 0;
    first = last = nullptr;
}

// **********************************************************
// * Name: TList<T>::TList(T val, int num)                  *
// * Description: Constructor creating num number of        *
// *    elements each storing val data .                    *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TList<T>::TList(T val, int num) {
    size = 0;
    first = last = nullptr;
    for (int i = 0; i < num; i++){
        InsertBack(val);
    }
}

// **********************************************************
// * Name: TList<T>::~TList()                               *
// * Description: Destructor                                *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TList<T>::~TList() {
    Clear();
}

// **********************************************************
// * Name: TList<T>::TList(const TList &L)                  *
// * Description: Copy Constructor                          *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
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

// **********************************************************
// * Name: TList<T> &TList<T>::operator=(const TList &L)    *
// * Description: Copy assignment operator                  *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
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

// **********************************************************
// * Name: TList<T>::TList(TList &&L)                       *
// * Description: Move constructor                          *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TList<T>::TList(TList &&L) {
    first = L.first;
    last = L.last;
    size = L.size;
}

// **********************************************************
// * Name: TList<T> &TList<T>::operator=(TList &&L)         *
// * Description: Move assignment operator                  *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TList<T> &TList<T>::operator=(TList &&L) {
    int temp = 0;
    Node<T> *tempnode = first;
    first = L.first;
    L.first = tempnode;
    tempnode = last;
    last = L.last;
    L.last = tempnode;
    temp = size;
    size = L.size;
    L.size = temp;
    return *this;
}

// **********************************************************
// * Name: TList<T>::IsEmpty() const                        *
// * Description: Checks if size is 0 and returns true,     *
// *    else returns false.                                 *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
bool TList<T>::IsEmpty() const {
    if (size == 0)
        return true;
    else
        return false;
}

// **********************************************************
// * Name: TList<T>::Clear()                                *
// * Description: While the list is not empty keep          *
// *    removing the last element of the list.              *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
void TList<T>::Clear() {
    while (!IsEmpty()){
        RemoveBack();
    }
}

// **********************************************************
// * Name: TList<T>::GetSize()                              *
// * Description: Returns the size of the list              *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
int TList<T>::GetSize() const {
    return size;
}

// **********************************************************
// * Name: TList<T>::InsertFront(const T &d)                *
// * Description: Creates a new node with data d. Checks    *
// *    if the size is 0, if it is sets first and last to   *
// *    the new node and increases size. If size is not 0,  *
// *    sets the new node next to first, sets first prev to *
// *    new node, sets first to new node, and increases the *
//  *   size.
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
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

// **********************************************************
// * Name: TList<T>::InsertBack(const T &d)                 *
// * Description: Creates a new node with data d. Checks if *
// *    the size is 0, if it is sets first and last to new  *
// *    node and increases size. If not rearranges          *
// *    pointers, sets last to new node and increases size. *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
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

// **********************************************************
// * Name: TList<T>::RemoveFront()                          *
// * Description: Checks if list is empty and returns if    *
// *    true. Checks if list has 1 element, if true deletes *
// *    the node, sets first and last to null and decreases *
// *    size. If more than 1 element, creates a new node    *
// *    with data of first next. Deletes first, sets first  *
// *    to the new node and decreases size.                 *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
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

// **********************************************************
// * Name: TList<T>::RemoveBack()                           *
// * Description: Checks if list is empty and returns if    *
// *    true. Checks if list has 1 element, if true deletes *
// *    the node, sets first and last to null and decreases *
// *    size. If more than 1 element, creates a new node    *
// *    with data of last prev. Deletes last, sets last to  *
// *     the new node and decreases size.                   *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
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

// **************************************************************
// * Name: TList<T>::Print(std::ostream &os, char delim) const  *
// * Description: Creates a node at the front of the list.      *
// *    Traverse the list and output each node's data.          *
// * Author: Dustin Marsden                                     *
// * Date: 1/10/2022                                            *
// **************************************************************
template<typename T>
void TList<T>::Print(std::ostream &os, char delim) const {
    Node<T> * _temp = first;
    for(int i=0;i<size; i++) {
        os << _temp->data << delim;
        _temp = _temp->next;
    }
}

// **********************************************************
// * Name: List<T>::GetFirst() const                        *
// * Description: Returns the data of the first element     *
// *    of the list.                                        *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
T &TList<T>::GetFirst() const {
    return first->data;
}

// **********************************************************
// * Name: TList<T>::GetLast() const                        *
// * Description: Returns the data of the last element      *
// *    of the list.                                        *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
T &TList<T>::GetLast() const {
    return last->data;
}

// **********************************************************
// * Name: TList<T>::GetIterator() const                    *
// * Description: Creates an iterator using the first       *
// *    element of the list                                 *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TListIterator<T> TList<T>::GetIterator() const {
    TListIterator<T> itr;
    itr.ptr = first;
    return itr;
}

// **********************************************************
// * Name: TList<T>::GetIteratorEnd() const                 *
// * Description: Creates an iterator using the last        *
// *    element of the list.                                *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const {
    TListIterator<T> itr;
    itr.ptr = last;
    return itr;
}

// **************************************************************
// * Name: TList<T>::Insert(TListIterator<T> pos, const T &d)   *
// * Description: Creates a new node with data d. then places   *
// *    the new node into the list before the position of the   *
// *    iterator pos.                                           *
// * Author: Dustin Marsden                                     *
// * Date: 1/10/2022                                            *
// **************************************************************
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

// **********************************************************
// * Name: TList<T>::Remove(TListIterator<T> pos)           *
// * Description: This will delete an item from the list    *
// *    located in at the iterator position pos. This will  *
// *    then return the iterator to the node after the one  *
// *    that was deleted.
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos) {
    Node<T> *node = pos.ptr;
    TListIterator<T> temp = pos.Next();
    node->prev->next = temp.ptr;
    node->next->prev = node->prev;
    delete node;
    size--;
    return temp;
//    Node *p = itr.current; // sourced from lecture slides
//    iterator retval(p->next);
//    p->prev->next = p->next;
//    p->next->prev = p->prev;
//    delete p;
//    theSize--;
//    return retval;
}

//*********************************************************************
//*******************      TLISTITERATOR<T>        ********************
//*********************************************************************

// **********************************************************
// * Name: TListIterator<T>::TListIterator()                *
// * Description: Default iterator constructor              *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template <typename T>
TListIterator<T>::TListIterator() {
    ptr = nullptr;
}

// **********************************************************
// * Name: TListIterator<T>::HasNext() const                *
// * Description: Checks if the iterator next points to     *
// *    nullptr. If yes it will return false. Otherwise,    *
// *    it will return true.                                *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
bool TListIterator<T>::HasNext() const {
    if (ptr->next == nullptr)
        return false;
    else
        return true;
}

// **********************************************************
// * Name: TListIterator<T>::HasPrevious() const            *
// * Description: Checks if the iterator previous points to *
// *    nullptr. If yes it will return false. Otherwise,    *
// *    it will return true.                                *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
bool TListIterator<T>::HasPrevious() const {
    if (ptr->prev == nullptr)
        return false;
    else
        return true;
}

// **********************************************************
// * Name: TListIterator<T>::Next()                         *
// * Description: If the iterator has a next node it will   *
// *    traverse to it and return an iterator.              *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TListIterator<T> TListIterator<T>::Next() {
    if (HasNext()){
        ptr = ptr->next;
    }
    return *this;
}

// **********************************************************
// * Name: TListIterator<T>::Previous()                     *
// * Description: If the iterator has a previous node it    *
// *    will traverse to it and return an iterator.         *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
TListIterator<T> TListIterator<T>::Previous() {
    if (HasPrevious()){
        ptr = ptr->prev;
    }
    return *this;
}

// **********************************************************
// * Name: TListIterator<T>::GetData() const                *
// * Description: Returns the data of the node the          *
// *    iterator is pointing to.                            *
// * Author: Dustin Marsden                                 *
// * Date: 1/10/2022                                        *
// **********************************************************
template<typename T>
T &TListIterator<T>::GetData() const {
    return ptr->data;
}

#endif

