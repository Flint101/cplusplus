#include <iostream>
#include <vector>
#include "mergesort.h"

int main(){
    std::vector<double> unsorted { 42.0, -7, 1.001e3, -16.5, 2.5, 0.0, -17.8 };
    std::vector<double> sorted;
    sorted.resize(unsorted.size());

    mergeSort(unsorted, 0, unsorted.size()-1, sorted);

    for (unsigned int i=0; i < sorted.size(); i++){
        std::cout << sorted.at(i) << ' ';
    }
    std::cout << std::endl;

    return 0;
}