#include <iostream>

int main() {
    std::cout << "Enter the expression: " << std::endl;
    char inputCharacter;
    std::cin >> inputCharacter;
    

    while (inputCharacter != 'q') {
        double num1;
        double num2;
        double result;

        std::cin >> num1 >> num2; 

        switch (inputCharacter) {
            case '+':
                result = num1 + num2;
                break;
            
            case '-':
                result = num1 - num2;
                break;

            case '*':
                result = num1 * num2;
                break;

            case '/':
                result = num1 / num2;
    
            default:
                break;
        }
        std::cout << num1 << " " << inputCharacter << " " << num2 << " = " << result << std::endl;
        std::cout << "Enter the expression: " << std::endl;
        std::cin >> inputCharacter;
    }
    return 0;
}