#ifndef LIST_H
#define LIST_H

#include "item.h"
#include "listexception.h"

class ListIterator;

class List
{
    Item *first;
    Item *last;
    unsigned int counter; //number of items with useful data
    void createEmptyList();
    void deepCopy(List &src);
    bool failBit;
public:
    List();
    List(List &other); //copy constructor
    ~List();
    List& operator=(List &rhs);
    bool good() const {return !failBit;}
    void clearBit(){failBit = false;}
    bool isEmpty() const noexcept {return (counter == 0);}
    void clean() noexcept;
    unsigned int count() const noexcept {return counter;}
    void pushBack(Data d);
    void pushFront(Data d);
    void popBack();
    //function overloading
    void popFront();
    void popFront(bool &ok);
    Data back() const{
        if(isEmpty()){
            throw ListException("Accessing last element of empty list");
        }
        return last->prev->getData();
    }
    Data front() const{
        if(isEmpty()){
            throw ListException("Accessing first element of empty list");
        }
        return first->next->getData();
    }
    void print() const;
    friend class ListIterator;
    ListIterator* getIterator();
};

#endif // LIST_H
