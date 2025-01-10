#include <iostream>
#include "list.h"
#include "iterator.h"

using namespace std;

void printSequence(Iterator *it){
    it->reset();
    while(it->next()){
        cout << it->data() << " ";
    }
    cout << endl;
}

Data findMin(Iterator *it){
    it->reset();
    Data min;
    bool init = false;
    while(it->next()){
        if(!init){
            min = it->data();
            init = true;
        } else if(min > it->data()){
            min = it->data();
        }
    }
    if(!init){
        throw logic_error("Finding minimum in empty sequence");
    }
    return min;
}

int main()
{
    List l;
    ListIterator *it = nullptr;
    /*
    //1. return value
    if(!l.popFront()){
        cerr << "Cannot pop from empty list!" << endl;
    }
    */

    //2. use of function parameter passed by reference
    /*
    bool ok = false;
    l.popFront(ok);
    if(!ok){
        cerr << "Cannot pop from empty list!" << endl;
    }
    */

    /*
    //3. use of global variable
    l.popFront();
    if(error){
        cerr << "Cannot pop from empty list!" << endl;
    }
    */

    //4. use of attribute
    /*
    l.popFront();
    if(!l.good()){
        cerr << "Cannot pop from empty list!" << endl;
        l.clearBit();
    }*/
    try{
        cout << "Start of TRY block" << endl;


        cout << "Before filling" << endl;
        for(int i = 1; i <= 5; i++){
            l.pushFront(10 - i);
            l.pushBack(i);

        }
        cout << "After filling" << endl;
        it = l.getIterator();
        printSequence(it);
        l.clean();
        l.popFront();
        cout << "Minimal value: " << findMin(it) << endl;
        delete it;
        it = nullptr;
        cout << "End of TRY block" << endl;
    }
    catch(ListException &e){
        cerr << "Logic error detected: ";
        cerr << e.what() << endl;
        if(it){
            delete it;
        }
    }
    /*
    catch(bad_alloc &e){
        cerr << "Memory allocation failed: ";
        cerr << e.what() << endl;
    }
    catch(exception &e){
        cerr << "Exception in standard library detected: ";
        cerr << e.what() << endl;
    }
    catch(...){ //universal handler
        cerr << "Something's wrong" << endl;
    }
    */

    cout << "This is after handlers" << endl;
    /*List copyOfL(l); //copy constructor
    l.clean();
    copyOfL.print();*/
    return 0;
}
