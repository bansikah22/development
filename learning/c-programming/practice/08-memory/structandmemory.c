/*
Structures and Dynamic Memory
You can also use dynamic memory with structures.

This is useful when you don't know how many structs you'll need in advance, or want to save memory by only allocating what's necessary (e.g., in a car dealership program where the number of cars is not fixed).

Allocating Memory for a Struct
You can use the malloc() function to allocate memory for a struct pointer:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct Car {
  char brand[50];
  int year;
};

int main() {
  // Allocate memory for one Car struct
  struct Car *ptr = (struct Car*) malloc(sizeof(struct Car));

  // Check if allocation was successful
  if (ptr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Set values
  strcpy(ptr->brand, "Honda");
  ptr->year = 2022;

  // Print values
  printf("Brand: %s\n", ptr->brand);
  printf("Year: %d\n", ptr->year);

  // Free memory
  free(ptr);

  return 0;
}

/*
Example Explained
malloc() allocates memory for one struct
strcpy() is used to copy a string into the brand field
We use -> to access members through the pointer
free() is used at the end to release the memory
Note: malloc() allocates uninitialized memory. The content will be undefined until you assign values. If you want memory initialized to zero, you can use calloc().
*/
