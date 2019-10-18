#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;

//Merging vectors
template <typename T> void merge(unsigned int firstToSort, int mid, unsigned int lastToSort, vector<T>& sorted) {
    vector<T> temp(lastToSort - firstToSort + 1);

    int sortedindex = 0, leftindex = firstToSort, rightindex = mid + 1;

    while (leftindex <= mid && rightindex <= lastToSort) {
        if (sorted.at(leftindex) < sorted.at(rightindex)) {
              temp.at(sortedindex++) = sorted.at(leftindex++);
        }
        else {
            temp.at(sortedindex++) = sorted.at(rightindex++);
        }
    }

    while (leftindex <= mid) {
        temp.at(sortedindex++) = sorted.at(leftindex++);
    }
    while (rightindex <= lastToSort) {
        temp.at(sortedindex++) = sorted.at(rightindex++);
    }
    for (int i = 0; i < temp.size(); ++i) {
        sorted.at(firstToSort + i) = temp.at(i);
    }
}

//Dividing the vectors until size is one
template <typename T> void mergeSort(const vector<T>& unsorted, unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    
    if (firstToSort == lastToSort) {
        sorted.at(firstToSort) = unsorted.at(firstToSort);
        return;
    }
    else {
        int mid = (firstToSort + lastToSort) / 2;

        mergeSort(unsorted, firstToSort, mid, sorted);
        mergeSort(unsorted, mid + 1, lastToSort, sorted);

        merge(firstToSort, mid, lastToSort, sorted);
    }
}

#endif