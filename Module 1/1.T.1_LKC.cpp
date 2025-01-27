// CSC 249
// 1.T.1 - Hello, Data Structures
// Leeanna Kathrine Coleman
// 01/26/25

#include <iostream>
using namespace std;

int main() {
    // Creating the array
    int numbers[5];
    int size = 5;

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    // Display the numbers in the array
    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Find the largest value in the array
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    // Display the largest value
    cout << "The maximum value is: " << max << endl;

    return 0;
}
