#include <iostream>
#include <cmath>
#include <stdexcept>

int discriminant (int a, int b, int c){
        return (b * b) - 4 * a * c;
}

double quadratic (double a, double b, double c) {
    if (c > 0) {
        return ((-b + sqrt(fabs(c))) / (2 * a));  
    } else {
        return ((- b - sqrt(fabs(c))) / (2 * a));
    }
}

double userIn () { 
    double i;
    if (!(std::cin >> i)) {
        throw std::runtime_error("An error occurred: Malformed user input");
    }
    return i;
}

int main() {
    std::cout << "Please enter the values of a, b, and c:" << std::endl;
    double a, b, c;

    try {
        a = userIn();
        b = userIn();
        c = userIn();

        if (a == 0) {
            throw std::runtime_error("An error occurred: a must not be zero");
        }

        double d = discriminant(a, b, c);
        
        if (d < 0) {
            std::cout << "There is no solution." << std::endl;
        } else if (d == 0) {
            double solution1 = quadratic(a, b, d);
            std::cout << "There is 1 solution." << std::endl << std::endl << "The solution is: " 
                << solution1 << std::endl;
        } else {
            double solution1 = quadratic(a, b, d);
            double solution2 = quadratic(a, b, - d);
            std::cout << "There are 2 solutions." << std::endl << std::endl << "The solutions are: " 
                << solution1 << " and " << solution2 << std::endl;
        }
    }
    catch (std::runtime_error &excpt) {
        std::cout << excpt.what() << std::endl;
    }
    return 0;
}
