#include <stdio.h>

// Global variable x
int x = 5;

void myFunction() {
  // Local variable with the same name as the global variable (x)
  int x = 22;
  printf("From Local variable: %d\n", x); // Refers to the local variable x
}

int main() {
  myFunction();

  printf("From Global variable :%d\n", x); // Refers to the global variable x
  return 0;
}