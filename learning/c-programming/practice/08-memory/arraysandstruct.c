/*
Using Arrays of Structs
You can also allocate memory for multiple structs at once, like an array:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
  char brand[50];
  int year;
};

int main() {
  struct Car *cars = (struct Car*) malloc(3 * sizeof(struct Car));

  if (cars == NULL) {
    printf("Memory allocation failed.\n");
    return 1 // Exit the program with an error code;
  }

  // Fill the data
  strcpy(cars[0].brand, "Ford");
  cars[0].year = 2015;

  strcpy(cars[1].brand, "BMW");
  cars[1].year = 2018;

  strcpy(cars[2].brand, "Volvo");
  cars[2].year = 2023;

  // Print the data
  for (int i = 0; i < 3; i++) {
    printf("%s - %d\n", cars[i].brand, cars[i].year);
  }

  free(cars);
  return 0;
}
