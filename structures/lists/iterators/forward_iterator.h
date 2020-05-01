#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator(){
            current = nullptr;
        };
        ForwardIterator(Node<T> *iter){
            current = iter;
        };

        ForwardIterator<T> operator=(ForwardIterator<T> iter){
            return *this;
        };

        bool operator!=(ForwardIterator<T> iter){
            return iter.current != current;
        };

        ForwardIterator<T> operator++(){
            if (!current->next){
                cout << "No se puede avanzar mas" <<endl;
            } else {
                return current->next;
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