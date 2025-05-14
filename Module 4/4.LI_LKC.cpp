// CSC 249
// 4.L.1 - Implementing Linear Search
// Leeanna Kathrine Coleman
// 04/06/25

#include <iostream>
using namespace std;

int LinearSearch(int* numbers, int numbersSize, int key) {
   for (int i = 0; i < numbersSize; i++) {
      if (numbers[i] == key) {
         return i;
      }
   }
   return -1;
}

int main() {
   int numbers[] = { 2, 12, 18, 20, 21, 43, 56, 82 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   cout << "NUMBERS: [" << numbers[0];
   for (int i = 1; i < numbersSize; i++) {
      cout << ", " << numbers[i];
   }
   cout << "]" << endl;
      
   cout << "Enter an integer value: ";
   int key = 0;
   cin >> key;

   int keyIndex = LinearSearch(numbers, numbersSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
}