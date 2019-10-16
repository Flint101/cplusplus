#include<vector>
#include<string>
#include<iostream>
#include<stdexcept>

using namespace std;

class Stack {
    private: 
        class Node {
            public:
                int data;
                Node* next;                
    
        };
        Node* head;
    public:
        Stack();
        Stack(const Stack& original);
        ~Stack();
        bool isEmpty() const;
        int top() const;
        int pop();
        void push(int);
        void print();
};


Stack::Stack() {
    this->head = nullptr;
}

Stack::Stack(const Stack& original) {

}

Stack::~Stack() {
    cout << "Destructor called";
}

void Stack::push(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    //this->length++;
}



/*
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



bool compareStrings(string s1, string s2) {
    if (s1.compare(s2) < 0) {
        return true;
    }
    return false;
}
*/

int main() {
    
    Stack* s = new Stack();
    delete s;

    /*Stack s;
    string command = "init";
    string arg;*/



    /*while (command != "end" && !cin.eof()) {
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
    }*/
   

    return 0;
}
