#include <stdio.h>
#include <stdlib.h>

int main() {
    // Start with memory for 3 integers
    int *numbers = malloc(3 * sizeof(int));

    if (numbers == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < 3; i++) {
        numbers[i] = i + 1;
    }

    printf("Initial array (3 elements): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Resize to hold 6 integers
    numbers = realloc(numbers, 6 * sizeof(int));

    if (numbers == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Add new elements
    for (int i = 3; i < 6; i++) {
        numbers[i] = i + 1;
    }

    printf("After realloc (6 elements): ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Shrink back to 4 elements
    numbers = realloc(numbers, 4 * sizeof(int));

    printf("After shrinking (4 elements): ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}
