#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int a, b;
    // Read the two input integers
    cin >> a >> b;

    // Iterate through the inclusive interval [a, b]
    for (int n = a; n <= b; n++) {
        if (n >= 1 && n <= 9) {
            // String array for easy mapping of numbers 1-9 to words
            string labels[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            cout << labels[n] << endl;
        } else if (n > 9) {
            // Check parity for numbers greater than 9
            if (n % 2 == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        }
    }

    return 0;
}
