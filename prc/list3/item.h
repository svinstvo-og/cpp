#ifndef ITEM_H
#define ITEM_H

#include "datatype.h"

class Item
{
    Item *prev;
    Item *next;
    Data data;
public:
    Item();
    Item(Data payload);
    void setData(Data payload);
    Data getData() const;
    void print() const;
    void printLn() const;
    friend class List; //List is friend, so it can access even to private members of Item
};

#endif // ITEM_H
