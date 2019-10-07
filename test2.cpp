#include <vector>
#include <iostream>

using namespace std;

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

template <typename T> void mergeSort(unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    if (lastToSort == firstToSort) {
        return;
    }
    
    int mid = (firstToSort + lastToSort) / 2;

    mergeSort(firstToSort, mid, sorted);
    mergeSort(mid + 1, lastToSort, sorted);

    merge(firstToSort, lastToSort, sorted);
}

template <typename T> void mergeSort(const vector<T>& unsorted, unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    for(int i=0;i < unsorted.size(); ++i) {
        sorted.at(i) = unsorted.at(i);
    }
    // Copy unsorted to sorted
    mergeSort(firstToSort, lastToSort, sorted);
}

int main() {
    //vector<int> unsorted { 42, -7, 1001, -16, 2, 0, -17 };
    vector<string> unsorted { "Frits", "Hugo", "Adam", "Catherine", "Joliet", "Xu", "Quirin"};
    vector<string> sorted;
    sorted.resize(unsorted.size());

    mergeSort(unsorted, 0, unsorted.size() - 1, sorted);

    for (int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << " ";

    return 0;
}