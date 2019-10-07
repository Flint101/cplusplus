#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;

//Merging vectors
template <typename T> void merge(unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted)
{
    int mid = (firstToSort + lastToSort) / 2;
    int i = firstToSort, j = mid + 1, k = firstToSort;
    vector<T> temp;

    while (i <= mid && j <= lastToSort) {
        if (sorted.at(i) < sorted.at(j)) {
            temp.push_back(sorted.at(i++));
        }
        else {
            temp.push_back(sorted.at(j++));
        }
    }
    while (i <= mid) {
        temp.push_back(sorted.at(i++));
    }
    while (j <= lastToSort) {
        temp.push_back(sorted.at(j++));
    }
    for (i = 0; i < temp.size(); ++i) {
        sorted.at(firstToSort + i) = temp.at(i);
    }
}

//Dividing the vectors until size is one
template <typename T> void mergeSort(unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    if (lastToSort == firstToSort) {
        return;
    }
    
    int mid = (firstToSort + lastToSort) / 2;

    mergeSort(firstToSort, mid, sorted);
    mergeSort(mid + 1, lastToSort, sorted);

    merge(firstToSort, lastToSort, sorted);
}

//Copying from unsorted to sorted
template <typename T> void mergeSort(const vector<T>& unsorted, unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    for(int i=0;i < unsorted.size(); ++i) {
        sorted.at(i) = unsorted.at(i);
    }
    mergeSort(firstToSort, lastToSort, sorted);
}

#endif