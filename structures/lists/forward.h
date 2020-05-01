#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() override {
            if (this->nodes != 0){
                return this->head->data;
            } else {
                cout << "La forward list esta vacia." << endl;
            }
        };
        T back() override{
            if (this->nodes != 0){
                return this->tail->data;
            } else {
                cout << "La forward list esta vacia." << endl;
            }
        };
        void push_front(T elem) override{
            auto newNode = new Node<T>();
            newNode->data = elem;
            if (!this->head){
                newNode->next = nullptr;
                this->tail = newNode;
            } else {
                newNode->next = this->head;
            }
            this->head = newNode;
            this->nodes++;
        };
        void push_back (T elem) override{
            auto newNode = new Node<T>();
            newNode->data = elem;
            newNode->next = nullptr;
            if (!this->tail){
                this->head = newNode;
            } else {
                this->tail->next = newNode;
            }
            this->tail = newNode;
            this->nodes++;
        };
        void pop_front() override{
             auto temp = this->head->next;
             this->head->killSelf();
             this->head = temp;
             this->nodes--;
        };
        void pop_back() override{
            auto temp = this->head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            this->tail = temp;
            this->tail->next->killSelf();
            this->tail->next = nullptr;
            this->nodes--;
        };
        T operator[](int pos){
            if (empty()){
                cout << "La forward list esta vacia." << endl;
            } else {
                if (pos >= size() || pos < 0){
                    cout << "Posicion incorrecta." << endl;
                } else {
                    int cont = 0;
                    auto it = this->head;
                    while (cont!=pos){
                        cont++;
                        it = it->next;
                    }
                    return it->data;
                }
            }
        };
        bool empty() override{
            return this->nodes == 0;
        };
        int size() override{
            return this->nodes;
        };
        void clear() override {
            while (this->head != this->tail->next){
                auto temp = this->head->next;
                this->head->killSelf();
                this->head = temp;
            }
            this->tail->killSelf();
            this->tail = nullptr;
            this->head = this->tail;
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
        void sort() override
        {
            //Insertion sort
            if (this->nodes != 0){
                int i, j;
                T key;
                for (i = 1; i < this->nodes; i++){
                    key = findValue(i);
                    j = i - 1;
                    //cout << findValue(j) << endl;
                    while (j>= 0 && findValue(j) > key){
                        swapValuesNodes(j+1,j);
                        j = j - 1;
                    }
                    swapValues(j+1,key);
                }
            } else {
                cout << "La forward list esta vacia." << endl;
            }
        };
        void reverse() override {
            auto auxTail = this->tail;
            auto auxHead = this->head;
            int count = this->nodes-1;
            while (auxTail != auxHead){
                auto temp = auxTail->data;
                auxTail->data = auxHead->data;
                auxHead->data = temp;
                count--;
                int aux = 0;
                auxTail = this->head;
                while (aux != count){
                    aux++;
                    auxTail = auxTail->next;
                }
                if (auxTail==auxHead)
                    break;
                auxHead = auxHead->next;
            }
        };

        ForwardIterator<T> begin(){
            ForwardIterator<T> iter (this->head);
            return iter;
        };
	    ForwardIterator<T> end(){
            ForwardIterator<T> iter (this->tail);
            return iter;
	    };

        string name() override{
            return "Forward List";
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
        void merge(ForwardList<T>& newList){
            this->sort();
            newList.sort();
            Node<T> *auxNewList = newList.head;
            auto auxOGList = this->head;
            while(auxNewList){
                //cout << auxNewList->data << " " << auxOGList->data << endl;
                if(auxNewList->data < auxOGList->data){
                    auto temp = auxNewList;
                    auxNewList = auxNewList->next;
                    temp->next = auxOGList;
                    if (auxOGList == this->head){
                        this->head = temp;
                    } else {
                        auto aux = this->head;
                        while(aux->next != auxOGList){
                            aux = aux->next;
                        }
                        aux->next = temp;
                    }
                    this->nodes++;
                    /*for (int i = 0; i < this->nodes; i++){
                        cout << findValue(i) << " ";
                    }
                    cout << endl;*/
                } else {
                    if (auxOGList->next){
                        auxOGList = auxOGList->next;
                    } else {
                        auxOGList->next = auxNewList;
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