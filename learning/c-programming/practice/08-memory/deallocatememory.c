#include <stdio.h>
#include <stdlib.h>

/*
Deallocate (free) Memory
When you no longer need a block of memory you should deallocate it. Deallocation is also referred to as "freeing" the memory.

Dynamic memory stays reserved until it is deallocated or until the program ends.

Once the memory is deallocated it can be used by other programs or it may even be allocated to another part of your program.

Free Memory
To deallocate memory, use the free() function:

free(pointer);
The pointer parameter is a pointer to the address of the memory to be deallocated:

Example:
int *ptr;
ptr = malloc(sizeof(*ptr));

free(ptr);
ptr = NULL;

int main(){

    int *dynamicArray;
    int size = 5;

    // Allocate memory for 5 integers
    dynamicArray = (int *)malloc(size * sizeof(int));
    if(dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < size; i++) {
        dynamicArray[i] = i * 10; // Accessing elements using index
    }
    for(int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]); // Accessing elements using index              
    }
    printf("\n");

    // Free the allocated memory
    free(dynamicArray);
    return 0;
} /*memory remains allocated until it is explicitly freed using the free() function.
*/

int main(){
    int *ptr;
ptr = malloc(sizeof(*ptr)); // Allocate memory for one integer

// If memory cannot be allocated, print a message and end the main() function
if (ptr == NULL) {
  printf("Unable to allocate memory");
  return 1;  // Exit the program with an error code
}

// Set the value of the integer
*ptr = 20;

// Print the integer value
printf("Integer value: %d\n", *ptr);

// Free allocated memory
free(ptr);

// Set the pointer to NULL to prevent it from being accidentally used
ptr = NULL;
}

/*
Memory Leaks
A memory leak happens when dynamic memory is allocated but never freed.

If a memory leak happens in a loop or in a function that is called frequently it could take up too much memory and cause the computer to slow down.

There is a risk of a memory leak if a pointer to dynamic memory is lost before the memory can be freed. This can happen accidentally, so it is important to be careful and keep track of pointers to dynamic memory.

Here are some examples of how a pointer to dynamic memory may be lost.

The pointer exists only inside a function:

void myFunction() {
  int *ptr;
  ptr = malloc(sizeof(*ptr));
}

int main() {
  myFunction();
  printf("The function has ended");
  return 0;
}
In this example, the memory that was allocated inside of the function remains allocated after the function ends but it cannot be accessed anymore. One way to prevent this problem is to free the memory before the function ends.
*/