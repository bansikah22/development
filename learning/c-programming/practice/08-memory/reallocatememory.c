#include <stdio.h>

/*
Reallocate Memory
If the amount of memory you reserved is not enough, you can reallocate it to make it larger.

Reallocating reserves a different (usually larger) amount of memory while keeping the data that was stored in it.

You can change the size of allocated memory with the realloc() function.

The realloc() function takes two parameters:

int *ptr2 = realloc(ptr1, size);
The first parameter is a pointer to the memory that is being resized.
The second parameter specifies the new size of allocated memory, measured in bytes.
The realloc() function tries to resize the memory at ptr1 and return the same memory address. If it cannot resize the memory at the current address then it will allocate memory at a different address and return the new address instead.

Note: When realloc() returns a different memory address, the memory at the original address is no longer reserved and it is not safe to use. When the reallocation is done it is good to assign the new pointer to the previous variable so that the old pointer cannot be used accidentally.
*/

// int main(){

//     int *ptr1, *ptr2, size;

//    // Allocate memory for four integers
//    size = 4 * sizeof(*ptr1);
//    ptr1 = malloc(size);

//    printf("%d bytes allocated at address %p \n", size, ptr1);

//     // Resize the memory to hold six integers
//    size = 6 * sizeof(*ptr1);
//    ptr2 = realloc(ptr1, size);

//    printf("%d bytes reallocated at address %p \n", size, ptr2);
//     free(ptr2); // Free the allocated memory
// }

/*
NULL Pointer & Error Checking
The realloc() function returns a NULL pointer if it is not able to allocate more memory. This is very unlikely, but it is worth keeping in mind when you need your code to be failproof.

The following example checks whether realloc() is able to resize the memory or not, by checking for a NULL pointer:

Example:

int *ptr1, *ptr2;

// Allocate memory
ptr1 = malloc(4);

// Attempt to resize the memory
ptr2 = realloc(ptr1, 8);

// Check whether realloc is able to resize the memory or not
if (ptr2 == NULL) {
  // If reallocation fails
  printf("Failed. Unable to resize memory");
} else {
  // If reallocation is sucessful
  printf("Success. 8 bytes reallocated at address %p \n", ptr2);
  ptr1 = ptr2;  // Update ptr1 to point to the newly allocated memory
}
*/



int main(){

    int *ptr1, *ptr2, size;

   // Allocate memory for four integers
   size = 4 * sizeof(*ptr1);
   ptr1 = malloc(size);

   if(ptr1 == NULL) {
       printf("Memory allocation failed\n");
       return 1; // Exit if memory allocation fails
   }

   printf("%d bytes allocated at address %p \n", size, ptr1);

    // Resize the memory to hold six integers
   size = 6 * sizeof(*ptr1);
   ptr2 = realloc(ptr1, size);

   if(ptr2 == NULL) {
       printf("Memory reallocation failed\n");
       free(ptr1); // Free the original memory if realloc fails
       return 1; // Exit if memory reallocation fails
   }

   printf("%d bytes reallocated at address %p \n", size, ptr2);
    free(ptr2); // Free the allocated memory
}
