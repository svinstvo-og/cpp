#include "item.h"
#include <iostream>

Item::Item()
    : prev(nullptr), next(nullptr)
{}

Item::Item(Data payload)
    : prev(nullptr), next(nullptr), data(payload)
{}

void Item::setData(Data payload){
    data = payload;
}

Data Item::getData() const{
    return data;
}

void Item::print() const{
    std::cout << getData();
}

void Item::printLn() const{
    print();
    std::cout << std::endl;
}
