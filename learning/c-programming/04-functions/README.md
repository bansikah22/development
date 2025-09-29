# Functions in C

## Concept
Functions are reusable blocks of code that perform specific tasks. They help organize code, reduce repetition, and make programs more modular and easier to maintain.

## Function Structure
```c
return_type function_name(parameter_list) {
    // function body
    return value; // if return_type is not void
}
```

## Types of Functions

### 1. Functions with Return Values
```c
int add(int a, int b) {
    return a + b;
}
```

### 2. Void Functions (No Return Value)
```c
void greet(char name[]) {
    printf("Hello, %s!\n", name);
}
```

### 3. Recursive Functions
Functions that call themselves:
```c
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## Function Components

### Function Declaration (Prototype)
Tells the compiler about the function before it's defined:
```c
int add(int a, int b); // Declaration
```

### Function Definition
The actual implementation of the function:
```c
int add(int a, int b) {
    return a + b; // Definition
}
```

### Function Call
Using the function in your code:
```c
int result = add(5, 3); // Call
```

## Parameter Passing

### 1. Pass by Value
- Copies the value to the function
- Changes inside function don't affect original variable
```c
void func(int x) { x = 10; } // Original variable unchanged
```

### 2. Pass by Reference (using pointers)
- Passes the address of the variable
- Changes inside function affect original variable
```c
void swap(int *a, int *b) { 
    int temp = *a; *a = *b; *b = temp; 
}
```

## Key Points
1. **Function Prototypes**: Declare functions before using them
2. **Return Statement**: Functions with return type must return a value
3. **Void Functions**: Use when no return value is needed
4. **Local Variables**: Variables inside functions are local to that function
5. **Recursion**: Useful for problems that can be broken into smaller subproblems

## Best Practices
- Use meaningful function names
- Keep functions small and focused on one task
- Use function prototypes for better organization
- Document what your functions do

## How to Run
```bash
gcc functions.c -o functions -lm
./functions
```
Note: `-lm` flag links the math library for mathematical functions.

## Learning Objectives
- Understand function syntax and structure
- Learn the difference between declaration and definition
- Practice writing functions with different return types
- Understand parameter passing (by value vs by reference)
- Learn about recursion and its applications
- Master function organization and best practices
