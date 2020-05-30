#include <iostream>

template <typename T>
struct ListNode {
    ListNode* next;
    T data;
};

/** Template for the LinkedList class */
template <typename T>
class LinkedList {
private:
    int size;
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    LinkedList();
    ~LinkedList();
    T get(int index);
    void insert(T key);
    void insert(int index, T key);
    T alter(int index, T key);
    T remove(int index);
    int getSize();
    void print();
};

/** Construct the LinkedList with no initial information */
template <typename T>
LinkedList<T>::LinkedList() {
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* cur = head;
    while (cur != tail) {
        ListNode<T>* curNext = cur->next;
        delete cur;
        cur = curNext;
    }
}
