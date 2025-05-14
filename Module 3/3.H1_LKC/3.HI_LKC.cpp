// CSC 249
// 3.HI - Stacks and Queues in Practice
// Leeanna Kathrine Coleman
// 03/23/25

#include <iostream>
#include "./ArrayQueue.hpp"
#include "./Stack.hpp"
#include "./Queue.hpp"
using namespace std;

// Function to test the custom ArrayQueue (bounded and unbounded)
void TestArrayQueues() {
   // Make two queues, one bounded to 4 items and the other bounded
   ArrayQueue boundedQueue(4);
   ArrayQueue unboundedQueue;

   // Enqueue 8 items in each
   cout << "Enqueueing values 1 through 8 to each queue" << endl;
   for (int i = 1; i <= 8; i++) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }

   // Dequeue two items from each queue
   cout << "Dequeuing twice" << endl;
   for (int i = 0; i < 2; i++) {
      cout << "  Dequeued " << boundedQueue.Dequeue();
      cout << " from bounded queue" << endl;
      cout << "  Dequeued " << unboundedQueue.Dequeue();
      cout << " from unbounded queue" << endl;
   }

   // Enqueue 4 more items
   cout << "Enqueueing values: 10, 20, 30 and 40" << endl;
   for (int i = 10; i <= 40; i += 10) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }

   // Display contents of each queue
   cout << "Bounded queue (maxLength=";
   cout << boundedQueue.GetMaxLength();
   cout << ") contents:" << endl;
   while (boundedQueue.GetLength() > 0) {
      cout << "  " << boundedQueue.Dequeue() << endl;
   }

   cout << "Unbounded queue contents:" << endl;
   while (unboundedQueue.GetLength() > 0) {
      cout << "  " << unboundedQueue.Dequeue() << endl;
   }

   cout << endl;
}

// Function to test the Stack operations
void TestStack() {
   int numbers[] = { 12, 23, 18, 20, 26, 43, 54, 98, 10 };

   // Initialize a new Stack and add numbers
   Stack numStack;
   for (int number : numbers) {
      numStack.Push(number);
   }

   // Output stack
   cout << "Stack after initial pushes:   ";
   numStack.Print(cout);

   // Pop and print, push 99 and print, pop and print again
   numStack.Pop();
   cout << "Stack after first pop:        ";
   numStack.Print(cout);
   numStack.Push(99);
   cout << "Stack after pushing 99:       ";
   numStack.Print(cout);
   numStack.Pop();
   cout << "Stack after second pop:       ";
   numStack.Print(cout);

   // Print a blank line before the Queue demo
   cout << endl;
}

// Function to test the Queue operations
void TestQueue() {
   int numbers[] = { 12, 23, 18, 20, 26, 43, 54, 98, 10 };

   // Initialize a new Queue and add numbers
   Queue numQueue;
   for (int number : numbers) {
      numQueue.Enqueue(number);
   }

   // Output queue
   cout << "Queue after initial enqueues: ";
   numQueue.Print(cout);

   // Dequeue 83 and print
   numQueue.Dequeue();
   cout << "Queue after first dequeue:    ";
   numQueue.Print(cout);

   // Enqueue 99 and print
   numQueue.Enqueue(99);
   cout << "Queue after enqueueing 99:    ";
   numQueue.Print(cout);

   // Dequeue 4 and print
   numQueue.Dequeue();
   cout << "Queue after second dequeue:   ";
   numQueue.Print(cout);
}

// Main function to run all demos
int main() {
   cout << "-- ArrayQueue --" << endl;
   TestArrayQueues();

   cout << "-- Stack --" << endl;
   TestStack();

   cout << "-- Queue --" << endl;
   TestQueue();

   return 0;
}