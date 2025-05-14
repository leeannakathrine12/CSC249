// CSC 249
// 3.LI - The Stack
// Leeanna Kathrine Coleman
// 03/16/25

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include "./StackADT.hpp"

class ArrayStack : public StackADT {
private:
   int allocationSize;
   int* array;
   int length;
   int maxLength;
   
   void Resize() {
      int newSize = allocationSize * 2;
      int* newArray = new int[newSize];
      for (int i = 0; i < length; i++) {
         newArray[i] = array[i];
      }
        
      delete[] array;
      array = newArray;
      allocationSize = newSize;
   }

public:
   ArrayStack(int optionalMaxLength = -1) {
      allocationSize = 1;
      array = new int[allocationSize];
      length = 0;
      maxLength = optionalMaxLength;
   }
    
   virtual ~ArrayStack() {
      delete[] array;
   }
   
   virtual int GetLength() const override {
      return length;
   }
    
   virtual int GetMaxLength() const {
      return maxLength;
   }
   
   virtual bool IsEmpty() const override {
      return 0 == length;
   }
   
   virtual int Peek() const override {
      return array[length - 1];
   }
    
   virtual int Pop() override {
      length--;
      return array[length];
   }
   
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const override {
      if (length > 0) {
         printStream << array[length - 1];
      }
      
      for (int i = length - 2; i >= 0; i--) {
         printStream << separator << array[i];
      }
   }
   
   virtual bool Push(int item) override {
      if (length == maxLength) {
         return false;
      }
      
      if (length == allocationSize) {
         Resize();
      }
        
      array[length] = item;
      length++;
      return true;
   }
};

#endif