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

//Removes all consecutive duplicate values. Has to return empty {} if no input.
vector<char> uniqueCharacters(string data) {
    if (data.length() > 0) {
        vector<char> unique(1);
        for (int i = 0; i < data.length(); ++i) {
            unique.at(0) = data.at(0);
            if (data.at(i) != unique.back()) {
                unique.push_back(data.at(i));
            }
        }
        return unique;
    }
    else {
        return {};
    }
}

//Counts concecutive Duplicates
vector<int> duplicateCounter(string data) { 
    int n = data.length(); 
    vector<int> countV;
    for (int i = 0; i < n; i++) { 
        int count = 1; 
        while (i < n - 1 && data.at(i) == data.at(i + 1)) { 
            count++; 
            i++; 
        } 
        countV.push_back(count); 
    }
    return countV; 
} 

int main() {
    try {
        cout << "Enter the data to be compressed: " << endl;
        string data;
        cin >> data;
        checkString(data);
       
        vector<char> characters = uniqueCharacters(data);
        vector<int> counter = duplicateCounter(data);
                
        cout << "The compressed data is: ";
        for (int i = 0; i < characters.size(); ++i) {
            cout << counter.at(i) << characters.at(i);
        }  
    }
    catch(runtime_error& exception) {
        cout << exception.what() << endl;
    }
    return 0;
}
