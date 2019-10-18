#include <iostream>
#include <vector>
using namespace std;
int i;

int main() {
    std::cout << "Summing up 1 to n, please enter n: " << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Which partial sum (1+...+x) would you like to know? Please enter x<=n : " << std::endl;
    int x;
    std::cin >> x;

    std::vector<int> vectorSums;

    for (i = 0; i < n; i++) {
        vectorSums.push_back(i + 1);
    }

    int sum = 0;
    for (i = 0; i < x; i++) {
        std::cout << vectorSums.at(i);
        sum = sum + vectorSums.at(i);
        if (i < x -1) {
            cout << "+";
        }
    }
    
    cout << " = " << sum << endl << "The entire sequence of partial sums up to " << n << " is: ";

    int partialSum = 0;
    for (i = 0; i < n; i++) {
        partialSum += vectorSums.at(i);
        cout << partialSum << " ";       
    }
    return 0;
}
