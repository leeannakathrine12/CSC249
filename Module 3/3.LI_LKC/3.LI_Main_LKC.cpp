// CSC 249
// 3.LI - The Stack
// Leeanna Kathrine Coleman
// 03/16/25

#include <iostream>
#include "./ArrayStack.hpp"
using namespace std;

int main(int argc, char* argv[]) {
   ArrayStack boundedStack(4);
   ArrayStack unboundedStack;
    
   cout << "Pushing values 1 through 8 to each stack" << endl;
   for (int i = 1; i <= 8; i++) {
      boundedStack.Push(i);
      unboundedStack.Push(i);
   }
   
   cout << "Popping twice" << endl;
   for (int i = 0; i < 2; i++) {
      boundedStack.Pop();
      unboundedStack.Pop();
   }

   cout << "Pushing values to each stack: 10, 20, 30 and 40" << endl;
   for (int i = 10; i <= 40; i += 10) {
      boundedStack.Push(i);
      unboundedStack.Push(i);
   }
    
   cout << "Bounded stack (maxLength=" << boundedStack.GetMaxLength();
   cout << ") contents:" << endl;
   while (boundedStack.GetLength() > 0) {
      cout << "  " << boundedStack.Pop() << endl;
   }
   cout << "Unbounded stack contents:" << endl;
   while (unboundedStack.GetLength() > 0) {
      cout << "  " << unboundedStack.Pop() << endl;
   }
   
   return 0;
}