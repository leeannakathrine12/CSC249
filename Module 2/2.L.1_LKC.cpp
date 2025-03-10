// CSC 249
// 2.L.1 - Linear Search of Array
// Leeanna Kathrine Coleman
// 02/23/25

#include <iostream>
using namespace std;

int LinearSearch(double* numbers, int numbersSize, double key) {
   for (int i = 0; i < numbersSize; i++) {
      if (numbers[i] == key) {
         return i;
      }
   }
   return -1; // not found
}

int main() {
   double numbers[] = { 2.1, 4.2, 7.3, 10.4, 11.5, 32.6, 45.7, 87.8};
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   cout << "NUMBERS: [" << numbers[0];
   for (int i = 1; i < numbersSize; i++) {
      cout << ", " << numbers[i];
   }
   cout << "]" << endl;
      
   // Prompt for an double to search for
   cout << "Enter a number with a decimal/floating-point value: ";
   double key = 0;
   cin >> key;

   double keyIndex = LinearSearch(numbers, numbersSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
}
