#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator(){
            current = nullptr;
        };
        BidirectionalIterator(Node<T>* iter){
            current = iter;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> iter){
            return *this;
        };

        bool operator!=(BidirectionalIterator<T> iter){
            return current != iter.current;
        };

        BidirectionalIterator<T> operator++(){
            if (!current->next){
                cout << "No se puede avanzar mas" <<endl;
            } else {
                current = current->next;
                return current;
            }
        };

        BidirectionalIterator<T> operator--(){
            if (!current->prev){
                cout << "No se puede retroceder mas" <<endl;
            } else {
                current = current->prev;
                return current;
            }
        };

        T operator*(){
            if (current){
                return current->data;
            } else {
                cout << "El iterador es nulo" << endl;
            }
        };
};

#endif