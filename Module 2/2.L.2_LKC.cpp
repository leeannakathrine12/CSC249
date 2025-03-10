// CSC 249
// 2.L.2 - Binary Search of an Array
// Leeanna Kathrine Coleman
// 02/23/25

#include <iostream>
using namespace std;

int BinarySearch(string* words, int wordSize, string key) {
   // Variables to hold the low and high indices of the area being searched. 
   // Starts with entire range.
   int low = 0;
   int high = wordSize - 1;
   
   // Loop until "low" passes "high"
   while (high >= low) {
      // Calculate the middle index
      int mid = (high + low) / 2;

      // Cut the range to either the left or right half,
      // unless numbers[mid] is the key
      if (words[mid] < key) {
         low = mid + 1;
      }
      else if (words[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}

int main() {
   string words[] = { "cow", "pig", "goat", "horse", "chicken", "dog", "cat", "duck" };
   int wordSize = sizeof(words) / sizeof(words[0]);
   cout << "WORDS: [" << words[0];
   for (int i = 1; i < wordSize; i++) {
      cout << ", " << words[i];
   }
   cout << "]" << endl;
      
   // Prompt for an integer to search for
   cout << "Enter an animal to search: ";
   string key;
   cin >> key;
      
   int keyIndex = BinarySearch(words, wordSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
}