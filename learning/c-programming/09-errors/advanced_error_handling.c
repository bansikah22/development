#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to safely read a string
int safeStringInput(char *buffer, int maxSize) {
    printf("Enter a string: ");
    if (fgets(buffer, maxSize, stdin) != NULL) {
        // Remove newline if present
        buffer[strcspn(buffer, "\n")] = 0;
        return 0; // Success
    }
    return -1; // Error
}

// Function to safely convert string to integer
int safeStringToInt(const char *str, int *result) {
    char *endPtr;
    long value = strtol(str, &endPtr, 10);

    // Check for conversion errors
    if (endPtr == str) {
        printf("Error: No digits found in '%s'\n", str);
        return -1;
    }

    if (*endPtr != '\0') {
        printf("Error: Invalid characters in '%s'\n", str);
        return -1;
    }

    if (value > INT_MAX || value < INT_MIN) {
        printf("Error: Number '%s' is too large/small\n", str);
        return -1;
    }

    *result = (int)value;
    return 0; // Success
}

// Function to safely access array element
int safeArrayAccess(int *array, int size, int index, int *value) {
    if (array == NULL) {
        printf("Error: Array is NULL\n");
        return -1;
    }

    if (index < 0 || index >= size) {
        printf("Error: Index %d is out of bounds (0-%d)\n", index, size-1);
        return -1;
    }

    *value = array[index];
    return 0; // Success
}

int main() {
    printf("=== Advanced Error Handling - Better Safe Than Sorry! ===\n\n");

    // 1. Safe string input
    printf("=== Safe String Input ===\n");
    char name[50];
    if (safeStringInput(name, sizeof(name)) == 0) {
        printf("Successfully read: '%s'\n", name);
    } else {
        printf("Failed to read string!\n");
    }

    // 2. Safe string to number conversion
    printf("\n=== Safe String to Number Conversion ===\n");
    char numberStrings[][20] = {"123", "45.67", "abc", "123abc", "999999999999999"};
    int numStrings = sizeof(numberStrings) / sizeof(numberStrings[0]);

    for (int i = 0; i < numStrings; i++) {
        int number;
        printf("Converting '%s': ", numberStrings[i]);
        if (safeStringToInt(numberStrings[i], &number) == 0) {
            printf("Success! Value = %d\n", number);
        } else {
            printf("Failed to convert\n");
        }
    }

    // 3. Safe array access
    printf("\n=== Safe Array Access ===\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    int testIndices[] = {0, 2, 4, 5, -1, 10};
    int numTests = sizeof(testIndices) / sizeof(testIndices[0]);

    for (int i = 0; i < numTests; i++) {
        int value;
        int index = testIndices[i];

        printf("Accessing index %d: ", index);
        if (safeArrayAccess(numbers, arraySize, index, &value) == 0) {
            printf("Success! Value = %d\n", value);
        } else {
            printf("Access failed\n");
        }
    }

    // 4. Memory allocation with error checking
    printf("\n=== Safe Memory Allocation ===\n");

    int sizes[] = {5, 1000000, 0};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        printf("Allocating memory for %d integers: ", size);

        if (size <= 0) {
            printf("Error: Invalid size!\n");
            continue;
        }

        int *ptr = malloc(size * sizeof(int));
        if (ptr == NULL) {
            printf("Allocation failed!\n");
        } else {
            printf("Success!\n");

            // Use the memory safely
            for (int j = 0; j < size && j < 5; j++) {
                ptr[j] = j * 10;
            }

            free(ptr);
            ptr = NULL;
        }
    }

    // 5. Function return status pattern
    printf("\n=== Error Codes Summary ===\n");
    printf("0  = Success\n");
    printf("-1 = General error\n");
    printf("-2 = Invalid input\n");
    printf("-3 = Memory error\n");
    printf("-4 = File error\n");

    printf("\nAlways check return values and handle errors gracefully!\n");

    return 0;
}
