#include <stdio.h>

struct Car {
  char brand[30];
  int year;
};

// Function that takes a pointer to a Car struct and updates the year
void updateYear(struct Car *c) {
  c->year = 2025;  // Change the year
}

int main() {
  struct Car myCar = {"Toyota", 2020};

  updateYear(&myCar);  // Pass a pointer so the function can change the year

  printf("Brand: %s\n", myCar.brand);
  printf("Year: %d\n", myCar.year);

  return 0;
}