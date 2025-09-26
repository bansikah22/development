# Variables and Data Types in C

## Concept
Variables are containers that store data values. C is a statically typed language, meaning you must declare the type of a variable before using it. Understanding data types is fundamental to C programming.

## Data Types in C

### 1. Integer Types
- **`int`**: Standard integer (usually 4 bytes)
- **`short`**: Short integer (usually 2 bytes)
- **`long`**: Long integer (usually 8 bytes)

### 2. Floating Point Types
- **`float`**: Single precision floating point (4 bytes)
- **`double`**: Double precision floating point (8 bytes)

### 3. Character Types
- **`char`**: Single character (1 byte)
- **`char[]`**: Array of characters (string)

### 4. Constants
Use the `const` keyword to create variables that cannot be modified after initialization.

## Format Specifiers
- `%d` - integers
- `%f` - floats
- `%lf` - doubles
- `%c` - characters
- `%s` - strings
- `%ld` - long integers
- `%zu` - size_t (for sizeof)

## Variable Declaration Syntax
```c
data_type variable_name = initial_value;
```

## Key Points
1. **Initialization**: Always initialize variables before using them
2. **Naming**: Use meaningful variable names (camelCase or snake_case)
3. **Scope**: Variables declared in a block are only accessible within that block
4. **Constants**: Use `const` for values that shouldn't change

## How to Run
```bash
gcc variables.c -o variables
./variables
```

## Learning Objectives
- Understand different data types in C
- Learn variable declaration and initialization
- Practice using format specifiers for output
- Understand the concept of constants
- Learn about memory sizes of different data types
