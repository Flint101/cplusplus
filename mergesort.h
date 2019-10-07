#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;

//Merging vectors
template <typename T> void merge(const vector<T>& unsorted, unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    cout << "Calling merge " << endl;

    for (int i = 0; i < sorted.size(); ++i) {
        cout << sorted.at(i) << " ";
    }
    cout << endl;
    int mid = (firstToSort + lastToSort) / 2;
    cout << "mid merge = " << mid << " firstToSort: " << firstToSort << endl;
    int leftindex = firstToSort, rightindex = mid + 1, sortedindex = firstToSort;
    //vector<T> temp;

    while (leftindex <= mid && rightindex <= lastToSort) {
        cout << "leftindex: " << leftindex << endl;
        if (unsorted.at(leftindex) < unsorted.at(rightindex)) {
            cout << "if " << unsorted.at(leftindex) << " < " << unsorted.at(rightindex) << " firstToSort " << firstToSort << endl;
            sorted.at(sortedindex++) = unsorted.at(leftindex++);
        }
        else {
            cout << "Else statement: sorted.at(sortedindex++) " << sortedindex << " = unsorted.at(rightindex) " << unsorted.at(rightindex) << endl;
            sorted.at(sortedindex++) = unsorted.at(rightindex++);
            
        }
    }

    while (leftindex <= mid) {
        //cout << "while leftindex <= mid CALLED" << endl;
        cout << "sorted.at(sortedindex): " << sortedindex << " = unsorted.at(leftindex) " << unsorted.at(leftindex) << endl;
        sorted.at(sortedindex++) = unsorted.at(leftindex++);
    }
    while (rightindex <= lastToSort) {
        //cout << "while rightindex <= lastToSort CALLED" << endl;
        cout << "sorted.at( " << sortedindex << " ) = " << unsorted.at(rightindex) << endl;
        sorted.at(sortedindex++) = unsorted.at(rightindex++);
    }
   /* for (i = 0; i < sorted.size(); ++i) {
        sorted.at(firstToSort + i) = temp.at(i);
    }*/
}

//Dividing the vectors until size is one
template <typename T> void mergeSort(const vector<T>& unsorted, unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    cout << "Calling mergeSort with firstToSort: " << firstToSort << " and lastToSort: " << lastToSort << endl;
    
    if (lastToSort == firstToSort) {
        return;
    }
    
    int mid = (firstToSort + lastToSort) / 2;
    cout << "Mid mergeSort = " << mid << endl;

    mergeSort(unsorted, firstToSort, mid, sorted);
    mergeSort(unsorted, mid + 1, lastToSort, sorted);

    merge(unsorted, firstToSort, lastToSort, sorted);
}

//Copying from unsorted to sorted
/*template <typename T> void mergeSort(const vector<T>& unsorted, unsigned int firstToSort, unsigned int lastToSort, vector<T>& sorted) {
    for (int i = 0;i < unsorted.size(); ++i) {
        sorted.at(i) = unsorted.at(i);
    }
    mergeSort(firstToSort, lastToSort, sorted);
}*/

#endif