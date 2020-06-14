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

/** Construct the Queue with no initial elements */
template <typename T>
Queue<T>::Queue() {
    size = 0;
}

/** Destruct the Queue */
template <typename T>
Queue<T>::~Queue() {
    delete array;
    array = nullptr;
}

/** Access the size of the Queue */
template <typename T>
int Queue<T>::getSize() {
    return size;
}

/** Peek the element at the front of the Queue */
template <typename T>
T Queue<T>::peek() {
    if (size == 0) {
        throw std::runtime_error("Peeking out of bounds");
    } else {
        return array[0];
    }
}

/** Enqueue a value to the end of the Queue */
template <typename T>
void Queue<T>::enqueue(T key) {
    array = (T*)realloc(array, (size + 1) * sizeof(T));
    array[size] = key;
    ++size;
}

/** Dequeue a value from the front of the Queue */
template <typename T>
T Queue<T>::dequeue() {
    if (size == 0) {
        throw std::runtime_error("Dequeuing out of bounds");
    } else {
        T key = array[0];
		for (int i = 0; i < size - 1; ++i) {
			array[i] = array[i + 1];
		}
		array = (T*)realloc(array, (size - 1) * sizeof(T));
        --size;
        return key;
    }
}

/** Display the elements of the Queue from front to back */
template <typename T>
void Queue<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
