#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Pointers and Dynamic Memory - Creating Variables as Needed! ===\n\n");

    // Static vs Dynamic memory demonstration
    printf("=== Static Memory (Fixed Size) ===\n");
    int staticArray[5] = {1, 2, 3, 4, 5};  // Size fixed at compile time
    printf("Static array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", staticArray[i]);
    }
    printf("\n");

    // Dynamic memory allocation
    printf("\n=== Dynamic Memory (Size Decided at Runtime) ===\n");

    int size;
    printf("How many numbers do you want to store? ");
    printf("(Example: Let's say 7)\n");
    size = 7;  // In real program, you'd use: scanf("%d", &size);

    // Allocate memory for 'size' integers
    int *dynamicArray = malloc(size * sizeof(int));

    // Always check if allocation succeeded
    if (dynamicArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated for %d integers!\n", size);

    // Fill the dynamic array
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = (i + 1) * 10;  // 10, 20, 30, etc.
    }

    printf("Dynamic array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Demonstrate pointer arithmetic with dynamic memory
    printf("\n=== Pointer Arithmetic with Dynamic Memory ===\n");
    int *ptr = dynamicArray;  // Point to first element

    printf("Using pointer to access elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d (address: %p)\n", i, *ptr, ptr);
        ptr++;  // Move to next element
    }

    // Reset pointer to beginning
    ptr = dynamicArray;

    // Modify values through pointer
    printf("\n=== Modifying Through Pointers ===\n");
    *ptr = 999;        // Change first element
    *(ptr + 2) = 888;  // Change third element

    printf("After modifications: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Multiple pointers to same memory
    printf("\n=== Multiple Pointers to Same Memory ===\n");
    int *ptr1 = dynamicArray;
    int *ptr2 = dynamicArray;
    int *ptr3 = &dynamicArray[3];  // Point to 4th element

    printf("ptr1 points to: %d\n", *ptr1);
    printf("ptr2 points to: %d\n", *ptr2);
    printf("ptr3 points to: %d\n", *ptr3);

    *ptr1 = 111;  // Change through first pointer
    printf("After changing through ptr1:\n");
    printf("ptr1 points to: %d\n", *ptr1);
    printf("ptr2 points to: %d (same memory!)\n", *ptr2);

    // NULL pointer safety
    printf("\n=== NULL Pointer Safety ===\n");
    int *safePtr = NULL;

    printf("Checking if pointer is safe to use...\n");
    if (safePtr == NULL) {
        printf("Pointer is NULL - not safe to use!\n");
    } else {
        printf("Pointer is safe: %d\n", *safePtr);
    }

    // Always free dynamic memory
    printf("\n=== Cleaning Up Memory ===\n");
    free(dynamicArray);
    dynamicArray = NULL;  // Good practice: set to NULL after freeing

    printf("Memory freed and pointer set to NULL\n");

    // Don't use freed memory
    if (dynamicArray == NULL) {
        printf("Pointer is now NULL - memory has been freed\n");
    }

    return 0;
}
