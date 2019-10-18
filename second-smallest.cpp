#include<iostream>
#include<vector>
using namespace std;

int secondSmall (vector<int> v) {
    int min ,second;
    if (v.size() < 2) {
        throw runtime_error("error: no second smallest");
    }
    if (v.at(0) < v.at(1)) {
        min = v.at(0);
        second = v.at(1);        
    } else {
        min = v.at(1);
        second = v.at(0);
    }  
    for (int i = 2; i < v.size(); ++i) {
        if (v.at(i) < min) {
            second = min;
            min = v.at(i);
        } else if (v.at(i) > min && v.at(i) <= second || min == second) {
                second = v.at(i);
            }
        }
    if (second == min) {
        throw runtime_error("error: no second smallest");
    } 
    return second;
}

int main() {
    cout << "Enter the numbers in random order: (close by entering q)" << endl;
    int numInput;
    vector<int> inputVector;

    while (cin >> numInput) {
        inputVector.push_back(numInput);
    }
    try {
        int second = secondSmall(inputVector);
        cout << "The second smallest number is: " << second;
    }
    catch (runtime_error &excpt) {
        cout << excpt.what() << std::endl;  
    } 
    return 0;
}
