#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>

using namespace std;

class Stack {
    public:
        bool isEmpty();
        // returns true if stack has no elements stored

        int top();
        // returns element from top of the stack
        // throws runtime_error("stack is empty")

        int pop();
        // returns element from top of the stack and removes it
        // throws runtime_error("stack is empty")

        void push(int);
        // puts a new element on top of the stack

    private:
        vector<int> elements;
};

bool Stack::isEmpty() {
    if (elements.size() == 0) {
        return true;
    }
    return false;
}

int Stack::pop() {
    int temp = elements.back(); 
    elements.pop_back();
    if (elements.size() == 0) {
        throw runtime_error("stack is emtpy");
        return 0;
    }
    return temp;
}

int Stack::top() {
    if (elements.size() > 0) {
        return elements.back();
    } 
    else {
        throw runtime_error("stack is empty");
    }
}

void Stack::push(int input) {
    elements.push_back(input);
    cout << input << " pushed in to stack \n";
}




//Asks for user input until input is "end"
string getUserInput() {
    string in = "init";
    while (in != "end") {
        cout << "stack> ";
        cin >> in;
        if (in == "end") {
            break;
        }
    }
    return in;
}

int main() {
    //getUserInput();
    try {
        Stack s;
        s.push(10);
        s.push(35);
        cout << s.elements
        s.isEmpty();
        s.top();
        s.pop();
        s.pop();
        s.pop();
        
    }
   
    catch (runtime_error& exception) {
        cout << exception.what() << endl;
    }

    return 0;
}
