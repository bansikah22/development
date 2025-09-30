#include <stdio.h>
/*
Structures and Pointers
You can use pointers with structs to make your code more efficient, especially when passing structs to functions or changing their values.

To use a pointer to a struct, just add the * symbol, like you would with other data types.

To access its members, you must use the -> operator instead of the dot . syntax:


*/

int main() {
// Define a struct
struct Car {
  char brand[30];
  int year;
};

int main() {
  struct Car car = {"Toyota", 2020};

  // Declare a pointer to the struct
  struct Car *ptr = &car;

  // Access members using the -> operator
  printf("Brand: %s\n", ptr->brand);
  printf("Year: %d\n", ptr->year);

  return 0;
}