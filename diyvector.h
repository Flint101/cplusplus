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
        T* ptr;
        int length;
        int arrSize;

};

template <typename T>
DiyVector<T>::DiyVector() {

}

template <typename T>
DiyVector<T>::~DiyVector() {

}

template <typename T>
T& DiyVector<T>::at(unsigned int index) const {

}

template <typename T>
unsigned int DiyVector<T>::size() const {
}

template <typename T>
void DiyVector<T>::pushBack(const T& item) {

}

template <typename T>
void DiyVector<T>::popBack() {

}

template <typename T>
void DiyVector<T>::erase(unsigned int index) {

}

template <typename T>
void DiyVector<T>::insert(unsigned int index, const T& item) {

}



#endif