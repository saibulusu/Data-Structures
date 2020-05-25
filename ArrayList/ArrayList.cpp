#include <exception>
#include <iostream>

/** template for the ArrayList class **/
template <typename T>
class ArrayList {
private:
    int size;
    T* array;
public:
    ArrayList();
    ~ArrayList();
    T get(int index);
    void insert(T key);
    void insert(int index, T key);
    T alter(int index, T key);
    T remove(int index);
    int getSize();
    void print();
};

/** Construct the ArrayList with no initial information */
template <typename T>
ArrayList<T>::ArrayList() {
    size = 0;
}

/** Destruct the ArrayList */
template <typename T>
ArrayList<T>::~ArrayList() {
    delete array;
    array = nullptr;
}

/** Get a specific value by index from the ArrayList **/
template <typename T>
T ArrayList<T>::get(int index) {
    if (index < 0 || index >= size) {
        throw "Accessing out of bounds";
    } else {
        return array[index];
    }
}

/** Insert a value into the list at the end **/
template <typename T>
void ArrayList<T>::insert(T key) {
    array = (T*)realloc(array, sizeof(T) * (size + 1));
    array[size] = key;
    ++size;
}

/** Insert a value into the list at a specific index **/
template <typename T>
void ArrayList<T>::insert(int index, T key) {
    if (index < 0 || index > size) {
        throw "Inserting out of bounds";
    } else {
        if (index == size) {
            insert(key);
        } else {
            array = (T*)realloc(array, sizeof(T) * (size + 1));
            for (int i = size; i > index; --i) {
                array[i] = array[i - 1];
            }
            array[index] = key;
            ++size;
        }
    }
}

/** Edit a value of the ArrayList at a specific index **/
template <typename T>
T ArrayList<T>::alter(int index, T key) {
    if (index < 0 || index >= size) {
        throw "Altering out of bounds";
    } else {
        T oldKey = remove(index);
        insert(index, key);
        return oldKey;
    }
}

/** Access the size of the ArrayList **/
template <typename T>
int ArrayList<T>::getSize() {
    return size;
}

/** Remove a value from the list at a specific index **/
template <typename T>
T ArrayList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw "Removing out of bounds";
    } else {
        T oldKey = array[index];
        for (int i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        array = (T*)realloc(array, sizeof(T) * (size - 1));
        --size;
        return oldKey;
    }
}

/** Print the contents of the ArrayList **/
template <typename T>
void ArrayList<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}    