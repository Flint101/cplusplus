#include <iostream>
using namespace std;

int main() {
    string first_name;
    string last_name;
    int age;
    double height;

    cout << "I am making a change in this ";

    cout << "Enter your first name:" << endl;
    cin >> first_name;

    cout << "Enter your last name:" << endl;
    cin >> last_name;

    cout << first_name << ", enter your age:" << endl;
    cin >> age;

    cout << first_name << ", enter your height in meters:" << endl;
    cin >> height;

    cout << endl << "Hello " << first_name << "," << endl << endl 
            << "Welcome to Computer Programming. You entered the following information:" 
            << endl << "Full name: " << first_name << " " << last_name << endl << "Age: " 
            << age << endl << "Height: " << height << endl << endl 
            << "We hope you will enjoy the course!" << endl;

    return 0;
}
