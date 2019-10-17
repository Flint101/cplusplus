#include<vector>
#include<string>
#include<iostream>
#include<stdexcept>
#include<limits>

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
};


Stack::Stack() : head(nullptr) {}

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
 
}

/*void Stack::print(){
    Node* head = this->head;
    cout << "[";
    while(head) {
        cout << head->data;
        if (!isEmpty()) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}*/

bool Stack::isEmpty() const {
    return this->head == nullptr;
}

/*
int Stack::pop() {
    if (elements.size() == 0) {
        throw runtime_error("error: stack is emtpy");
    }
    else {
        int temp = elements.at(0); 
        elements.erase(elements.begin());
        return temp;
    }   
}*/

int Stack::top() const {
    if (isEmpty()) {
        throw runtime_error("error: stack is empty");
    } 
    else {
        return this->head->data;        
    }
}


int main() {
    
    Stack* stack = new Stack();

    const string POP = "pop";
    const string TOP = "top";
    const string LIST = "list";
    const string PUSH = "push";
    const string END = "end";

    string arg;

    while (true) {
        string command;
        cout << "stack> " << endl;
        try {
            cin >> command;

            if (cin.eof() || command == END) {
                break;
            }

            else if (command == POP) {
                //cout << s.pop() << endl;
            }
            
            else if (command == PUSH) {
                string arg;
                cin >> arg;
                stack->push(stoi(arg));
                }

            else if (command == TOP) {
                cout << stack->top() << endl;
            }

            else if (command == LIST) {
                //stack->print();
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
   
    delete stack;
    return 0;
}
