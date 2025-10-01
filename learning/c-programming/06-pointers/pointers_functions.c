#include <stdio.h>

// Function that tries to change a value (won't work without pointers)
void changeValueWrong(int x) {
    x = 999;  // This only changes the copy, not the original!
    printf("Inside function (copy): x = %d\n", x);
}

// Function that changes a value using pointers (works!)
void changeValueRight(int *x) {
    *x = 999;  // This changes the original variable!
    printf("Inside function (original): *x = %d\n", *x);
}

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;  // Store value at address a
    *a = *b;        // Put value from b into a
    *b = temp;      // Put stored value into b
}

int main() {
    printf("=== Pointers with Functions - Real Magic! ===\n\n");

    // Demonstrate why we need pointers with functions
    int myNumber = 50;

    printf("=== Without Pointers (Doesn't Work) ===\n");
    printf("Before function: myNumber = %d\n", myNumber);
    changeValueWrong(myNumber);  // Pass the value (copy)
    printf("After function: myNumber = %d (unchanged!)\n", myNumber);

    printf("\n=== With Pointers (Works!) ===\n");
    printf("Before function: myNumber = %d\n", myNumber);
    changeValueRight(&myNumber);  // Pass the address
    printf("After function: myNumber = %d (changed!)\n", myNumber);

    // Demonstrate swapping
    printf("\n=== Swapping Numbers ===\n");
    int first = 10, second = 20;

    printf("Before swap: first = %d, second = %d\n", first, second);
    swap(&first, &second);  // Pass addresses of both variables
    printf("After swap: first = %d, second = %d\n", first, second);

    // Array and pointers relationship
    printf("\n=== Arrays and Pointers ===\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Array name is like a pointer to first element

    printf("Array elements using array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    printf("\nSame elements using pointer notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }

    // Pointer arithmetic
    printf("\n=== Pointer Arithmetic ===\n");
    printf("ptr points to: %d (address: %p)\n", *ptr, ptr);
    ptr++;  // Move to next element
    printf("After ptr++: %d (address: %p)\n", *ptr, ptr);
    ptr++;  // Move to next element
    printf("After ptr++: %d (address: %p)\n", *ptr, ptr);

    return 0;
}
