#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate and initialize memory for 5 integers
    int *numbers = calloc(5, sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // calloc initializes all values to 0
    printf("Values after calloc (all should be 0):\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Modify some values
    for (int i = 0; i < 5; i++) {
        numbers[i] = (i + 1) * 5;
    }

    printf("\nAfter modification:\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Demonstrate difference between malloc and calloc
    printf("\n--- Comparing malloc vs calloc ---\n");

    int *malloc_array = malloc(3 * sizeof(int));
    int *calloc_array = calloc(3, sizeof(int));

    printf("malloc array (uninitialized): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", malloc_array[i]);
    }

    printf("\ncalloc array (initialized to 0): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", calloc_array[i]);
    }
    printf("\n");

    free(numbers);
    free(malloc_array);
    free(calloc_array);

    return 0;
}
