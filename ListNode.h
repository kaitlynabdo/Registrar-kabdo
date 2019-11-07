#ifndef LISTNODE_h
#define LISTNODE_h

#include <iostream>
using namespace std;

template <class T>
class ListNode {
public:
     ListNode();
     ListNode(T d);
     ~ListNode();

     ListNode<T>* next;
     ListNode<T>* prev;
     T data;
};

template <class T>
ListNode<T>::ListNode() {
     data = nullptr;
     next = nullptr;
     prev = nullptr;
}

template <class T>
ListNode<T>::ListNode(T d) {
     data = d;
     next = nullptr;   //could be nullptr depending on version of C++
     prev = nullptr;   //could be nullptr depending on version of C++
}

template <class T>
ListNode<T>::~ListNode() {
     if(next != nullptr) {
		delete next;
		delete prev;
	}
}

#endif
