#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;

    void killSelf()
    {
        delete this;
    };

    ~Node();
};

template<typename T>
Node<T>::~Node() = default;

#endif