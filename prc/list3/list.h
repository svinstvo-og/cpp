#ifndef LIST_H
#define LIST_H

#include "item.h"

class List
{
    Item *first;
    Item *last;
    unsigned int counter; //number of items with useful data
    void createEmptyList();
    void deepCopy(List &src);
public:
    List();
    List(List &other); //copy constructor
    ~List();
    List& operator=(List &rhs);
    bool isEmpty() const {return (counter == 0);}
    void clean();
    void pushBack(Data d);
    void pushFront(Data d);
    void popBack();
    void popFront();
    Data back() const{return last->prev->getData();}
    Data front() const{return first->next->getData();}
    void print() const;
};

#endif // LIST_H
