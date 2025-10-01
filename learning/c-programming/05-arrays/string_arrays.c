#include <stdio.h>
#include <string.h>

int main() {
    printf("=== String Arrays - Working with Text ===\n\n");

    // Different ways to create strings
    char name1[] = "Alice";                    // Easy way - C adds \0 automatically
    char name2[] = {'B', 'o', 'b', '\0'};    // Manual way - must add \0
    char name3[20] = "Charlie";               // Fixed size with extra space

    printf("Method 1: %s\n", name1);
    printf("Method 2: %s\n", name2);
    printf("Method 3: %s\n", name3);

    // String operations
    printf("\n=== String Operations ===\n");

    // 1. String length
    printf("Length of '%s': %lu characters\n", name1, strlen(name1));

    // 2. String copy
    char copyName[20];
    strcpy(copyName, name1);
    printf("Copied string: %s\n", copyName);

    // 3. String comparison
    if (strcmp(name1, "Alice") == 0) {
        printf("Names match!\n");
    }

    // 4. String concatenation
    char fullName[50] = "Hello, ";
    strcat(fullName, name1);
    printf("Concatenated: %s\n", fullName);

    // 5. Array of strings (2D array)
    char students[5][20] = {
        "Alice Johnson",
        "Bob Smith",
        "Charlie Brown",
        "Diana Prince",
        "Eve Adams"
    };

    printf("\n=== Class Roster ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: %s\n", i + 1, students[i]);
    }

    // 6. Character by character access
    printf("\n=== Spelling out '%s' ===\n", name1);
    for (int i = 0; name1[i] != '\0'; i++) {
        printf("Letter %d: %c\n", i + 1, name1[i]);
    }

    // 7. Reading user input
    char userInput[100];
    printf("\nEnter your name: ");
    // Note: In a real program, you'd want to use fgets for safety
    // fgets(userInput, sizeof(userInput), stdin);
    printf("Example: You entered 'John Doe'\n");

    return 0;
}
