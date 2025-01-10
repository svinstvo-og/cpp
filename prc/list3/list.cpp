#include "list.h"
#include <iostream>
#include <stdexcept>
#include "iterator.h"

List::List() {
    createEmptyList();
}

/*
//implicit copy constructor -> shallow copy
List::List(List &other)
    : first(other.first),
    last(other.last),
    counter(other.counter)
{}
*/

//custom copy constructor -> deep copy
List::List(List &other){
    createEmptyList();
    deepCopy(other);
}


//shallow copy and memory leak
/*
List& List::operator=(List &rhs){
    this->first = rhs.first;
    this->last = rhs.last;
    this->counter = rhs.counter;
    return *this;
}
*/

List& List::operator=(List &rhs){
    if(this == &rhs){
        return *this;
    }
    this->clean();
    this->deepCopy(rhs);
    return *this;
}

//cpoies data from src list to *this list
void List::deepCopy(List &src){
    Item *curr = src.first->next;
    while(curr != src.last){
        this->pushBack(curr->getData());
        curr = curr->next;
    }
    this->failBit = src.failBit;
}

void List::createEmptyList(){
    first = new Item;
    last = new Item;
    counter = 0;
    failBit = false;
    first->next = last;
    last->prev = first;
}

List::~List(){
    clean();
    delete first;
    delete last;
}

void List::clean() noexcept{
    //unexpected exception
    //throw ListException("This is bad idea!");
    while(!isEmpty()){
        popFront();
    }
}


void List::pushBack(Data d){
    /*
    //1. store data d in last item
    this->last->setData(d);
    //2. create new item in memory
    Item *tmp = new Item;
    //3. connect new item after last item
    last->next = tmp;
    //4. connect last item in front of new item
    tmp->prev = last;
    //5. move last to new item
    last = tmp;
    //6. update counter
    counter++;*/
    try{
        last->next = new Item;
    }
    catch(std::bad_alloc &e){
        throw ListException("Memory allocation failed while pushing new element");
    }

    last->setData(d);
    last->next->prev = last;
    last = last->next;
    counter++;
}

// last <-> first
// next <-> prev
void List::pushFront(Data d){
    first->prev = new(std::nothrow) Item;
    if(!first->prev){
        throw ListException("Memory allocation failed while pushing new element");
    }
    first->setData(d);
    first->prev->next = first;
    first = first->prev;
    counter++;
}

void List::popFront(){
    if(isEmpty()){
        throw ListException("Popping from empty list");
    }
    first = first->next;
    delete first->prev; //release memory!
    first->prev = nullptr;
    counter--;
}

/*
//1. use return value
bool List::popFront(){
    if(isEmpty()){
        return false;
    }
    first = first->next;
    delete first->prev; //release memory!
    first->prev = nullptr;
    counter--;
    return true;
}
*/

//2. use function parameter passed by reference
/*
void List::popFront(bool &ok){
    ok = true;
    if(isEmpty()){
        ok = false;
        return;
    }
    popFront();
}
*/

//3. global variable
/*
void List::popFront(){
    if(isEmpty()){
        error = true; //error would be global variable
        return;
    }
    first = first->next;
    delete first->prev; //release memory!
    first->prev = nullptr;
    counter--;
}
*/

//4. use attribute
/*
void List::popFront(){
    if(isEmpty()){
        failBit = true; //error would be global variable
        return;
    }
    first = first->next;
    delete first->prev; //release memory!
    first->prev = nullptr;
    counter--;
}
*/

void List::popBack(){
    if(isEmpty()){
        throw ListException("Popping from empty list");
    }
    last = last->prev;
    delete last->next; //release memory!
    last->next = nullptr;
    counter--;
}

void List::print() const{
    Item *curr = first->next;
    while(curr!=last){
        curr->printLn();
        curr = curr->next;
    }
    if(isEmpty()){
        std::cout << "List is empty!" << std::endl;
    }
}

ListIterator* List::getIterator(){
    return new ListIterator(this);
}
