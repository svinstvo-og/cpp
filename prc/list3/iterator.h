#ifndef ITERATOR_H
#define ITERATOR_H

#include "datatype.h"

class Iterator
{
public:
    Iterator();
    virtual ~Iterator(){}
    virtual void reset() = 0;
    virtual Data& data() = 0;
    virtual bool next() = 0;
};

//forward declarations
class List;
class Item;

class ListIterator : public Iterator{
    List *list;
    Item *current;
public:
    ListIterator(List *l);
    virtual ~ListIterator(){}
    virtual void reset();
    virtual Data& data();
    virtual bool next();
};

#endif // ITERATOR_H
