#include <iostream>

/** ListNode class declarations */
template <typename T>
struct ListNode {
    ListNode<T>* next;
    T data;
};

/** LinkedList class declarations */
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
    head = tail = nullptr;
}

/** Destruct the LinkedList */
template <typename T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* cur = head;
    while (cur != tail) {
        ListNode<T>* curNext = cur->next;
        delete cur;
        cur = curNext;
    }
}

/** Get a value in the linked list at a certain index */
template <typename T>
T LinkedList<T>::get(int index) {
    if (index >= size || index < 0) {
        throw std::runtime_error("Getting out of bounds");
    }
    ListNode<T>* cur = head;
    while (index > 0) {
        cur = cur->next;
        --index;
    }
    return cur->data;
}

/** Insert a value into the linked list at the end */
template <typename T>
void LinkedList<T>::insert(T key) {
    if (size == 0) {
		head = tail = new ListNode<T>;
		tail->data = key;
        tail->next = nullptr;
    } else {
	    tail->next = new ListNode<T>;    
	    tail->next->data = key;
	    tail->next->next = nullptr;
	    tail = tail->next;
    }
	++size;
}

/** Insert a value into the linked list at a certain index */
template <typename T>
void LinkedList<T>::insert(int index, T key) {
    if (index > size + 1) {
        throw std::runtime_error("Inserting out of bounds");
    }
    if (index == size) {
        insert(key);
    } else if (index == 0) {
		ListNode<T>* newHead = new ListNode<T>;
		newHead->next = head;
		newHead->data = key;
		head = newHead;
		++size;
	} else {
		ListNode<T>* cur = head;
		while (index > 1) {
			cur = cur->next;
			--index;
		}
		ListNode<T>* newNode = new ListNode<T>;
		newNode->data = key;
		newNode->next = cur->next;
		cur->next = newNode;
		++size;
	}
}

/** Alter a value in the linked list at a certain index */
template <typename T>
T LinkedList<T>::alter(int index, T key) {
    if (index >= size || index < 0) {
        throw std::runtime_error("Altering out of bounds");
    }
	ListNode<T>* cur = head;
	while (index > 0) {
		cur = cur->next;
		--index;
	}
	T val = cur->data;
	cur->data = key;
	return val;
}

/** Remove a value in the linked list at a certain index */
template <typename T>
T LinkedList<T>::remove(int index) {
    if (index >= size || index < 0) {
        throw std::runtime_error("Removing out of bounds");
    }
    ListNode<T>* rem = head;
    if (index == 0) {
        T val = head->data;
        head = head->next;
        delete rem;
        rem = nullptr;
        --size;
        return val;
    }
    while (index > 1) {
        rem = rem->next;
        --index;
    }
    ListNode<T>* temp = rem->next;
    rem->next = temp->next;
    T val = temp->data;
    delete temp;
    --size;
    return val;
}

/** Access the size of the linked list */
template <typename T>
int LinkedList<T>::getSize() {
    return size;
}

/** Print the elements in the linked list */
template <typename T>
void LinkedList<T>::print() {
    ListNode<T>* cur = head;
    while (cur != nullptr) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
