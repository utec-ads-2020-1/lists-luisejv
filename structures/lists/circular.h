#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() override {
            if (this->nodes == 0){
                cout << "La circular list esta vacia." << endl;
            } else {
                return this->head->data;
            }
        };
        T back() override{
            if (this->nodes == 0){
                cout << "La circular list esta vacia." << endl;
            } else {
                //cout << this->head->data <<endl;
                return this->head->prev->data;
            }
        };

        void push_front(T elem) override{
            auto newNode = new Node<T>();
            newNode->data = elem;
            newNode->next = this->head;
            newNode->prev = (this->nodes!=0) ? (this->nodes==1) ? this->head : this->head->prev : nullptr;
            //cout << newNode->next->data << " " << newNode->prev->data << " " << newNode->data << endl;
            if (this->nodes > 0){
                if (this->nodes > 1){
                    this->head->prev->next = newNode;
                    this->head->prev = newNode;
                } else {
                    this->head->prev = newNode;
                    this->head->next = newNode;
                }
            }
            this->head = newNode;
            this->nodes++;
        };
        void push_back(T elem) override{
            auto newNode = new Node<T>();
            newNode->data = elem;
            newNode->next = this->head;
            newNode->prev = (this->nodes!=0) ? (this->nodes==1) ? this->head : this->head->prev : nullptr;
            //cout << newNode->next << " " << newNode->prev << " " << newNode->data << endl;
            if (this->nodes > 0){
                if (this->nodes > 1){
                    this->head->prev->next = newNode;
                    this->head->prev = newNode;
                } else {
                    this->head->prev = newNode;
                    this->head->next = newNode;
                }
            } else {
                this->head = newNode;
            }
            this->nodes++;
        };
        void pop_front() override{
            if (this->nodes == 0){
                cout << "La circular list esta vacia." << endl;
            } else {
                if (this->nodes > 1) {
                    this->head->prev->next = this->head->next;
                    this->head->next->prev = this->head->prev;
                    auto temp = this->head->next;
                    this->head->killSelf();
                    this->head = temp;
                } else {
                    this->head->killSelf();
                }
                this->nodes--;
            }
        };
        void pop_back() override{
            if (this->nodes == 0){
                cout << "La circular list esta vacia." << endl;
            } else {
                if (this->nodes > 1){
                    this->head->prev->prev->next = this->head;
                    auto temp = this->head->prev->prev;
                    this->head->prev->killSelf();
                    this->head->prev = temp;
                } else {
                    this->head->killSelf();
                }
                this->nodes--;
            }
        };
        T operator[](int pos) override {
            if (empty())
            {
                cout<<"La circular list esta vacia."<<endl;
            }
            else
            {
                if (pos >= size() || pos < 0)
                {
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
                        //cout <<"\n"<< cont << " " << iterador->data << endl;
                    }
                    return iterador->data;
                }
            }
        };
        bool empty() override {
            return this->nodes == 0;
        };
        int size() override{
            return this->nodes;
        };
        void clear() override {
            while(this->head != this->head->prev){
                auto aux = this->head->next;
                this->head->killSelf();
                this->head = aux;
            }
            this->head->killSelf();
            this->nodes = 0;
        };
        void swapValuesNodes(int j, int k){
            //cout << "swapValuesNode: " << this->head->data << " " << this->tail << ":"<< this->tail->data << endl;
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
            //cout << "swapValuesNode: " << aux << ":" <<aux->data << " " << aux2 << ":" << aux2->data << endl;
            auto temp = aux->data;
            aux->data = aux2->data;
            aux2->data = temp;
            //cout << "swapValuesNode: " << this->head->data << " " << this->tail->data << endl;
        };
        void swapValues(int j, T value){
            auto aux = this->head;
            int count = 0;
            while (aux && count != j){
                aux = aux->next;
                count++;
            }
            aux->data = value;
            //cout << "swapValues: " << this->head->data << " " << this->tail->data << endl;
        }
        //function implemented to find values in forwardlist. Only for sort purposes, so I took out validators.
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
        void sort() override{
            if (this->nodes != 0){
                int i, j;
                T key;
                for (i = 1; i<this->nodes; i++){
                    key = findValue(i);
                    j = i -1;
                    while(j>=0 && findValue(j) > key){
                        swapValuesNodes(j+1, j);
                        j = j -1;
                    }
                    swapValues(j+1, key);
                }
            } else {
                cout << "La circular list esta vacia." << endl;
            }
        };
        void reverse() override {
            auto temp = this->head;
            while (temp != this->head->prev){
                auto aux = temp->next;
                temp->next = temp->prev;
                temp->prev = aux;
                temp = temp->next;
            }
            auto aux = temp->next;
            temp->next = temp->prev;
            temp->prev = aux;
        };

        BidirectionalIterator<T> begin(){
            BidirectionalIterator<T> iter (this->head);
            return iter;
        };
	    BidirectionalIterator<T> end(){
            BidirectionalIterator<T> iter (this->head->prev);
            return iter;
	    };

        string name() override{
            return "Circular Linked List";
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
        void merge(CircularLinkedList<T>& newList){
            this->sort();
            newList.sort();
            Node<T> *auxNewList = newList.head;
            auto auxOGList = this->head;
            while(auxNewList){
                //cout << auxNewList->data << " " << auxOGList->data << endl;
                if (auxNewList->data < auxOGList->data){
                    auto temp = auxNewList;
                    auxNewList = auxNewList->next;
                    auxNewList->prev = temp->prev;
                    temp->next = auxOGList;
                    temp->prev = auxOGList->prev;
                    auxOGList->prev->next= temp;
                    auxOGList->prev = temp;
                    this->nodes++;
                    this->head = temp;
                    //auxOGList = auxOGList->next;
                } else {
                    if (auxOGList->next != this->head){
                        auxOGList = auxOGList->next;
                    } else {
                        auto temp = auxNewList;
                        while(temp->next != auxNewList){
                            this->nodes++;
                            temp = temp->next;
                        }
                        this->nodes++;
                        auxOGList->next = auxNewList;
                        this->head->prev = auxNewList->prev;
                        auxNewList->prev->next = this->head;
                        auxNewList->prev = auxOGList;
                        break;
                    }
                }
            }
        };
};

#endif