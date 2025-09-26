# Input and Output in C

## Concept
Input and Output (I/O) operations allow programs to interact with users and external data sources. C provides several functions for reading input from users and displaying output to the console or files.

## Output Functions

### printf() - Formatted Output
```c
printf("format string", arguments);
```

### Common Format Specifiers
- `%d` - integers
- `%f` - floats (default 6 decimal places)
- `%.2f` - floats with 2 decimal places
- `%c` - single character
- `%s` - strings
- `%x` - hexadecimal
- `%o` - octal
- `%e` - scientific notation

### Formatting Options
```c
printf("%10d", num);      // Right-aligned in 10 spaces
printf("%-10d", num);     // Left-aligned in 10 spaces
printf("%05d", num);      // Zero-padded to 5 digits
printf("%.2f", price);    // 2 decimal places
```

## Input Functions

### scanf() - Formatted Input
```c
scanf("format", &variable);
```

**Important**: Always use `&` (address-of) operator with scanf for non-array variables.

### Common scanf Patterns
```c
scanf("%d", &integer);        // Read integer
scanf("%f", &float_var);      // Read float
scanf(" %c", &character);     // Read char (note space before %c)
scanf("%s", string_array);    // Read string (no & needed for arrays)
```

### Input Validation with scanf
```c
if (scanf("%d", &num) != 1) {
    printf("Invalid input!\n");
    // Clear input buffer
    while (getchar() != '\n');
}
```

## Better Input Methods

### fgets() for Strings
Safer than scanf for string input:
```c
char buffer[100];
fgets(buffer, sizeof(buffer), stdin);
```

### getchar() for Single Characters
```c
char ch = getchar();    // Read single character
```

## File I/O Operations

### Opening Files
```c
FILE *file = fopen("filename.txt", "mode");
```

### File Modes
- `"r"` - Read only
- `"w"` - Write only (overwrites existing)
- `"a"` - Append
- `"r+"` - Read and write
- `"w+"` - Write and read (overwrites existing)

### File Operations
```c
fprintf(file, "format", args);    // Write to file
fscanf(file, "format", &vars);    // Read from file
fgets(buffer, size, file);        // Read line from file
fclose(file);                     // Close file
```

### File Error Handling
```c
FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
}
// Use file...
fclose(file);
```

## Common I/O Issues and Solutions

### 1. Input Buffer Problems
**Problem**: Leftover characters in input buffer
**Solution**: Clear buffer with `while (getchar() != '\n');`

### 2. String Input with Spaces
**Problem**: `scanf("%s", str)` stops at whitespace
**Solution**: Use `fgets()` instead

### 3. Character Input After Numbers
**Problem**: `scanf()` leaves newline in buffer
**Solution**: Use `scanf(" %c", &ch)` (note the space)

### 4. Input Validation
**Problem**: Invalid input crashes program
**Solution**: Check scanf return value and validate ranges

## Best Practices

1. **Always validate input** - Check scanf return values
2. **Clear input buffer** when needed
3. **Use fgets() for strings** instead of scanf
4. **Check file operations** - Always verify fopen success
5. **Close files** after use to free resources
6. **Use meaningful prompts** for user input
7. **Handle edge cases** - empty input, too long input, etc.

## Input Buffer Management
```c
// Clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
```

## How to Run
```bash
gcc input_output.c -o input_output
./input_output
```

## Learning Objectives
- Master printf formatting and output control
- Understand scanf and its limitations
- Learn safer input methods (fgets, getchar)
- Practice input validation and error handling
- Understand file I/O operations
- Learn to manage input buffer issues
- Master file opening, reading, writing, and closing
