#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int *ptr;

    printf("=== Testing File Operation Errors ===\n");

    // Try to open a file that doesn't exist
    errno = 0; // Reset errno
    file = fopen("nonexistent.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        printf("Error code (errno): %d\n", errno);
        printf("Error message: %s\n", strerror(errno));

        // Alternative way using perror
        perror("File opening failed");
    } else {
        printf("File opened successfully!\n");
        fclose(file);
    }

    printf("\n=== Testing Memory Allocation Errors ===\n");

    // Try to allocate a huge amount of memory (will likely fail)
    errno = 0;
    ptr = malloc(SIZE_MAX); // This should fail

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        if (errno != 0) {
            printf("Error code: %d\n", errno);
            printf("Error message: %s\n", strerror(errno));
            perror("malloc failed");
        }
    } else {
        printf("Unexpectedly allocated huge memory!\n");
        free(ptr);
    }

    printf("\n=== Testing Division by Zero (System Error) ===\n");

    // Note: Division by zero doesn't always set errno
    errno = 0;
    int a = 10, b = 0;

    if (b == 0) {
        printf("Preventing division by zero before it happens!\n");
    } else {
        int result = a / b;
        printf("Result: %d\n", result);
    }

    printf("\n=== Creating a Test File for Success Case ===\n");

    // Create a file first
    file = fopen("test.txt", "w");
    if (file != NULL) {
        fprintf(file, "Hello, World!");
        fclose(file);
        printf("Created test.txt successfully\n");

        // Now try to read it
        errno = 0;
        file = fopen("test.txt", "r");
        if (file != NULL) {
            char buffer[100];
            if (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("Read from file: %s\n", buffer);
            }
            fclose(file);
        }
    }

    return 0;
}
