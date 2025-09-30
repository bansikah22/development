#include <stdio.h>

/*
Let's use the w mode from the previous chapter again, and write something to the file we just created.

The w mode means that the file is opened for writing. To insert content to it, you can use the fprintf() function and add the pointer variable (fptr in our example) and some text:

If you want to add content to a file without deleting the old content, you can use the a mode.

The a mode appends content at the end of the file:


*/
int main()
  {
  FILE *fptr;
   fptr = fopen("test.txt", "w");

   fprintf(fptr, "This is a test file.\n");
   fprintf(fptr, "This is the second line.\n");

   // Open a file in append mode
   fptr = fopen("filename.txt", "a");// filename should already exist

   // Append some text to the file
   fprintf(fptr, "\nHi everybody!");

   fclose(fptr);
   return 0;

  }