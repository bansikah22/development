#include <stdio.h>

int main() {
    printf("=== Array Basics - Like School Lockers! ===\n\n");

    // Method 1: Declare then assign
    int locker[5];
    locker[0] = 10;  // Put 10 in first locker
    locker[1] = 20;  // Put 20 in second locker
    locker[2] = 30;
    locker[3] = 40;
    locker[4] = 50;  // Put 50 in last locker

    printf("Method 1 - Fill lockers one by one:\n");
    for (int i = 0; i < 5; i++) {
        printf("Locker[%d] contains: %d\n", i, locker[i]);
    }

    // Method 2: Declare and initialize together
    int scores[] = {85, 92, 78, 90, 88};
    int size = sizeof(scores) / sizeof(scores[0]);

    printf("\nMethod 2 - All at once (test scores):\n");
    for (int i = 0; i < size; i++) {
        printf("Test %d score: %d\n", i + 1, scores[i]);
    }

    // Method 3: Partial initialization
    int grades[6] = {95, 87}; // First 2 are set, rest become 0

    printf("\nMethod 3 - Partial initialization:\n");
    for (int i = 0; i < 6; i++) {
        printf("Grade[%d] = %d\n", i, grades[i]);
    }

    return 0;
}
