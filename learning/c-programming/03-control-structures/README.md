 # Control Structures in C

## Concept
Control structures determine the flow of program execution. They allow you to make decisions, repeat actions, and control the sequence of operations in your program.

## Types of Control Structures

### 1. Conditional Statements

#### If-Else Statement
```c
if (condition) {
    // code if condition is true
} else if (another_condition) {
    // code if another_condition is true
} else {
    // code if all conditions are false
}
```

#### Switch Statement
```c
switch (variable) {
    case value1:
        // code for value1
        break;
    case value2:
        // code for value2
        break;
    default:
        // code if no case matches
        break;
}
```

### 2. Loops

#### For Loop
Best for when you know the number of iterations:
```c
for (initialization; condition; increment) {
    // code to repeat
}
```

#### While Loop
Best for when condition is checked before execution:
```c
while (condition) {
    // code to repeat
    // don't forget to update condition!
}
```

#### Do-While Loop
Best for when you need at least one execution:
```c
do {
    // code to repeat
} while (condition);
```

### 3. Loop Control

- **`break`**: Exits the loop immediately
- **`continue`**: Skips the current iteration and moves to the next

## Key Points
1. Always use braces `{}` even for single statements (good practice)
2. Be careful with infinite loops - ensure loop conditions can become false
3. Use `switch` for multiple discrete values, `if-else` for ranges
4. Remember `break` in switch statements to prevent fall-through
5. Logical operators: `&&` (AND), `||` (OR), `!` (NOT)

## Common Operators
- **Comparison**: `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Logical**: `&&`, `||`, `!`
- **Increment/Decrement**: `++`, `--`

## How to Run
```bash
gcc control.c -o control
./control
```

## Learning Objectives
- Master conditional statements (if-else, switch)
- Understand different types of loops
- Learn when to use each type of loop
- Practice with break and continue statements
- Understand logical and comparison operators
