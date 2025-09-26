#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== BASIC POINTER CONCEPTS ===\n");

    // Basic pointer declaration and initialization
    int num = 42;
    int *ptr = &num;  // ptr points to the address of num

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr (address it holds): %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);
    printf("Address of ptr itself: %p\n", (void*)&ptr);

    // Modifying value through pointer
    printf("\n=== MODIFYING VALUES THROUGH POINTERS ===\n");
    printf("Original value of num: %d\n", num);
    *ptr = 100;  // Change value through pointer
    printf("After *ptr = 100, num is now: %d\n", num);

    // Pointer arithmetic
    printf("\n=== POINTER ARITHMETIC ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *arr_ptr = arr;  // Point to first element

    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(arr_ptr + %d) = %d\n",
               i, arr[i], i, *(arr_ptr + i));
    }

    // Moving pointer
    printf("\nMoving pointer through array:\n");
    arr_ptr = arr;  // Reset to beginning
    for (int i = 0; i < 5; i++) {
        printf("Current value: %d, address: %p\n", *arr_ptr, (void*)arr_ptr);
        arr_ptr++;  // Move to next element
    }

    // Pointers and functions
    printf("\n=== POINTERS AND FUNCTIONS ===\n");
    int a = 5, b = 10;
    printf("Before swap: a=%d, b=%d\n", a, b);

    // Function to swap values (defined below)
    swap(&a, &b);
    printf("After swap: a=%d, b=%d\n", a, b);

    // Null pointers
    printf("\n=== NULL POINTERS ===\n");
    int *null_ptr = NULL;
    printf("Null pointer value: %p\n", (void*)null_ptr);

    // Always check before dereferencing
    if (null_ptr != NULL) {
        printf("Safe to dereference: %d\n", *null_ptr);
    } else {
        printf("Cannot dereference null pointer!\n");
    }

    // Dynamic memory allocation
    printf("\n=== DYNAMIC MEMORY ALLOCATION ===\n");
    int *dynamic_arr = (int*)malloc(5 * sizeof(int));

    if (dynamic_arr != NULL) {
        // Initialize allocated memory
        for (int i = 0; i < 5; i++) {
            dynamic_arr[i] = (i + 1) * 10;
        }

        printf("Dynamically allocated array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", dynamic_arr[i]);
        }
        printf("\n");

        // Free allocated memory
        free(dynamic_arr);
        dynamic_arr = NULL;  // Good practice to avoid dangling pointers
        printf("Memory freed successfully\n");
    } else {
        printf("Memory allocation failed!\n");
    }

    // Pointer to pointer
    printf("\n=== POINTER TO POINTER ===\n");
    int value = 25;
    int *ptr1 = &value;
    int **ptr2 = &ptr1;  // Pointer to pointer

    printf("Value: %d\n", value);
    printf("*ptr1: %d\n", *ptr1);
    printf("**ptr2: %d\n", **ptr2);
    printf("Address of value: %p\n", (void*)&value);
    printf("ptr1 (address of value): %p\n", (void*)ptr1);
    printf("ptr2 (address of ptr1): %p\n", (void*)ptr2);

    return 0;
}

// Function to swap two integers using pointers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
