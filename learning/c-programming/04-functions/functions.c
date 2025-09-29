#include <stdio.h>
#include <math.h>

// Function declarations (prototypes)
int add(int a, int b);
float multiply(float x, float y);
void greet(char name[]);
int factorial(int n);
void swap(int *a, int *b);
int isEven(int num) {
    return num % 2 == 0;
}
void printArray(int arr[], int size);

int main() {
    printf("=== BASIC FUNCTIONS ===\n");

    // Simple functions with return values
    int sum = add(5, 3);
    printf("5 + 3 = %d\n", sum);

    float product = multiply(2.5, 4.0);
    printf("2.5 * 4.0 = %.2f\n", product);

    // Void function (no return value)
    printf("\n=== VOID FUNCTIONS ===\n");
    greet("Alice");
    greet("Bob");

    // Recursive function
    printf("\n=== RECURSIVE FUNCTIONS ===\n");
    int num = 5;
    printf("Factorial of %d = %d\n", num, factorial(num));

    // Functions with pointers (pass by reference)
    printf("\n=== FUNCTIONS WITH POINTERS ===\n");
    int x = 10, y = 20;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After swap: x=%d, y=%d\n", x, y);

    // Function returning boolean-like value
     printf("\n=== BOOLEAN FUNCTIONS ===\n");
       for (int i = 1; i <= 5; i++) {
           if (isEven(i)) {
               printf("%d is even\n", i);
           } else {
               printf("%d is odd\n", i);
           }
       }

    // Function with arrays
    printf("\n=== FUNCTIONS WITH ARRAYS ===\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array contents: ");
    printArray(numbers, size);

    return 0;
}

// Function definitions

// Addition function
int add(int a, int b) {
    return a + b;
}

// Multiplication function
float multiply(float x, float y) {
    return x * y;
}

// Greeting function (void - no return value)
void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

// Recursive factorial function
int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive call
}

// Swap function using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if number is even
int isEven(int num) {
    return (num % 2 == 0); // Returns 1 if even, 0 if odd
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
