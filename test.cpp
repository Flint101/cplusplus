#include<iostream>
#include<string>

using namespace std;

int main() {
    string input;
    int i;

    cin >> input;
    cout << "command: " << input << endl;
    cin >> input; 
    i = stoi(input);
    cout << "argument: " << i << endl;





    return 0;
}