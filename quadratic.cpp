#include <iostream>
#include <cmath>

int discriminant (int a, int b, int c){
        return ((b * b) - 4 * a * c);
}

double quadratic (double a, double b, double c) {
    if (c > 0) {
        return ((-b + sqrt(fabs(c))) / (2 * a));  
    } else {
        return ((- b - sqrt(fabs(c))) / (2 * a));
    }
}

int main() {
    std::cout << "Please enter the values of a, b, and c:" << std::endl;
    double a, b, c;
    std::cin >> a >> b >> c;
    double d = discriminant(a, b, c);
    double solution1 = quadratic(a, b, d);
    double solution2 = quadratic(a, b, - d);
    
    if (d < 0) {
        std::cout << "There is no solution." << std::endl;
    } else if (d == 0) {
        std::cout << "There is 1 solution." << std::endl << std::endl << "The solution is: " 
            << solution1 << std::endl;
    } else {
        std::cout << "There are 2 solutions." << std::endl << std::endl << "The solutions are: " 
            << solution1 << " and " << solution2 << std::endl;
    }
    return 0;
}