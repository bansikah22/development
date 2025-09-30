#include <stdio.h>


/*
check https://www.w3schools.com/c/c_files.php
In C, you can create, open, read, and write to files by declaring a pointer of type FILE, and use the fopen() function:

FILE *fptr;
fptr = fopen(filename, mode);

Tip: If you want to create the file in a specific folder, just provide an absolute path (remember to use double backslashes to create a single backslash (\), like we specified in strings special characters):

fptr = fopen("C:\\directoryname\\filename.txt", "w");
*/


int main() {
    FILE *fptr;

    fptr = fopen("test.txt", "w");

    if (fptr == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    fclose(fptr);

    printf("File created and closed successfully!\n");
    return 0;
}