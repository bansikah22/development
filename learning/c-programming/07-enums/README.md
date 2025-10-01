# Enums in C

An enum (enumeration) is a user-defined data type that consists of named integer constants.

## Key Concepts

- Enums make code more readable and maintainable
- By default, the first value is 0, second is 1, etc.
- You can assign specific values to enum constants
- Enums are internally stored as integers

## Basic Enum Declaration

```c
enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};
```

## Using typedef with Enums

```c
typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} Day;
Day today = WED;  // Cleaner syntax
```

## Custom Values

```c
enum Status {FAILED = -1, SUCCESS = 0, PENDING = 1};
```

Think of enums like a list of named choices - instead of remembering that Monday = 0, you just use MON!
