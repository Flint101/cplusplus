#include <sstream>
#include <string>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<exception>
#include<limits>

using namespace std;


int main(int argc, char* argv[]) {
        string inFile = "";
        if (argc == 2) {
            inFile = argv[1];
        }
        else {
            throw runtime_error("an error occurred: no input file name given");
        }
    
        ifstream inputFile;
        inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            string error = "an error occurred: could not open input file ";
            error.append(argv[1]);
            throw runtime_error(error);
            
        }



    string line;
    getline(inputFile, line);
    istringstream iss(line);
    int a, b;
    if (!(iss >> a >> b)) { cout << "error" << endl; } // error

    cout << a << " " << b << endl;
}