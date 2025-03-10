// CSC 249
// 2.H.1 - Recursion
// Leeanna Kathrine Coleman
// 03/02/25

#include <iostream>
using namespace std;

//Binary Iteratively

int IterativeBinarySearch(int* numbers, int numbersSize, int key) {
   // Variables to hold the low and high indices of the area being searched. 
   // Starts with entire range.
   int low = 0;
   int high = numbersSize - 1;
   
   // Loop until "low" passes "high"
   while (high >= low) {
      // Calculate the middle index
      int mid = (high + low) / 2;

      // Cut the range to either the left or right half,
      // unless numbers[mid] is the key
      if (numbers[mid] < key) {
         low = mid + 1;
      }
      else if (numbers[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}

//Binary Recursively
int RecursiveBinarySearch(int* numbers, int low, int high, int key) {
    if (low > high)
       return -1;
 
    int mid = (low + high) / 2;
    if (numbers[mid] < key) {
       return RecursiveBinarySearch(numbers, mid + 1, high, key);
    }
    else if (numbers[mid] > key) {
       return RecursiveBinarySearch(numbers, low, mid - 1, key);
    }
    return mid;
 }

 //Fibonacci Recursive
 int RecursiveFibonacciNumber(int termIndex) {
    if (termIndex == 0)
       return 0;
    else if (termIndex == 1)
       return 1;
    else
       return RecursiveFibonacciNumber(termIndex - 1) + RecursiveFibonacciNumber(termIndex - 2);
 }

 //Fibonacci Iteratively
 int IterativeFibonacciNumber(int termIndex) {
    if (termIndex == 0) return 0;
    if (termIndex == 1) return 1;

    int previous = 0, current = 1;
    for (int i = 2; i <= termIndex; i++) {
        int temp = current;
        current += previous;
        previous = temp;
    }
    return current;
 }

 int main() {
    int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    cout << "NUMBERS: [" << numbers[0];
    for (int i = 1; i < numbersSize; i++) {
       cout << ", " << numbers[i];
    }
    cout << "]" << endl;
       
    // Binary Search
    cout << "Enter an integer value: ";
    int key;
    cin >> key;
       
    int iterativeIndex = IterativeBinarySearch(numbers, numbersSize, key);
    if (iterativeIndex == -1) {
       cout << key << " was not found. (Iterative Search)" << endl;
    }
    else {
       cout << "Found " << key << " at index ";
       cout << iterativeIndex << ". (Iterative Search)" << endl;
    }

    int recursiveIndex = RecursiveBinarySearch(numbers, 0, numbersSize - 1, key);
    if (recursiveIndex == -1) {
        cout << key << "was not found. (Recursive Search)" << endl;
    }
    else {
        cout << "Found " << key << " at index " << recursiveIndex << " (Recursive Search)." << endl;
    }

    //FIbonacci Number Search
    cout << "Enter a number to calculate the Fibonacci of:" << endl;
    int fibNumber;
    cin >> fibNumber;

    cout << "Iterative Fibonacci of " << fibNumber << " is: " << IterativeFibonacciNumber(fibNumber) << endl;
    cout << "Recursive Fibonacci of " << fibNumber << " is: " << RecursiveFibonacciNumber(fibNumber) << endl;

    return 0;
 }