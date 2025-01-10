#include "iterator.h"
#include "list.h"

Iterator::Iterator() {}

ListIterator::ListIterator(List *l)
    : Iterator(), list(l), current(l->first)
{}


void ListIterator::reset(){
    current = list->first;
}

Data& ListIterator::data(){
    return current->data;
}

bool ListIterator::next(){
    if(current == list->last){
        current = list->first;
    } else{
       current = current->next;
    }
    return current != list->last;
}
