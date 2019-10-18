#include<iostream>
#include<vector>
using namespace std;

//Executes insertion sort on vector inputV
void insertionSort(vector<int>& inputV) {  
    int i, key, j;  
    for (i = 1; i < inputV.size(); i++) {  
        key = inputV.at(i);  
        j = i - 1;  

        while (j >= 0 && inputV.at(j) > key) {  
            inputV.at(j + 1) = inputV.at(j);  
            j = j - 1;  
        }  
        inputV.at(j + 1) = key;  
    }  
}

//Prints the vector
void printVector(vector<int> inputV) {
    for (int i = 0; i < inputV.size(); ++i) {
        cout << inputV.at(i) << " ";
    }
    cout << endl;
}

//Validates if the input is an integer
int validateUserIn () { 
    int i;
    if (!(cin >> i)) {
        throw std::runtime_error("error: invalid input");
    }
    return i;
}

int main () {
    try {
        cout << "Please enter the number of elements: " << endl;
        int numElements = validateUserIn();

        cout << "Enter the list to be sorted: " << endl;
        vector<int> inputV(numElements);

        for (int i = 0; i < inputV.size(); ++i) {
            inputV.at(i) = validateUserIn();
        }
        
        insertionSort(inputV);
        cout << "The sorted list is : ";
        printVector(inputV);
    }

    catch(runtime_error& exception) {
        cout << exception.what() << endl;
    }
    return 0;
}
