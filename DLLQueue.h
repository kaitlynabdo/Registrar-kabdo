#include <iostream>
#include "GenDLL.h"
#include <experimental/optional>
#include <exception>
#ifndef GENQUEUE_H
#define GENQUEUE_H


template <class T>
class DLLQueue{
    public:
        DLLQueue(){
            GenDLL<T> dll;
            numElements = 0;
            head = dll.getFront();
            tail = dll.getBack();
        }
        ~DLLQueue(){
            if(head != nullptr)
               delete head;
        }

        void insert(T d);
        T removeFrontOfLine();
        T peek();
        T find(int i);
        bool isEmpty();

    private:
        ListNode<T> *head;
        ListNode<T> *tail;
        int numElements;
        GenDLL<T> dll;
};

template <class T>
void DLLQueue<T>::insert(T d){
    dll.insertBack(d);
    ++numElements;
}

template <class T>
T DLLQueue<T>::removeFrontOfLine(){
    try{
        T r = dll.removeFront();
        --numElements;
        return r;
    }
    catch(exception& e){
        cout << "exception caught: " << e.what() << endl;

    }
}

template <class T>
T DLLQueue<T>::peek(){
    try{
        return head->data;
    }
    catch(exception& e){
        cout << "exception caught: " << e.what() << endl;
    }
}

template <class T>
bool DLLQueue<T>::isEmpty(){
    return (numElements == 0);
}

template <class T>
T DLLQueue<T>::find(int i){
    T temp = dll.findPos(i);
    return temp;
}

#endif
