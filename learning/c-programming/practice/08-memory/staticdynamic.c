#include <stdio.h>
#include <stdlib.h>

/*
Static vs Dynamic Memory Allocation in C
In C, memory can be allocated in two main ways: statically and dynamically.
Static Memory Allocation
Static memory allocation occurs when you declare variables at compile time. The memory for these variables is allocated on the stack, and it is automatically freed when the function in which they are declared exits.
Example of static memory allocation:
*/
void staticMemoryExample() {
    int staticArray[5]; // Memory for 5 integers is allocated on the stack
    for(int i = 0; i < 5; i++) {
        staticArray[i] = i * 10;
    }
    for(int i = 0; i < 5; i++) {
        printf("%d ", staticArray[i]);              
    }
    printf("\n");
}       

/*
Dynamic Memory Allocation
Dynamic memory allocation occurs at runtime using functions like malloc(), calloc(), realloc(), and free(). The
memory is allocated on the heap, and it must be manually freed when it is no longer needed to avoid memory leaks.
Example of dynamic memory allocation:
*/
void dynamicMemoryExample() {
    int *dynamicArray;
    int size = 5;

    // Allocate memory for 5 integers
    dynamicArray = (int *)malloc(size * sizeof(int));
    if(dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for(int i = 0; i < size; i++) {
        dynamicArray[i] = i * 20;
    }
    for(int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);              
    }
    printf("\n");

    // Free the allocated memory
    free(dynamicArray);
}

int main() {
    printf("Static Memory Example:\n");
    staticMemoryExample();

    printf("Dynamic Memory Example:\n");
    dynamicMemoryExample();

    return 0;
} /*memory remains allocated until it is explicitly freed using the free() function.
*/