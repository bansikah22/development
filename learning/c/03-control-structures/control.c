#include <stdio.h>

int main() {
    // If-else statements
    printf("=== IF-ELSE STATEMENTS ===\n");
    int number = 15;

    if (number > 0) {
        printf("%d is positive\n", number);
    } else if (number < 0) {
        printf("%d is negative\n", number);
    } else {
        printf("%d is zero\n", number);
    }

    // Nested if
    int age = 20;
    if (age >= 18) {
        if (age >= 65) {
            printf("Senior citizen\n");
        } else {
            printf("Adult\n");
        }
    } else {
        printf("Minor\n");
    }

    // For loop
    printf("\n=== FOR LOOPS ===\n");
    printf("Counting from 1 to 5: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // While loop
    printf("\n=== WHILE LOOPS ===\n");
    int count = 1;
    printf("While loop countdown: ");
    while (count <= 3) {
        printf("%d ", count);
        count++;
    }
    printf("\n");

    // Do-while loop
    printf("\n=== DO-WHILE LOOPS ===\n");
    int num = 1;
    printf("Do-while loop: ");
    do {
        printf("%d ", num);
        num++;
    } while (num <= 3);
    printf("\n");

    // Switch statement
    printf("\n=== SWITCH STATEMENTS ===\n");
    char grade = 'B';
    switch (grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Good job!\n");
            break;
        case 'C':
            printf("Average\n");
            break;
        case 'D':
            printf("Below average\n");
            break;
        case 'F':
            printf("Failed\n");
            break;
        default:
            printf("Invalid grade\n");
            break;
    }

    // Break and continue in loops
    printf("\n=== BREAK AND CONTINUE ===\n");
    printf("Numbers 1-10, skipping 5, stopping at 8: ");
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue; // Skip 5
        }
        if (i == 8) {
            break; // Stop at 8
        }
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
