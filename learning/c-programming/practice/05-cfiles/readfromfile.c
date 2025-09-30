#include <stdio.h>

/*
In the previous chapter, we wrote to a file using w and a modes inside the fopen() function.

To read from a file, you can use the r mode:
*/

int main() {
FILE *fptr;

// Open a file in read mode
fptr = fopen("filename.txt", "r");

// Store the content of the file
char myString[100];

// Read the content and print it
while(fgets(myString, 100, fptr)) {
  printf("%s", myString);
}

// Close the file
fclose(fptr);
}