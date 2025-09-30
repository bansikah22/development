#include <stdio.h>
/*
Nested Structs
A structure can also contain another structure as a member. This is called a nested structure,
and it is useful when you want to group related data together in layers:
*/

int main() {
#include <stdio.h>

struct Owner {
  char firstName[30];
  char lastName[30];
};

struct Car {
  char brand[30];
  int year;
  struct Owner owner; // Nested structure
};

int main() {
  struct Owner person = {"John", "Doe"};
  struct Car car1 = {"Toyota", 2010, person};

  printf("Car: %s (%d)\n", car1.brand, car1.year);
  printf("Owner: %s %s\n", car1.owner.firstName, car1.owner.lastName);

  return 0;
}
}