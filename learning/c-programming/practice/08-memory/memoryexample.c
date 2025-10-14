/*
Real-Life Memory Management Example
To demonstrate a practical example of dynamic memory, we created a program that can make a list of any length.

Regular arrays in C have a fixed length and cannot be changed, but with dynamic memory we can create a list as long as we like:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


struct list {
  int *data; // Points to the memory where the list items are stored
  int numItems; // Indicates how many items are currently in the list
  int size; // Indicates how many items fit in the allocated memory
};

void addToList(struct list *myList, int item);

int main() {
  struct list myList;
  int amount;
  int i, j;

  // Create a list and start with enough space for 10 items
  myList.numItems = 0;
  myList.size = 10;
  myList.data = malloc(myList.size * sizeof(int));

  // Find out if memory allocation was successful
  if (myList.data == NULL) {
    printf("Memory allocation failed");
    return 1; // Exit the program with an error code
  }

  // Add any number of items to the list specified by the amount variable
  amount = 44;
  for (i = 0; i < amount; i++) {
    addToList(&myList, i + 1);
  }

  // Display the contents of the list
  for (j = 0; j < myList.numItems; j++) {
    printf("%d ", myList.data[j]);
  }

  // Free the memory when it is no longer needed
  free(myList.data);
  myList.data = NULL;

  return 0;
}

// This function adds an item to a list
void addToList(struct list *myList, int item) {

  // If the list is full then resize the memory to fit 10 more items
  if (myList->numItems == myList->size) {
    int newSize = myList->size + 10;

    // Use a temporary pointer so we don't lose the original on failure
    int *tmp = realloc(myList->data, newSize * sizeof(int));
    if (tmp == NULL) {
      printf("Memory resize failed\n");
      return; // Leave the list unchanged
    }

    // Only update fields after a successful reallocation
    myList->data = tmp;
    myList->size = newSize;
  }

  // Add the item to the end of the list
  myList->data[myList->numItems] = item;
  myList->numItems++;
}
