#include <stdio.h>

int main() {
    // Integer types
    int age = 25;
    short small_num = 100;
    long big_num = 1000000L;

    // Floating point types
    float height = 5.9f;
    double price = 99.99;

    // Character types
    char grade = 'A';
    char name[] = "John Doe";

    // Boolean (using integers)
    int is_student = 1; // 1 for true, 0 for false

    // Constants
    const int MAX_SCORE = 100;

    // Printing different data types
    printf("=== Integer Types ===\n");
    printf("Age (int): %d\n", age);
    printf("Small number (short): %d\n", small_num);
    printf("Big number (long): %ld\n", big_num);

    printf("\n=== Floating Point Types ===\n");
    printf("Height (float): %.1f\n", height);
    printf("Price (double): %.2f\n", price);

    printf("\n=== Character Types ===\n");
    printf("Grade (char): %c\n", grade);
    printf("Name (string): %s\n", name);

    printf("\n=== Boolean and Constants ===\n");
    printf("Is student: %d\n", is_student);
    printf("Maximum score: %d\n", MAX_SCORE);

    // Size of data types
    printf("\n=== Size of Data Types ===\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));

    return 0;
}
