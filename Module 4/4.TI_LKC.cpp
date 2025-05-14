// CSC 249
// 4.T.1 - Warmup: Finding Local Maximum
// Leeanna Kathrine Coleman
// 03/30/25

#include <iostream>
#include <string>
using namespace std;

int main2() {
    int a, b, c;

    cout << "Enter three integers seperated by spaces" << endl;
    cin >> a >> b >> c;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;

    if ( (a < b) && (a < c) ) {
        cout << "a is smallest" << endl;
    }
    if ( (b < a) && (b < c) ) {
        cout << "b is smallest" << endl;
    }
    if ( (c < a) && (c < b) ) {
        cout << "c is smallest" << endl;
    }


    return 0;
}

int main() {

    const int SIZE = 6;
    int values [SIZE] = {1, 4, 7, 5, 3, 4};

    int current;
    
    for (int i=0; i < SIZE; i++) {
        cout << "Value[" << i << "]: ";
        cin >> values[i];
    }
    cout << endl;
    
    int current_max = values[0];

    cout << "V=";
    for (int i=0; i < SIZE; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    cout << "Now finding maximum n in V" << endl;
    for (int i=0; i < SIZE; i++) {
        current = values[i];
        cout << current << endl;
        if (current > current_max) {
            current_max = current;
            cout << "\t" << "-> current_max now: " << current_max << endl;
        }
    }
    cout << "Largest value in V is: " << current_max << endl;

    main2();

    return 0;
}