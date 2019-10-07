#include<iostream>
#include<stack>
#include<string>
#include<fstream>

using namespace std;

void sortStack(stack<int>& s) {
    //if number of elements in stack is smaller than 2, return
    //if not store top element of the stack in variable and remove it from the stack
    //repeat following steps until done:
        //recursively sort the remaining stack
        //if separate stored element is smaller than current top element of the stack, put stored element on top of stack
        //else exchange top element and stored element and continue
}



int main(int argc, char* argv[]) {
    string inFile = "";
    if (argc == 2) {
        inFile = argv[1];
    }
    else {
        cout << "an error occured: no input file name given \n";
        return 1;
    }
   
    ifstream inFS;
    cout << "Opening file " << argv[1] << endl;

    inFS.open(argv[1]);
    if (!inFS.is_open()) {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }
    cout << "Reading the file. " << endl;
    inFS >> filenum1;
    cout << "Closing file." << endl;
    inFS.close();

    cout << "Output value: " 



    /*if (argc < 2) {
        cerr << "Usage: " << argv[0] << " NAME" << endl;
        return 1;
    }

    cout << argv[0] << " says hello, " << argv[1] << "!" << endl;*/
    return 0;
}