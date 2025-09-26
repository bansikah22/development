# Hello World - Your First C Program

## Concept
The "Hello World" program is traditionally the first program written when learning a new programming language. It demonstrates the basic syntax and structure of a C program.

## Code Structure

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    printf("Welcome to C Programming!\n");
    
    return 0;
}
```

## Key Components

1. **`#include <stdio.h>`**: This is a preprocessor directive that includes the standard input/output library, which provides functions like `printf()`.

2. **`int main()`**: This is the main function where program execution begins. Every C program must have a main function.

3. **`printf()`**: A function that prints formatted text to the console. The `\n` creates a new line.

4. **`return 0;`**: Indicates successful program termination. Returning 0 means the program executed without errors.

## How to Compile and Run

```bash
# Compile the program
gcc hello.c -o hello

# Run the program
./hello
```

## Expected Output
```
Hello, World!
Welcome to C Programming!
```

## Learning Objectives
- Understand basic C program structure
- Learn about preprocessor directives
- Understand the main function
- Learn basic output with printf()
- Understand program return values
