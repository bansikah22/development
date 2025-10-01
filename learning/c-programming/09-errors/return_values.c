#include <stdio.h>

// Function that can fail - returns 0 on success, -1 on error
int divide(int a, int b, int *result) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return -1; // Error code
    }

    *result = a / b;
    return 0; // Success
}

// Function to check if a number is positive
int checkPositive(int num) {
    if (num <= 0) {
        return -1; // Error: not positive
    }
    return 0; // Success: positive number
}

// Function to find element in array
int findElement(int arr[], int size, int target, int *index) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            *index = i;
            return 0; // Success: found
        }
    }
    return -1; // Error: not found
}

int main() {
    int result;
    int status;

    printf("=== Testing Division Function ===\n");

    // Successful division
    status = divide(10, 2, &result);
    if (status == 0) {
        printf("10 / 2 = %d (Success)\n", result);
    } else {
        printf("Division failed!\n");
    }

    // Division by zero (will cause error)
    status = divide(10, 0, &result);
    if (status == -1) {
        printf("Division by zero detected and handled!\n");
    }

    printf("\n=== Testing Positive Number Check ===\n");

    int numbers[] = {5, -3, 0, 15};
    for (int i = 0; i < 4; i++) {
        if (checkPositive(numbers[i]) == 0) {
            printf("%d is positive\n", numbers[i]);
        } else {
            printf("%d is not positive\n", numbers[i]);
        }
    }

    printf("\n=== Testing Array Search ===\n");

    int arr[] = {10, 20, 30, 40, 50};
    int index;

    status = findElement(arr, 5, 30, &index);
    if (status == 0) {
        printf("Found 30 at index %d\n", index);
    } else {
        printf("30 not found in array\n");
    }

    status = findElement(arr, 5, 99, &index);
    if (status == 0) {
        printf("Found 99 at index %d\n", index);
    } else {
        printf("99 not found in array\n");
    }

    return 0;
}
