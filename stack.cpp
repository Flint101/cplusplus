#include<vector>
#include<string>
#include<iostream>
#include<stdexcept>

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

        void Print() {
            cout << "[";
            for (int i = 0; i < elements.size(); ++i)
            {
                cout << elements.at(i);
                if (i < elements.size() - 1) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }

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
    if (elements.size() == 0) {
        throw runtime_error("error: stack is emtpy");
    }
    else {
        int temp = elements.at(0); 
        elements.erase(elements.begin());
        return temp;
    }   
}

int Stack::top() {
    if (elements.size() > 0) {
        return elements.at(0);
    } 
    else {
        throw runtime_error("error: stack is empty");
    }
}

void Stack::push(int input) {
    elements.insert(elements.begin(), input);
    //cout << input << " pushed in to stack \n";
}

bool compareStrings(string s1, string s2) {
    if (s1.compare(s2) < 0) {
        return true;
    }
    return false;
}


int main() {
    
    Stack s;
    string command = "init";
    string arg;

    while (command != "end" && !cin.eof()) {
        try {
            cout << "stack> " << endl;
            cin >> command;

            if (command == "pop") {
                cout << s.pop() << endl;
            }
            
            else if (command == "push") {
                cin >> arg;
               // cout << "Attempting to convert " << arg << " to number" << endl;
                s.push(stoi(arg));
            }

            else if (command == "top") {
                cout << s.top() << endl;
            }

            else if (command == "list") {
                s.Print();
            }
            else {
                cout << "error: invalid command" << endl;
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
