#include <iostream>
#include <cmath>

int main() {
    std::cout << "Enter the first number of the sequence: " << std::endl;
    int inputNumber;
    std::cin >> inputNumber;

    int counter = 0;
    while (counter < 3) {
        std::cout << inputNumber << " ";
        if (inputNumber == 1) {
            counter++;
        }
        if (inputNumber % 2 == 0) {
            inputNumber /= 2;
        } else {
            inputNumber = (3 * inputNumber) + 1;
        }
    }
    std::cout << "...";
    return 0;
}
