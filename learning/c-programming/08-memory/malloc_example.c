#include <stdio.h>
#include <stdlib.h>
# Memory Management in C
int main() {
    // Allocate memory for 5 integers
    int *numbers = malloc(5 * sizeof(int));

    // Check if allocation was successful
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated successfully!\n");

    // Use the allocated memory
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Show memory addresses
    printf("\nMemory addresses:\n");
    for (int i = 0; i < 5; i++) {
        printf("Address of numbers[%d]: %p\n", i, &numbers[i]);
    }

    // Free the allocated memory
    free(numbers);
    numbers = NULL; // Good practice to avoid dangling pointer

    printf("\nMemory freed successfully!\n");

    return 0;
}
/*
Memory management is crucial in C programming. C gives you direct control over memory allocation and deallocation.

## Types of Memory

1. **Stack Memory**: Automatic variables (local variables)
2. **Heap Memory**: Dynamic memory allocation
3. **Static Memory**: Global and static variables

## Dynamic Memory Allocation Functions

- `malloc()`: Allocates memory block
- `calloc()`: Allocates and initializes memory
- `realloc()`: Resizes memory block
- `free()`: Deallocates memory

## Important Rules

- Always free allocated memory
- Don't use memory after freeing it
- Don't free the same memory twice
- Check if allocation was successful

Think of memory like toy boxes:
- Stack: Boxes that appear and disappear automatically
- Heap: Boxes you must ask for and return yourself
