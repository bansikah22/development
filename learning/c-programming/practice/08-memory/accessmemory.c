#include <stdio.h>
#include <stdlib.h>

/*
Access Dynamic Memory
Dynamic memory behaves like an array, with its data type specified by the type of the pointer.

As with arrays, to access an element in dynamic memory, refer to its index number:
*/
int main() {    
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