#include<iostream>
#include<vector>
using namespace std;

vector<double> multiplication (vector<double> inputVector, vector<vector<double>>matrix) {
    vector<double> result(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.at(i) += (matrix.at(i).at(j) * inputVector.at(j));
        }
    }
    return result;
}

int main() {
    cout << "Please enter the three vector coefficients " << endl;

    vector<double> inputVector(3);              //Initialize 3x1 inputvector
    double v;
    for (int i = 0; i < 3; ++i) {
        cin >> v;
        inputVector.at(i) = v;
    }

//Initialize 3x3 matrix
    double counter = 1.0;                       
    vector<vector<double>> mult;
    for (int i = 0; i < 3; ++i) {
        vector<double> row;
        for (int j = 0; j < 3; ++j) {
            row.push_back(counter);
            counter++;
        }
        mult.push_back(row);        
    }

    vector<double> result(3);

    result = multiplication(inputVector, mult); //Calling the function

    cout << "The result vector is [";
    for (int i = 0; i < 3; ++i) {
        if (i < 2) {
            cout << result.at(i) << ", ";        //Outputting the result
        } else {
            cout << result.at(i);
        }
    }

    cout << "]";

    return 0;
}