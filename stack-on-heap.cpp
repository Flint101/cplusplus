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

Stack::Stack(const Stack& original) : head(nullptr) {
    Node* tmp = original.head;
    Node* current = new Node();
    
    if (tmp == nullptr) {
        return;
    }
 
    head = new Node();
    head->data = tmp->data;
    head->next = nullptr;
    current = head;
    tmp = tmp->next;

    while (tmp != nullptr) {
        current->next = new Node();
        current = current->next;
        current->data = tmp->data; 
        current->next = nullptr;
        tmp = tmp->next;      
    }
}

Stack::~Stack() {
    while (!this->isEmpty()) {
        this->pop();
    }
}

//Adding node and data to the head of the linked list
void Stack::push(int data){
    Node* node = new Node();        
    node->data = data;          
    node->next = this->head;     
    this->head = node;        
}

//Checks if linked list is empty
bool Stack::isEmpty() const {
    return this->head == nullptr;
}

//Returning first value in first Node
int Stack::top() const {
    if (isEmpty()) {
        throw runtime_error("error: stack is empty");
    } 
    else {
        return this->head->data;        
    }
}

//Returning top value and deleting first node 
int Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("error: stack is empty");
    }
    else {
        int temp = this->head->data; 
        Node* placeholder = new Node();
        placeholder = head;
        head = head->next;
        delete placeholder; 
        return temp;
    }   
}

//Printing all current elements of the 'stack'
void printElements(Stack stack) {
    cout << "[";
    while (!stack.isEmpty()) {
        cout << stack.pop();
        if (!stack.isEmpty()) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    
    Stack* stack = new Stack();
    
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
                cout << stack->pop() << endl;
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
                printElements(*stack);
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
