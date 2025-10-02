#include <stdio>
#include <stdlib.h>


/*
Memory in C
Understanding how memory works in C is important. When you create a basic variable, C will automatically reserve space for that variable. An int variable for example, will typically occupy 4 bytes of memory, while a double variable will occupy 8 bytes of memory.

You can use the sizeof operator to find the size of different types:
*/
int main(){

    int myInt;
    float myFloat;
    double myDouble;
    char myChar;

   printf("%zu\n", sizeof(myInt));      // 4 bytes
   printf("%zu\n", sizeof(myFloat));    // 4 bytes
   printf("%zu\n", sizeof(myDouble));   // 8 bytes
   printf("%zu\n", sizeof(myChar));     // 1 byte

}