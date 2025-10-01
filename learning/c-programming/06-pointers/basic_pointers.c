#include <stdio.h>

int main() {
    printf("=== Pointer Basics - Like GPS Addresses! ===\n\n");

    // Step 1: Create a regular variable (like a house)
    int number = 42;
    char letter = 'A';
    float price = 19.99;

    printf("=== Our Variables (Houses) ===\n");
    printf("Number: %d\n", number);
    printf("Letter: %c\n", letter);
    printf("Price: %.2f\n", price);

    // Step 2: Create pointers (like GPS devices)
    int *numPtr;      // Pointer to integer
    char *charPtr;    // Pointer to character
    float *floatPtr;  // Pointer to float

    // Step 3: Make pointers point to variables (get addresses)
    numPtr = &number;    // numPtr now holds the address of number
    charPtr = &letter;   // charPtr now holds the address of letter
    floatPtr = &price;   // floatPtr now holds the address of price

    printf("\n=== Addresses (Like Street Addresses) ===\n");
    printf("Address of number: %p\n", &number);
    printf("Address of letter: %p\n", &letter);
    printf("Address of price: %p\n", &price);

    printf("\n=== What Pointers Store ===\n");
    printf("numPtr stores address: %p\n", numPtr);
    printf("charPtr stores address: %p\n", charPtr);
    printf("floatPtr stores address: %p\n", floatPtr);

    // Step 4: Use pointers to get values (dereference)
    printf("\n=== Getting Values Through Pointers ===\n");
    printf("Value at numPtr address: %d\n", *numPtr);      // Shows 42
    printf("Value at charPtr address: %c\n", *charPtr);    // Shows 'A'
    printf("Value at floatPtr address: %.2f\n", *floatPtr); // Shows 19.99

    // Step 5: Change values through pointers
    printf("\n=== Changing Values Through Pointers ===\n");
    *numPtr = 100;     // Changes number to 100
    *charPtr = 'Z';    // Changes letter to 'Z'
    *floatPtr = 99.99; // Changes price to 99.99

    printf("After changes:\n");
    printf("Number: %d (changed through pointer!)\n", number);
    printf("Letter: %c (changed through pointer!)\n", letter);
    printf("Price: %.2f (changed through pointer!)\n", price);

    return 0;
}
