

#include <iostream>
#include <initializer_list>
#include "List.h"
using namespace cop4530;


// **********************************************************
// * Name: List<T>::const_iterator::const_iterator()        *
// * Description: Constructor for const iterator            *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::const_iterator::const_iterator() {
    current = nullptr;
}

// **********************************************************
// * Name: List<T>::const_iterator::operator*()             *
// * Description: Returns element from iterator             *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
const T &List<T>::const_iterator::operator*() const {
    return this->retrieve();
}

// **********************************************************************************
// * Name: List<T>::const_iterator &cop4530::List<T>::const_iterator::operator++()  *
// * Description: Increment operator                                                *
// * Author: Dustin Marsden                                                         *
// * Date: 2/2/2022                                                                 *
// **********************************************************************************
template<typename T>
typename List<T>::const_iterator &cop4530::List<T>::const_iterator::operator++() {
    current = current->next;
    return *this;
}

// **********************************************************************************
// * Name: List<T>::const_iterator cop4530::List<T>::const_iterator::operator++(int)*
// * Description: Increment operator                                                *
// * Author: Dustin Marsden                                                         *
// * Date: 2/2/2022                                                                 *
// **********************************************************************************
template<typename T>
typename List<T>::const_iterator cop4530::List<T>::const_iterator::operator++(int) {
    auto temp = *this;
    ++(*this);
    return temp;
}

// **********************************************************************************
// * Name: List<T>::const_iterator &cop4530::List<T>::const_iterator::operator--()  *
// * Description: Decrement operator                                                *
// * Author: Dustin Marsden                                                         *
// * Date: 2/2/2022                                                                 *
// **********************************************************************************
template<typename T>
typename List<T>::const_iterator &cop4530::List<T>::const_iterator::operator--() {
    current = current->prev;
    return *this;
}

// **********************************************************************************
// * Name: List<T>::const_iterator cop4530::List<T>::const_iterator::operator--(int)*
// * Description: Decrement operator                                                *
// * Author: Dustin Marsden                                                         *
// * Date: 2/2/2022                                                                 *
// **********************************************************************************
template<typename T>
typename List<T>::const_iterator cop4530::List<T>::const_iterator::operator--(int) {
    auto temp = *this;
    --(*this);
    return temp;
}

// **********************************************************************************
// * Name: List<T>::const_iterator::operator==(const const_iterator &rhs) const     *
// * Description: Equal comparison operator                                         *
// * Author: Dustin Marsden                                                         *
// * Date: 2/2/2022                                                                 *
// **********************************************************************************
template<typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const {
    return (current == rhs.current);
}

// **********************************************************************************
// * Name: List<T>::const_iterator::operator!=(const const_iterator &rhs) const     *
// * Description: Not equal comparison operator                                     *
// * Author: Dustin Marsden                                                         *
// * Date: 2/2/2022                                                                 *
// **********************************************************************************
template<typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const {
    return (current != rhs.current);
}

// **********************************************************
// * Name: T &List<T>::const_iterator::retrieve() const     *
// * Description: Returns data of current from iterator     *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
T &List<T>::const_iterator::retrieve() const {
    return current->data;
}

// **********************************************************
// * Name: List<T>::const_iterator::const_iterator(Node *p) *
// * Description: Constructor. Sets current to p            *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::const_iterator::const_iterator(Node *p) {
    current = p;
}

// **********************************************************
// * Name: List<T>::iterator::iterator()                    *
// * Description:
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::iterator::iterator() {
}

// **********************************************************
// * Name: T &cop4530::List<T>::iterator::operator*()       *
// * Description: Returns element at iterator               *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
T &cop4530::List<T>::iterator::operator*() {
    return this->retrieve();
}

// ******************************************************************
// * Name: const T &cop4530::List<T>::iterator::operator*() const   *
// * Description: Const version of returning element from iterator  *
// * Author: Dustin Marsden                                         *
// * Date: 2/2/2022                                                 *
// ******************************************************************
template<typename T>
const T &cop4530::List<T>::iterator::operator*() const {
    return this->retrieve();
}

// **************************************************************
// * Name: List<T>::iterator &List<T>::iterator::operator++()   *
// * Description: Increment operator                            *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template<typename T>
typename List<T>::iterator &List<T>::iterator::operator++() {
    this->current = this->current->next;
    return(*this);
}

// **************************************************************
// * Name: List<T>::iterator List<T>::iterator::operator++(int) *
// * Description: Increment operator                            *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
}

// **************************************************************
// * Name: List<T>::iterator &List<T>::iterator::operator--()   *
// * Description: Decrement operator                            *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template<typename T>
typename List<T>::iterator &List<T>::iterator::operator--() {
    this->current = this->current->prev;
    return(*this);
}

// **************************************************************
// * Name: List<T>::iterator List<T>::iterator::operator--(int) *
// * Description: Decrement operator                            *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
}

// **********************************************************************************************
// * Name: List<T>::iterator::iterator(Node *p): List<T>::const_iterator::const_iterator{p}     *
// * Description: Iterator constructor. Calls const iterator constructor.                       *
// * Author: Dustin Marsden                                                                     *
// * Date: 2/2/2022                                                                             *
// **********************************************************************************************
template<typename T>
List<T>::iterator::iterator(Node *p): List<T>::const_iterator::const_iterator{p} {

}

// **********************************************************
// * Name: List<T>::List()                                  *
// * Description: Default constructor                       *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::List() {
    init();
}

// **********************************************************
// * Name: List<T>::List(const List &rhs)                   *
// * Description: Copy constructor                          *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::List(const List &rhs) {
    init();
    auto itr = rhs.begin();
    for(int i = 0; i < rhs.size(); i++){
        push_back(*itr);
        itr++;
    }
}

// **********************************************************
// * Name: List<T>::List(List &&rhs)                        *
// * Description: Move constructor                          *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::List(List &&rhs) {
    theSize = rhs.theSize;
    head = rhs.head;
    tail = rhs.tail;
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

// **********************************************************
// * Name: List<T>::List(int num, const T &val)             *
// * Description: Constructor to create list with num       *
// *    number of nodes with data val                       *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::List(int num, const T &val) {
    init();
    for (auto i = 0; i < num; ++i){
        push_back(val);
    }
}

// **********************************************************
// * Name: List<T>::List(List::const_iterator start,        *
// *        List::const_iterator end)                       *
// * Description: Constructs with elements start and end    *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::List(List::const_iterator start, List::const_iterator end) {
    init();
    auto itr = start;
    while(itr != end){
        push_back(*itr);
        itr++;
    }
}

// **********************************************************
// * Name: List<T>::List(std::initializer_list<T> iList)    *
// * Description: constructs with a copy of each of the     *
// *    elements in the initializer_list                    *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::List(std::initializer_list<T> iList) {
    init();
    for(auto i = iList.begin(); i != iList.end(); ++i){
        push_back(*i);
    }
}

// **********************************************************
// * Name: List<T>::~List()                                 *
// * Description: Destructor                                *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T>::~List() {
    if(empty())
        clear();
    delete head;
    delete tail;
}

// **********************************************************
// * Name: List<T> &List<T>::operator=(const List &rhs)     *
// * Description: Copy assignment operator                  *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
const List<T> &List<T>::operator=(const List &rhs) {
    clear();
    auto itr = rhs.begin();
    for(int i = 0; i < rhs.size(); i++){
        push_back(itr.retrieve());
        itr++;
    }
    return *this;
}

// **********************************************************
// * Name: List<T> &List<T>::operator=(List &&rhs)          *
// * Description: Move assignment operator                  *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
List<T> &List<T>::operator=(List &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
}

// **********************************************************************
// * Name: List<T> &List<T>::operator=(std::initializer_list<T> iList)  *
// * Description: sets list to the elements of the initializer_list     *
// * Author: Dustin Marsden                                             *
// * Date: 2/2/2022                                                     *
// **********************************************************************
template<typename T>
List<T> &List<T>::operator=(std::initializer_list<T> iList) {
    init();
    for(auto i = iList.begin(); i != iList.end(); ++i){
        push_back(*i);
        return *this;
    }
}

// **********************************************************
// * Name: List<T>::size() const                            *
// * Description: Returns size of list                      *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
int List<T>::size() const {
    return theSize;
}

// **********************************************************
// * Name: List<T>::empty() const                           *
// * Description: Checks if size is 0 to determine if list  *
// *    is empty                                            *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
bool List<T>::empty() const {
    if(theSize==0)
        return true;
    else
        return false;
}

// **********************************************************
// * Name: List<T>::clear()                                 *
// * Description: Checks if list is empty and pops back     *
// *    until list is empty                                 *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::clear() {
    while(!empty())
        pop_back();
}

// ***********************************************************
// * Name: List<T>::reverse()                                *
// * Description: Sets iterator to the last element. Creates *
// *    a new list. Then iterates backwards through the list *
// *    and pushes each element onto the list. Then          *
// *    reassigns pointer                                    *
// * Author: Dustin Marsden                                  *
// * Date: 2/2/2022                                          *
// ***********************************************************
template<typename T>
void List<T>::reverse() {
    auto itr = end();
    List<T> temp;
    itr--;
    for(int i = 0; i < theSize; i++){
        temp.push_back(*itr);
        itr--;
    }
    *this = temp;
}

// **********************************************************
// * Name: List<T>::front()                                 *
// * Description: Returns reference to first element        *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
T &List<T>::front() {
    return *begin();
}

// **********************************************************
// * Name: List<T>::front() const                           *
// * Description: Const version of returning reference to   *
// *    first element                                       *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
const T &List<T>::front() const {
    return *begin();
}

// **********************************************************
// * Name: List<T>::back()                                  *
// * Description: Returns reference to last element         *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
T &List<T>::back() {
    return *--end();
}

// **********************************************************
// * Name: List<T>::back() const                            *
// * Description: Const version of returning reference to   *
// *    last element                                        *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
const T &List<T>::back() const {
    return *--end();
}

// **********************************************************
// * Name: List<T>::push_front(const T &val)                *
// * Description: Calls insert using iterator begin and     *
// *    the given data val to insert item at front of list  *
// * Author: Dustin Marsden                                 *
// * Reference: Stackoverflow.com                           *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::push_front(const T &val) {
    insert(begin(), val);
}

// **********************************************************
// * Name: List<T>::push_front(T &&val)                     *
// * Description: Move version of inserting item at front   *
// *    of list using iterator insert and begin.            *
// * Author: Dustin Marsden                                 *
// * Reference: Stackoverflow.com                           *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::push_front(T &&val) {
    insert(begin(), std::move(val));
}

// **********************************************************
// * Name: List<T>::push_back(const T &val)                 *
// * Description: Calls insert using iterator end and       *
// *    the given data val to insert item at end of list    *
// * Author: Dustin Marsden                                 *
// * Reference: Stackoverflow.com                           *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::push_back(const T &val) {
    insert(end(), val);
}

// **********************************************************
// * Name: List<T>::push_back(T &&val)                      *
// * Description: Move version of inserting item at end     *
// *    of list using iterator insert and end.              *
// * Author: Dustin Marsden                                 *
// * Reference: Stackoverflow.com                           *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::push_back(T &&val) {
    insert(end(), std::move(val));
}

// **********************************************************
// * Name: List<T>::pop_front()                             *
// * Description: Removes first item of the list using      *
// *    iterator functions erase and begin                  *
// * Author: Dustin Marsden                                 *
// * Reference: Stackoverflow.com                           *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::pop_front() {
    erase(begin());
}

// **********************************************************
// * Name: List<T>::pop_back()                              *
// * Description: Removes last item of the list using       *
// *    iterator functions erase and end                    *
// * Author: Dustin Marsden                                 *
// * Reference: Stackoverflow.com                           *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::pop_back() {
    erase(--end());
}

// **********************************************************
// * Name: List<T>::remove(const T &val)                    *
// * Description: Creates an iterator at the start of the   *
// *    list. While the iterator is not at the end iterate  *
// *    through the list. If the value of the iterator is   *
// *    equal to val erase the item. If not, continue on.   *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::remove(const T &val) {
    auto itr = begin();
    while(itr != end()){
        if(itr.retrieve() == val)
            itr = erase(itr);
        else
            ++itr;
    }
}

// **********************************************************
// * Name: List<T>::remove_if(PREDICATE pred)               *
// * Description: Create an iterator at the beginning of    *
// *    the list. Iterate through the list checking if      *
// *    function Pred(*itr) is true. If true erase element  *
// *    at iterator location. If not, continue on.          *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
template<typename PREDICATE>
void List<T>::remove_if(PREDICATE pred) {
    auto itr = begin();
    while(itr != end()){
        if(pred(*itr) == true)
            itr = erase(itr);
        else
            ++itr;
    }
}

// **********************************************************
// * Name: List<T>::print(std::ostream &os, char ofc) const *
// * Description: Sets ofc to ' '. Then progresses through  *
//  *   the list using an iterator while outputting each    *
//  *   node's data                                         *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
void List<T>::print(std::ostream &os, char ofc) const {
    ofc = ' ';
    for(auto itr = begin(); itr != end(); ++itr){
        os << *itr << ofc;
    }
}

// **********************************************************
// * Name: List<T>::iterator List<T>::begin()               *
// * Description: Returns an iterator at the beginning of   *
// *    the list                                            *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head->next);
}

// **********************************************************
// * Name: List<T>::const_iterator List<T>::begin() const   *
// * Description: Returns a const iterator at the beginning *
// *    of the list                                         *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
typename List<T>::const_iterator List<T>::begin() const {
    return const_iterator(head->next);
}

// ***********************************************************
// * Name: List<T>::iterator List<T>::end()                  *
// * Description: Returns an iterator at the end of the list *
// * Author: Dustin Marsden                                  *
// * Date: 2/2/2022                                          *
// ***********************************************************
template<typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(tail);
}

// **********************************************************
// * Name: List<T>::const_iterator List<T>::end() const     *
// * Description: Returns a const iterator at the end of    *
// *    the list                                            *
// * Author: Dustin Marsden                                 *
// * Date: 2/2/2022                                         *
// **********************************************************
template<typename T>
typename List<T>::const_iterator List<T>::end() const {
    return const_iterator(tail);
}

// ******************************************************************************
// * Name: List<T>::iterator List<T>::insert(List::iterator itr, const T &val)  *
// * Description: Creates a node at iterator. Increases the size. Return        *
// *    iterator refers to newly inserted value.                                *
// * Author: Dustin Marsden                                                     *
// * Reference: Stackoverflow.com                                               *
// * Date: 2/2/2022                                                             *
// ******************************************************************************
template<typename T>
typename List<T>::iterator List<T>::insert(List::iterator itr, const T &val) {
    Node *p = itr.current;
    ++theSize;
    return iterator(p->prev = p->prev->next = new Node{val,p->prev,p});
}

// ******************************************************************************
// * Name: List<T>::iterator List<T>::insert(List::iterator itr, T &&val)       *
// * Description: Move version. Creates a node at iterator. Increases the size. *
// *    Return iterator refers to newly inserted value.                         *
// * Author: Dustin Marsden                                                     *
// * Reference: Stackoverflow.com                                               *
// * Date: 2/2/2022                                                             *
// ******************************************************************************
template<typename T>
typename List<T>::iterator List<T>::insert(List::iterator itr, T &&val) {
    Node *p = itr.current;
    ++theSize;
    return iterator(p->prev = p->prev->next = new Node{std::move(val),p->prev,p});
}

// **************************************************************
// * Name: List<T>::iterator List<T>::erase(List::iterator itr) *
// * Description: Creates a node at iterator to be removed. Sets*
// *    iterator for return to new node. Fixes pointers around  *
// *    node to be removed. Deletes node. Decreases size.       *
// *    Returns to next item in list.                           *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template<typename T>
typename List<T>::iterator List<T>::erase(List::iterator itr) {
    Node *p = itr.current;
    iterator retVal( p->next );
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retVal;


}

// **************************************************************************************
// * Name: List<T>::iterator List<T>::erase(List::iterator start, List::iterator end)   *
// * Description: Iterates through the list from start to end and removes all the       *
// *    elements between. Then returns end.                                             *
// * Author: Dustin Marsden                                                             *
// * Date: 2/2/2022                                                                     *
// **************************************************************************************
template<typename T>
typename List<T>::iterator List<T>::erase(List::iterator start, List::iterator end) {
    for( iterator itr = start; itr != end; )
        itr = erase( itr );
    return end;

}

// ***********************************************************
// * Name: List<T>::init()                                   *
// * Description: Initializer function to set up blank lists *
// * Author: Dustin Marsden                                  *
// * Date: 2/2/2022                                          *
// ***********************************************************
template<typename T>
void List<T>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

// **************************************************************
// * Name: operator==(const List<T> & lhs, const List<T> &rhs)  *
// * Description: Checks if the sizes are equal to verify that  *
// *    the list can even be equal. Starts iterators at         *
// *    beginning of each list. Iterate through checking if     *
// *    both sides are not equal. Once one is found return      *
// *    false. If none found has to be equal                    *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs) {
    if (lhs.size() != rhs.size()){
        return false;
    }
    for(auto lhs_itr = lhs.begin(), rhs_itr = rhs.begin(); lhs_itr != lhs.end(); ++lhs_itr, ++rhs_itr){
        if (*lhs_itr != *rhs_itr){
            return false;
        }
    }
    return true;
}

// **************************************************************
// * Name: operator!=(const List<T> & lhs, const List<T> &rhs)  *
// * Description: Uses == overload to check if list are equal   *
// *    and returns opposite of the result.                     *
// * Author: Dustin Marsden                                     *
// * Date: 2/2/2022                                             *
// **************************************************************
template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs) {
    return !(lhs == rhs);
}

// **************************************************************************
// * Name: std::ostream & operator<<(std::ostream & os, const List<T> &l)   *
// * Description: << overload operator. Calls print.                        *
// * Author: Dustin Marsden                                                 *
// * Date: 2/2/2022                                                         *
// **************************************************************************
template <typename T>
std::ostream & operator<<(std::ostream & os, const List<T> &l) {
    l.print(os);
    return os;
}
