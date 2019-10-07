#include <iostream>
#include <cmath>

int main() {
    std::cout << "Please enter the length and width of the rectangle:" << std::endl;
    int length;
    int width;
    std::cin >> length >> width;

    int perimeter = (2 * length) + (2 * width);
    int area = length * width;
    double diagonal = sqrt(pow(length,2) + pow(width,2));

    std::cout << "The perimeter: " << perimeter << " area: " << area << ", and diagonal" << diagonal << std::endl;

    return 0;
}
