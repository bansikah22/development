#include <stdio.h>
#include <string.h>

int main() {
    printf("=== BASIC INPUT AND OUTPUT ===\n");

    // Basic output with printf
    printf("Hello, World!\n");
    printf("Integer: %d\n", 42);
    printf("Float: %.2f\n", 3.14159);
    printf("Character: %c\n", 'A');
    printf("String: %s\n", "Hello");

    // Formatted output examples
    printf("\n=== FORMATTED OUTPUT ===\n");
    int num = 123;
    float price = 45.67;

    printf("Right aligned: '%10d'\n", num);
    printf("Left aligned: '%-10d'\n", num);
    printf("Zero padded: '%05d'\n", num);
    printf("Price with 2 decimals: $%.2f\n", price);
    printf("Scientific notation: %e\n", price);

    // Basic input with scanf
    printf("\n=== BASIC INPUT ===\n");
    int age;
    float height;
    char grade;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your grade (A-F): ");
    scanf(" %c", &grade);  // Note the space before %c

    printf("You are %d years old, %.2f meters tall, with grade %c\n",
           age, height, grade);

    // String input (be careful with scanf for strings)
    printf("\n=== STRING INPUT (with scanf) ===\n");
    char first_name[50];

    printf("Enter your first name: ");
    scanf("%s", first_name);  // Stops at whitespace
    printf("Hello, %s!\n", first_name);

    // Better string input with fgets
    printf("\n=== STRING INPUT (with fgets) ===\n");
    char full_name[100];

    // Clear input buffer first
    while (getchar() != '\n');

    printf("Enter your full name: ");
    fgets(full_name, sizeof(full_name), stdin);

    // Remove newline if present
    size_t len = strlen(full_name);
    if (len > 0 && full_name[len-1] == '\n') {
        full_name[len-1] = '\0';
    }

    printf("Nice to meet you, %s!\n", full_name);

    // Character input with getchar
    printf("\n=== CHARACTER INPUT ===\n");
    printf("Press any key and hit Enter: ");
    char ch = getchar();
    printf("You pressed: '%c' (ASCII: %d)\n", ch, ch);

    // Input validation example
    printf("\n=== INPUT VALIDATION ===\n");
    int number;
    int result;

    do {
        printf("Enter a positive number (1-100): ");
        result = scanf("%d", &number);

        if (result != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear invalid input
            while (getchar() != '\n');
        } else if (number < 1 || number > 100) {
            printf("Number must be between 1 and 100!\n");
        }
    } while (result != 1 || number < 1 || number > 100);

    printf("Valid number entered: %d\n", number);

    // Multiple inputs on same line
    printf("\n=== MULTIPLE INPUTS ===\n");
    int x, y, z;
    printf("Enter three numbers separated by spaces: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Sum: %d + %d + %d = %d\n", x, y, z, x+y+z);

    // File I/O basics
    printf("\n=== FILE INPUT/OUTPUT ===\n");
    FILE *file;

    // Write to file
    file = fopen("output.txt", "w");
    if (file != NULL) {
        fprintf(file, "Hello, File!\n");
        fprintf(file, "Numbers: %d, %.2f\n", 42, 3.14);
        fclose(file);
        printf("Data written to output.txt\n");
    } else {
        printf("Error opening file for writing\n");
    }

    // Read from file
    file = fopen("output.txt", "r");
    if (file != NULL) {
        char line[100];
        printf("Reading from file:\n");
        while (fgets(line, sizeof(line), file)) {
            printf("  %s", line);
        }
        fclose(file);
    } else {
        printf("Error opening file for reading\n");
    }

    // Error handling with scanf
    printf("\n=== ERROR HANDLING ===\n");
    float value;
    printf("Enter a decimal number: ");

    if (scanf("%f", &value) == 1) {
        printf("Successfully read: %.2f\n", value);
    } else {
        printf("Failed to read a valid number\n");
        // Clear the input buffer
        while (getchar() != '\n');
    }

    return 0;
}
