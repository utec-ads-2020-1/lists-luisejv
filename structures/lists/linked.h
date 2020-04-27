#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList() : List<T>() {}

    T front() override
    {
        if (empty())
        {
            throw string("La linked list esta vacia");
        }
        else
        {
            return this->head->data;
        }
    };

    T back() override
    {
        if (empty())
        {
            throw string("La linked list esta vacia");
        }
        else
        {
            return this->tail->data;
        }
    };

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

    void push_back(T elem)
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

    void pop_front()
    {
        this->head = this->head->next;
        this->head->prev->killSelf();
        // delete this->head->prev;
        this->head->prev = nullptr;
        this->nodes--;
    };

    void pop_back()
    {
        this->tail = this->tail->prev;
        this->tail->next->killSelf();
        // delete this->tail->next;
        this->tail->next = nullptr;
        this->nodes--;
    };

    T operator[](int pos)
    {
        if (empty())
        {
            throw string("La linked list esta vacia.");
        }
        else
        {
            if (pos >= size() || pos < 0)
            {
                throw string("Posicion incorrecta.");
            }
            else
            {
                int cont = 0;
                auto iterador = this->head;
                while (ind != index)
                {
                    cont++;
                    iterador = iterador->next;
                }
                return iterador->data;
            }
        }
    };

    bool empty()
    {
        return this->head == nullptr || this->tail == nullptr;
    };

    int size()
    {
        return this->nodes;
    };

    void clear()
    {
        while (this->head != this->tail->next)
        {
            this->head = this->head->next;
            delete this->head->prev;
        }
        this->tail = nullptr;
        this->head = this->tail;
        this->nodes = 0;
    };

    void sort()
    {
        //Insertion Sort
        int i, j;
        T key;
        for (i = 1; i < this->nodes; i++)
        {
            key = this->head->next->data;
            j = i - 1;
            while (j >= 0 && this[j] > key)
            {
            }
        }
    };

    void reverse();

    BidirectionalIterator<T> begin();
    BidirectionalIterator<T> end();

    string name()
    {
        return "Linked List";
    }

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
    void merge(LinkedList<T> &);
};

#endif