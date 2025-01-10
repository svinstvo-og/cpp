#ifndef VECTOR_H
#define VECTOR_H

#include "datatype.h"

class Vector
{
    unsigned int size;
    Data *array;
    void deepCopy(Vector &src);
public:
    Vector(unsigned int capacity);
    Vector(Vector &other);
    ~Vector();
    Vector& operator=(Vector &rhs);
    unsigned int getSize(){return size;}
    void resize();
    Data& at(unsigned int index);
    Data& operator[](unsigned int index);
};

#endif // VECTOR_H
