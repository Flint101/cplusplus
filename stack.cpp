#include<vector>
#include<string>
#include<iostream>
#include<stdexcept>
#include<limits>
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
//Checks if vector is empty
bool Stack::isEmpty() {
    return elements.size() == 0;
}
//Returning top value and removing it
int Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("error: stack is empty");
    }
 
    int temp = elements.at(0); 
    elements.erase(elements.begin());
    return temp;
}
//Printing all current elements of the 'stack'
void printElements(Stack s) {
    cout << "[";
    while (!s.isEmpty()) {
        cout << s.pop();
        if (!s.isEmpty()) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
//Returning top value 
int Stack::top() {
    if (isEmpty()) {
        throw runtime_error("error: stack is empty");
    }
    return elements.at(0);
}
//Pushing elements into the left side of the vector
void Stack::push(int input) {
    elements.insert(elements.begin(), input);
}
int main() {
    Stack s;
    
    const string POP = "pop";
    const string TOP = "top";
    const string LIST = "list";
    const string PUSH = "push";
    const string END = "end";
    
    
    while (true) {
        string command;
        cout << "stack> " << endl;
        try {
            cin >> command;
            if (cin.eof() || command == END) {
                break;
            }
            else if (command == POP) {
                cout << s.pop() << endl;
            }
            else if (command == PUSH) {
                string arg;
                cin >> arg;
                s.push(stoi(arg));
            }
            else if (command == TOP) {
                cout << s.top() << endl;
            }
            else if (command == LIST) {
                printElements(s);
            }
            else {
                cout << "error: invalid command" << endl;
            }
            if (cin.eof()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        catch (runtime_error& exception) {
            cout << exception.what() << endl;
        }
        catch (invalid_argument& exception) {
            cout << "error: not a number" << endl;
        }
    }
    return 0;
}