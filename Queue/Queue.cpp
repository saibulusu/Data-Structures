#include <iostream>

/** Queue class declarations */
template <typename T>
class Queue {
private:
    int size;
    T* array;
public:
    Queue();
    ~Queue();
    T peek();
    void enqueue(T key);
    T dequeue();
    int getSize();
    void print();
};

template <typename T>
Queue<T>::Queue() {
    size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete array;
    array = nullptr;
}

template <typename T>
int Queue<T>::getSize() {
    return size;
}