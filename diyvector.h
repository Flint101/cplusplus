#ifndef DIYVECTOR_H
#define DIYVECTOR_H

template <typename T> class DiyVector{
    public:
        DiyVector();
        ~DiyVector();

        T& at(unsigned int index) const;
        // item at index
        // throws OutOfRange

        unsigned int size() const;
        // number of items in the vector

        void pushBack(const T& item);
        // append item at the end of vector

        void popBack();
        // remove item at the end of vector
        // throws OutOfRange

        void erase(unsigned int index);
        // remove element at index
        // throws OutOfRange

        void insert(unsigned int index, const T& item);
        // insert item before element at index, with:
        // 0 <= index <= size()
        // throws OutOfRange

        class OutOfRange{};

    private:
        T* array;
        int length;
        int arraySize;

};

template <typename T>
DiyVector<T>::DiyVector() {
    array = nullptr;
    length = 0;
    arraySize = 0;
}

template <typename T>
DiyVector<T>::~DiyVector() {
    if (array != nullptr) {
        delete array;
    }
}

template <typename T>
T& DiyVector<T>::at(unsigned int index) const {
    if (index >= length || index < 0) {
        throw OutOfRange();
    }
    return array[index];
}

template <typename T>
unsigned int DiyVector<T>::size() const {
    return length;
}

template <typename T>
void DiyVector<T>::pushBack(const T& item) {
    if (length < arraySize) {
        array[length] = item;
        length++;
    }
    else {
        T* tmp = new T[length + 1];
        for (int i = 0; i < length; i++) {
            tmp[i] = array[i];
        }
        tmp[length] = item;
        delete array;
        array = tmp;
        length++;
        arraySize++;
    }
}

template <typename T>
void DiyVector<T>::popBack() {
    if (length == 0) {
        throw OutOfRange();
    }
    length--;
}

template <typename T>
void DiyVector<T>::erase(unsigned int index) {
    if (index >= length || index < 0) {
        throw OutOfRange();
    }
    for (int i = index + 1; i < length; ++i) {
        array[i - 1] = array[i];
    }
    length--;
}

template <typename T>
void DiyVector<T>::insert(unsigned int index, const T& item) {
    if (index > length || index < 0) {
        throw OutOfRange();
    }
    if (length < arraySize) {
        for (int i = length; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = item;
        length++;
    }
    else {
        T* temp = new T[length + 1];
        for (int i = 0; i < length; i++) {
            temp[i] = array[i];
        }
        for (int i = length; i > index; i--) {
            temp[i] = temp[i - 1];
        }
        temp[index] = item; 
        delete array;
        array = temp;
        length++;
        arraySize++;  
    }
}

#endif