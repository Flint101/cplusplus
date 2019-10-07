#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;

//Merging vectors
template <typename T> void merge(unsigned int firstToSort, int mid, unsigned int lastToSort, vector<T>& sorted) {
    vector<T> temp(lastToSort - firstToSort + 1);

    int i = 0, j = firstToSort, k = mid + 1;

    while (j <= mid && k <= lastToSort) {
        if (sorted.at(j) < sorted.at(k)) {
              temp.at(i++) = sorted.at(j++);
        }
        else {
            temp.at(i++) = sorted.at(k++);
            
        }
    }

    while (j <= mid) {
        temp.at(i++) = sorted.at(j++);
    }
    while (k <= lastToSort) {
        temp.at(i++) = sorted.at(k++);
    }
    for (i = 0; i < temp.size(); ++i) {
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