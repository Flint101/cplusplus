#include<iostream>
#include<stack>
#include<fstream>

using namespace std;

//Function to insert he stored value 
void stackInsert(stack<int>& s, int stored) {
    if (s.empty() || stored < s.top()) {
        s.push(stored);
        return;
    }
    else {
        int temp = s.top();
        s.pop();
        stackInsert(s, stored);
        s.push(temp);
    }
}

//Function to sort the stack
void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int stored = s.top();
        s.pop();
        sortStack(s);
        stackInsert(s, stored);
        }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
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
    inFS.open(argv[1]);
    if (!inFS.is_open()) {
        cout << "an error occured: could not open input file " << argv[1] << endl;
        return 1;
    }

    int num;
    stack<int> s;

    while (inFS >> num) {
        s.push(num);
    }
    
    inFS.close();

    sortStack(s);
    printStack(s);

    return 0;
}
