#include <stdio.h>

// Exercise 3-1: Write a program to call a function that calls another function.
/*
As long as you declare functions first, it is also possible to use functions to call other functions:
*/

// Declare two functions, myFunction and myOtherFunction
void myFunction();
void myOtherFunction();

int main() {
  myFunction(); // call myFunction (from main)
  return 0;
}

// Define myFunction
void myFunction() {
  printf("Some text in myFunction\n");
  myOtherFunction(); // call myOtherFunction (from myFunction)
}

// Define myOtherFunction
void myOtherFunction() {
  printf("Hey! Some text in myOtherFunction\n");
}