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
        ForwardIterator(Node<T> *iter){ // Intenta agregar explicit
            current = iter;
        };

        ForwardIterator<T> operator=(ForwardIterator<T> iter){
            // No estás igualando current
            return *this;
        };

        bool operator!=(ForwardIterator<T> iter){
            return iter.current != current;
        };

        ForwardIterator<T> operator++(){
            if (!current->next){
                // Throw, cout solo imprime
                cout << "No se puede avanzar mas" <<endl;
            } else {
                current = current->next;
                // Estás construyendo iteradores
                return current;
            }
        };

        T operator*(){
            if (current){
                return current->data;
            } else {
                // Throw, cout solo imprime
                cout << "El iterador es nulo" << endl;
            }
        };
};

#endif