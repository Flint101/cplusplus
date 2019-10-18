#include<iostream>
using namespace std;

//Funtion to check size to be 6
void checkSize (string userInput) {
    if (userInput.size() != 6) {
        string errorlength = to_string(userInput.size());
        string errormessage = "error: size incorrect (is " + errorlength + ", should be 6)";
        throw runtime_error(errormessage);
    }
}

//Checks if part of the string is alphabetical
void checkString (string userInput) {
    for (int i = 0; i < 3; ++i) {
        if ((userInput.at(i) < 'A') || (userInput.at(i) > 'Z' && userInput.at(i) < 'a') || (userInput.at(i) > 'z')) {
            string errorposition = to_string(i + 1);
            string errormessage = "error: letter expected at position " + errorposition;
            throw runtime_error(errormessage);
        }
    }
}

//Checks if part of the string is an integer
void checkIntegers (string userInput) {
    for (int i = 3; i < 6; ++i) {
        if (!(userInput.at(i) >= '0' && userInput.at(i) <= '9')) {
            string errorposition = to_string(i + 1);
            string errormessage = "error: digit expected at position " + errorposition;
            throw runtime_error(errormessage);
        }
    }
}


int main() {
    cout << "Please enter a vunet id: " << endl;
    string userInput;
    cin >> userInput;

    try {
        checkSize(userInput);
        checkString(userInput);
        checkIntegers(userInput);

        cout << "The vunet id " << userInput << " is valid";
    }

    catch(runtime_error &exception) {
        cout << exception.what() << endl;
    }

    return 0;
}
