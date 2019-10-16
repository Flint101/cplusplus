#include <sstream>
#include <string>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<exception>

using namespace std;


void handleFile(int argc, char *argv) {
    //Handling file
    string inFile = "";
    if (argc == 2) {
        inFile = argv;
    }
    else {
        throw runtime_error("an error occurred: no input file name given");
    }

    ifstream inputFile;
    inputFile.open(inFile);
    if (!inputFile.is_open()) {
        string error = "an error occurred: could not open input file ";
        error.append(inFile);
        throw runtime_error(error); 
    }
}


int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << " ";
    }
    cout << endl;




    handleFile(argc, argv[1]);
}