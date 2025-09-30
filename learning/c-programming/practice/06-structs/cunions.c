#include <stdio.h>
/*
C Unions
A union is similar to a struct in that it can store members of different data types.

However, there are some differences:

In a struct, each member has its own memory.
In a union, all members share the same memory, which means you can only use one of the values at a time.
Most of the time, you will use structs instead of unions, as it can store and access multiple values at the same time, which is more common in everyday programs.

However, unions are useful when you only need to store one of several possible types at a time, and you want to save memory.

Declare a Union
To create a union, use the union keyword, and then create a variable from it (just like with structs):
*/
union myUnion {
  int myNum;
  char myLetter;
  char myString[30];
};

int main() {
  union myUnion u1;

  u1.myNum = 1000;

  // Since this is the last value written to the union, myNum no longer holds 1000 - its value is now invalid
  u1.myLetter = 'A';

  printf("myNum: %d\n", u1.myNum); // This value is no longer reliable
  printf("myLetter: %c\n", u1.myLetter); // Prints 'A'
   printf("Size of union: %zu bytes\n", sizeof(u1)); // Prints 4 bytes

  return 0;
}