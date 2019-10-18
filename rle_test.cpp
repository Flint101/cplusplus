#include<iostream>
#include<vector>
using namespace std;

//Checks if alphabetical
bool isAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

//Checks that there are no values other than 'a' to 'z' in data
void checkString (string userInput) {
    for (int i = 0; i < userInput.size(); ++i) {
        if (isAlpha(userInput.at(i)) == false) {
            throw runtime_error("error: invalid input");
        }
    }
}

//Removes all consecutive duplicate values
vector<char> uniqueCharacters(string data) {
    vector<char> unique(1);
    for (int i = 0; i < data.length(); ++i) {
        unique.at(0) = data.at(0);
        if (data.at(i) != unique.back()) {
            unique.push_back(data.at(i));
        }
    }
    return unique;
}

//Counts concecutive Duplicates
vector<char> countDuplicates(string data) {
    vector<char> counterV(0);
    int counter = '0';
    if (data.length() > 0) {
        char currentChar = data.at(0);
        for (int i = 0; i < data.length(); ++i) {
            if (data.at(i) == currentChar) {
                counter++;
            }
            else {
                counterV.push_back(counter);
                counter = '1';
                currentChar = data.at(i);
            }
            if (i + 1 == data.length()) {
                counterV.push_back(counter);
            }
        }
    }
    return counterV;
}
int main() {
    try {
        cout << "Enter the data to be compressed: " << endl;
        string data;
        cin >> data;
        checkString(data);
        vector<char> duplicateCounter = countDuplicates(data);   //FIXME
        vector<char> result = uniqueCharacters(data);
   /*     for (int i = 0; i < duplicateCounter.size(); ++i) {
            cout << "Duplicatescounter: " << duplicateCounter.at(i);
        }
        cout << endl;
        for (int i = 0; i < result.size(); ++i) {
            cout << "Uniquecharacters: " << result.at(i);
        } */
    
        cout << "The compressed data is: ";
        for (int i = 0; i < result.size(); ++i) {
            cout << duplicateCounter.at(i) << result.at(i);
        }   
    }
    catch(runtime_error& exception) {
        cout << exception.what() << endl;
    }
    return 0;
}
