#include <iostream>

/** Stack class declarations */
template <typename T>
class Stack {
private:
    int size;
    T* array;
public:
    Stack();
    ~Stack();
    T peek();
    void push(T key);
    T pop();
    int getSize();
    void print();
};

/** Construct the Stack with no initial elements */
template <typename T>
Stack<T>::Stack() {
    size = 0;
}

/** Destruct the Stack **/
template <typename T>
Stack<T>::~Stack() {
    delete array;
    array = nullptr;
}

/** Push an element onto the top of the stack */
template <typename T>
void Stack<T>::push(T key) {
    array = (T*)realloc(array, (size + 1) * sizeof(T));
    array[size] = key;
    ++size;
}

/** Pop an element from the top of the stack */
template <typename T>
T Stack<T>::pop() {
    if (size == 0) {
        throw std::runtime_error("Popping out of bounds");
    } else {
        T key = array[size - 1];
        array = (T*)realloc(array, (size - 1) * sizeof(T));
        --size;
        return key;
    }
}

/** Peek the element at the top of the stack */
template <typename T>
T Stack<T>::peek() {
    if (size == 0) {
        throw std::runtime_error("Peeking out of bounds");
    } else {
        return array[size - 1];
    }
}

/** Access the size of the stack */
template <typename T>
int Stack<T>::getSize() {
    return size;
}

/** Display the elements of the stack from top to bottom */
template <typename T>
void Stack<T>::print() {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
