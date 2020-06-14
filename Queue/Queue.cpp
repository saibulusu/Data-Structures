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

template <typename T>
T Queue<T>::peek() {
    if (size == 0) {
        throw std::runtime_error("Peeking out of bounds");
    } else {
        return array[0];
    }
}

template <typename T>
void Queue<T>::enqueue(T key) {
    array = (T*)realloc(array, (size + 1) * sizeof(T));
    array[size] = key;
    ++size;
}

template <typename T>
T Queue<T>::dequeue() {
    if (size == 0) {
        throw std::runtime_error("Dequeuing out of bounds");
    } else {
        T key = array[0];
        T* temp;
        temp = (T*)malloc((size - 1) * sizeof(T));
        for (int i = 0; i < size - 1; ++i) {
            temp[i] = array[i + 1];
        }
        delete array;
        array = temp;
        temp = nullptr;
        --size;
        return key;
    }
}

template <typename T>
void Queue<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}