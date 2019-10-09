#include<vector>

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


