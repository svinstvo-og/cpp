#include "vector.h"
#include <stdexcept>
#include <cstring>

Vector::Vector(unsigned int capacity)
    : size(capacity), array(new Data[size])
{}

Vector::Vector(Vector &other)
    : size(other.size), array(new Data[size])
{
    this->deepCopy(other);
}

void Vector::deepCopy(Vector &src){
    for(unsigned int i = 0; i < src.size; i++){
        //this->array[i] = src.array[i];
        (*this)[i] = src[i];
    }
}

Vector::~Vector(){
    delete [] array;
}

Vector& Vector::operator=(Vector &rhs){
    if(this == &rhs){
        return *this;
    }
    if(this->size!=rhs.size){
        delete [] this->array;
        this->size = rhs.size;
        this->array = new Data[this->size];
    }
    this->deepCopy(rhs);
    return *this;
}


Data& Vector::operator[](unsigned int index){
    if(index >= size){
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}


Data& Vector::at(unsigned int index){
    return (*this)[index];
    //return this->operator[](index);
}

void Vector::resize(){
    Data *tmp = new Data[2*size];
    std::memcpy(tmp, this->array,
                size*sizeof(Data));
    delete [] this->array;
    size = size*2;
    this->array = tmp;
}
