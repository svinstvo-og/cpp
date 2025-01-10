#include "list.h"
#include <iostream>

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
}

void List::createEmptyList(){
    first = new Item;
    last = new Item;
    counter = 0;
    first->next = last;
    last->prev = first;
}

List::~List(){
    clean();
    delete first;
    delete last;
}

void List::clean(){
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
    last->setData(d);
    last->next = new Item;
    last->next->prev = last;
    last = last->next;
    counter++;
}

// last <-> first
// next <-> prev
void List::pushFront(Data d){
    first->setData(d);
    first->prev = new Item;
    first->prev->next = first;
    first = first->prev;
    counter++;
}

void List::popFront(){
    if(isEmpty()){
        return;
        //better solution -> throw an exception
    }
    first = first->next;
    delete first->prev; //release memory!
    first->prev = nullptr;
    counter--;
}


void List::popBack(){
    if(isEmpty()){
        return;
        //better solution -> throw an exception
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
