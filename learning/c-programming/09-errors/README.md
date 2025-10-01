# Error Handling in C

C doesn't have built-in exception handling like other languages, but provides several ways to handle errors.

## Types of Errors

1. **Syntax Errors**: Caught by compiler
2. **Runtime Errors**: Occur during program execution
3. **Logical Errors**: Program runs but produces wrong results

## Error Handling Methods

1. **Return Values**: Functions return error codes
2. **errno**: Global variable for system errors
3. **Error Messages**: Using `perror()` and `strerror()`

## Common Error Codes

- 0: Success (no error)
- Negative values: Usually indicate errors
- NULL: For pointer functions when allocation fails

Think of errors like warning lights in a car - they tell you something is wrong so you can fix it!
