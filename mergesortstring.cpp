#include <iostream>
#include <vector>
#include "mergesort.h"

int main(){
    std::vector<std::string> unsorted { "Frits", "Hugo", "Adam", "Catherine", "Joliet", "Xu", "Quirin"};
    std::vector<std::string> sorted;
    sorted.resize(unsorted.size());

    mergeSort(unsorted, 0, unsorted.size()-1, sorted);

    for (unsigned int i=0; i < sorted.size(); i++){
        std::cout << sorted.at(i) << ' ';
    }
    std::cout << std::endl;

    return 0;
}