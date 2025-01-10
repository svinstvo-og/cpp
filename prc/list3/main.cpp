#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List l;

    for(int i = 1; i <= 5; i++){
        l.pushBack(i);
        l.pushFront(10 - i);
    }
    List copyOfL(l); //copy constructor
    l.clean();
    copyOfL.print();
    return 0;
}
