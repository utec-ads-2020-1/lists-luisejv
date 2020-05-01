#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <string>
#include <iostream>

using namespace std;

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList() : List<T>() {}

    T front() override
    {
        if (this->nodes == 0)
        {
            //throw string("La linked list esta vacia");
            cout << "La linked list esta vacia." << endl;
        }
        else
        {
            return this->head->data;
        }
    }

    T back() override
    {
        if (this->nodes == 0)
        {
            //throw string("La linked list esta vacia");
            cout << "La linked list esta vacia." << endl;
        }
        else
        {
            return this->tail->data;
        }
    }

    void push_front(T elem) override
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = elem;
        newNode->prev = nullptr;
        if (this->head == nullptr)
        {
            newNode->next = nullptr;
            this->tail = newNode;
        }
        else
        {
            this->head->prev = newNode;
            newNode->next = this->head;
        }
        this->head = newNode;
        this->nodes++;
    };

    void push_back(T elem) override
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = elem;
        newNode->next = nullptr;
        if (this->tail == nullptr)
        {
            newNode->prev = nullptr;
            this->head = newNode;
        }
        else
        {
            this->tail->next = newNode;
            newNode->prev = this->tail;
        }
        this->tail = newNode;
        this->nodes++;
    };

    void pop_front() override
    {
        this->head = this->head->next;
        this->head->prev->killSelf();
        // delete this->head->prev;
        this->head->prev = nullptr;
        this->nodes--;
    };

    void pop_back() override
    {
        this->tail = this->tail->prev;
        this->tail->next->killSelf();
        // delete this->tail->next;
        this->tail->next = nullptr;
        this->nodes--;
    };

    T operator[](int pos) override
    {
        if (empty())
        {
            //throw string("La linked list esta vacia.");
            cout<<"La linked list esta vacia."<<endl;
        }
        else
        {
            if (pos >= size() || pos < 0)
            {
                //throw string("Posicion incorrecta.");
                cout<<"Posicion incorrecta."<<endl;
            }
            else
            {
                int cont = 0;
                auto iterador = this->head;
                while (cont != pos)
                {
                    cont++;
                    iterador = iterador->next;
                }
                return iterador->data;
            }
        }
    }
    bool empty() override
    {
        return this->head == nullptr || this->tail == nullptr;
    };
    int size() override
    {
        return this->nodes;
    };
    void clear() override
    {
        while (this->head != this->tail->next)
        {
            this->head = this->head->next;
            delete this->head->prev;
            //this->head->prev->killSelf();
        }
        this->tail = nullptr;
        this->head = this->tail;
        this->nodes = 0;
    };
    void swapValuesNodes(int j, int k){
        auto aux = this->head;
        auto aux2 = this->head;
        int count = 0;
        while (aux && count != j){
            aux = aux->next;
            count++;
        }
        count = 0;
        while (aux2 && count != k){
            aux2 = aux2->next;
            count++;
        }
        auto temp = aux->data;
        aux->data = aux2->data;
        aux2->data = temp;
    };
    void swapValues(int j, T value){
        auto aux = this->head;
        int count = 0;
        while (aux && count != j){
            aux = aux->next;
            count++;
        }
        aux->data = value;
    }
    //function implemented to find values in linkedlist. Only for sort purposes, so I took out validators.
    T findValue(int pos){
        int cont = 0;
        auto iterador = this->head;
        while (cont != pos)
        {
            cont++;
            iterador = iterador->next;
        }
        return iterador->data;
    };
    void sort() override
    {
        //Insertion sort
        if (this->nodes != 0){
            int i, j;
            T key;
            for (i = 1; i < this->nodes; i++){
                key = findValue(i);
                j = i - 1;
                while (j>= 0 && findValue(j) > key){
                    swapValuesNodes(j+1,j);
                    j = j - 1;
                }
                swapValues(j+1,key);
            }
        } else {
            cout << "La linked list esta vacia." << endl;
        }
    };
    void reverse() override{
        auto auxTail = this->tail;
        auto auxHead = this->head;
        while (auxTail != auxHead){
            auto temp = auxTail->data;
            auxTail->data = auxHead->data;
            auxHead->data = temp;
            auxTail = auxTail->prev;
            if (auxTail==auxHead)
                break;
            auxHead = auxHead->next;
        }
    };
    BidirectionalIterator<T> begin(){
        BidirectionalIterator<T> iter (this->head);
        return iter;
    };
    BidirectionalIterator<T> end(){
        BidirectionalIterator<T> iter (this->tail);
        return iter;
    };
    string name() override
    {
        return "Linked List";
    };
    /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
    void merge(LinkedList<T> & newList){
        this->sort();
        newList.sort();
        Node<T> *auxNewList = newList.head;
        auto auxOGList = this->head;
        while(auxNewList){
            //cout << auxNewList->data << " " << auxOGList->data << endl;
            if (auxNewList->data < auxOGList->data){
                auto temp = auxNewList;
                if (auxNewList->next) {
                    auxNewList = auxNewList->next;
                    auxNewList->prev = nullptr;
                } else {
                    auxNewList = nullptr;
                }
                if (auxOGList->prev != nullptr){
                    auxOGList->prev->next = temp;
                    temp->prev = auxOGList->prev;
                } else {
                    this->head = temp;
                }
                this->nodes++;
                auxOGList->prev = temp;
                temp->next = auxOGList;
            } else {
                if (auxOGList->next){
                    auxOGList = auxOGList->next;
                } else {
                    auxOGList->next = auxNewList;
                    auxNewList->prev = auxOGList;
                    while(auxNewList){
                        this->nodes++;
                        auxNewList = auxNewList->next;
                    }
                    this->tail = newList.tail;
                    break;
                }
            }
        }
    };

};

#endif