#include <iostream>
#include "ListNode.h"
#ifndef GENDLL_h
#define GENDLL_h
using namespace std;

template <class T>
class GenDLL {
public:
     ListNode<T>* front;
     ListNode<T>* back;
     unsigned int size;

     GenDLL() {
          front = nullptr;
          back = nullptr;
          size = 0;
     }

     ~GenDLL() {
          if(front != nullptr)
               delete front;
     }

     void insertFront(T d);
     void insertBack(T d);
     T removeFront();
     T removeBack();
     void printList();
     T find(T val);
     unsigned int getSize();
     bool isEmpty();
     T deletePos(int pos);
     T findPos(int i);
     ListNode<T>* getFront();
     ListNode<T>* getBack();
     ListNode<T>* remove(T key);
};

template <class T>
unsigned int GenDLL<T>::getSize() {
     return size;
}

template <class T>
bool GenDLL<T>::isEmpty() {
    if (size == 0)
        return true;

    return false;
}

template <class T>
void GenDLL<T>::printList() {
     ListNode<T>* curr = front;
     while(curr != nullptr)
     {
          cout << curr->data << endl;
          curr = curr->next;
     }
}

template <class T>
void GenDLL<T>::insertFront(T d) {
    ListNode<T>* node = new ListNode<T>(d);
        if(size == 0){
            //we have an empty list
            back = node;
        }
        else{
            //not an empty list
            front->prev = node;
            node->next = front;
        }
        front = node;
        ++size;
}

template <class T>
void GenDLL<T>::insertBack(T d) {
    ListNode<T>* node = new ListNode<T>(d);

    if(size == 0){
        front = node;
    }
    else{
        back->next = node;
        node->prev = back;
    }
    back = node;
    ++size;
}

template <class T>
T GenDLL<T>::removeFront() {
    //check if its empty before proceeding
    if(size == 0){
        cout << "List is empty: nothing to remove." << endl;
        return T();
    }
    ListNode<T>* ft = front;

    if(size == 1){ //if one node in the list
        back = nullptr;
    }
    else{ //more than one node inthe list
       front->next->prev = nullptr;
    }
    front = front->next;
    ft->next = nullptr;
    // int temp = ft->data;
    T temp = ft->data;
    delete ft;
    --size;

    return temp;
}



template <class T>
ListNode<T>* GenDLL<T>::remove(T d) {
        if (size == 0){
        return nullptr;
    }
    ListNode<T>* curr = front;
    while(curr->data != d){
        //look for te key/value to be removed
        curr = curr->next;
        if(curr == nullptr){ //val we are looking for does not exist
            return nullptr;
        }
        //we found the node/value to be removed

        if(curr == front){
            //node to be removed is the front
            front = curr->next;
        }
        else{
            //not the front
            curr->prev->next = curr->next;
        }
        if(curr == back){
            back = curr->prev;
        }
        else{
            curr->next->prev = curr->prev;
        }

        curr->next = nullptr;
        curr->prev = nullptr;

        --size;
        return curr;
    }
}

template <class T>
T GenDLL<T>::find(T value) {

     ListNode<T>* curr = front;
     int pos = -1;
     if(curr == nullptr)
          return;
     while(curr != nullptr)
     {
          if(curr->data == value)
               break;
          else
               curr = curr->next;
        ++pos;
     }
     return pos;
}

template <class T>
T GenDLL<T>::deletePos(int d) {
     int pos = 0;
     ListNode<T>* prev = front;
     ListNode<T>* curr = front;

     while (pos != d)
     {
          prev = curr;
          curr = curr->next;
          ++pos;
     }

     prev->next = curr->next;
     curr->next = nullptr;
     T temp = curr->data;
     --size;

     delete curr;

     return d;
}

template <class T>
ListNode<T>* GenDLL<T>::getFront()
{
	if(isEmpty())
		return nullptr;
	return front;
}

template <class T>
ListNode<T>* GenDLL<T>::getBack()
{
	if(isEmpty())
		return nullptr;
	return back;
}





template <class T>
T GenDLL<T>::findPos(int i) {

     ListNode<T>* curr = front;
     int pos = -1;
     // if(curr == nullptr)
     //      return;
     while(pos != i)
     {
          if(pos == i)
               break;
          else
               curr = curr->next;
        ++pos;
     }
     return curr->data;
}

#endif
