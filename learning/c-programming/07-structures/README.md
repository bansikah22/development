# Structures in C

## Concept
Structures (structs) are user-defined data types that allow you to group related variables of different types under a single name. They are essential for organizing complex data and creating more sophisticated programs.

## Structure Definition
```c
struct structure_name {
    data_type member1;
    data_type member2;
    // ... more members
};
```

## Structure Declaration and Initialization

### Method 1: Initialize during declaration
```c
struct Student s1 = {1001, "John Doe", 3.85, 20};
```

### Method 2: Initialize members individually
```c
struct Student s2;
s2.id = 1002;
strcpy(s2.name, "Jane Smith");
s2.gpa = 3.92;
s2.age = 19;
```

## Accessing Structure Members

### Using Dot Operator (.)
```c
struct Student s;
s.id = 100;                    // Assign value
printf("%d", s.id);            // Access value
```

### Using Arrow Operator (->)
For pointers to structures:
```c
struct Student *ptr = &s;
ptr->id = 100;                 // Equivalent to (*ptr).id = 100
printf("%d", ptr->id);         // Access through pointer
```

## Advanced Structure Concepts

### 1. Nested Structures
Structures can contain other structures:
```c
struct Address {
    char street[100];
    char city[50];
};

struct Person {
    char name[50];
    struct Address addr;       // Nested structure
};
```

### 2. Arrays of Structures
```c
struct Student classroom[50];  // Array of 50 students
```

### 3. Pointers to Structures
```c
struct Student *ptr = &student;
ptr->name;                     // Access member through pointer
```

## Functions and Structures

### Pass by Value
```c
void printStudent(struct Student s) {
    // Receives copy of structure
}
```

### Pass by Reference (Pointer)
```c
void updateStudent(struct Student *s) {
    // Can modify original structure
    s->gpa = 4.0;
}
```

## Memory Considerations

### Structure Padding
- Compiler may add padding bytes for alignment
- Use `sizeof()` to check actual structure size
- Padding improves memory access efficiency

### Memory Layout
- Members are stored in the order declared
- Total size may be larger than sum of member sizes due to padding

## Best Practices

1. **Use meaningful names** for structures and members
2. **Initialize structures** before use
3. **Use const** for read-only structure parameters
4. **Group related data** logically in structures
5. **Consider memory alignment** for performance-critical code

## Common Use Cases
- **Records**: Student records, employee data, etc.
- **Complex Numbers**: Real and imaginary parts
- **Coordinates**: x, y, z positions
- **Date/Time**: Year, month, day, hour, etc.

## Structure vs Array
- **Array**: Collection of same type elements
- **Structure**: Collection of different type elements
- **Use Array**: When you need multiple values of same type
- **Use Structure**: When you need to group related but different types

## How to Run
```bash
gcc structures.c -o structures
./structures
```

## Learning Objectives
- Understand structure definition and declaration
- Master structure member access (dot and arrow operators)
- Learn to work with nested structures
- Practice passing structures to functions
- Understand memory layout and padding
- Learn to create arrays of structures
- Master pointers to structures
