#include <stdio.h>
#include <string.h>
/*
Structures (also called structs) are a way to group several related variables into one place.

Each variable in the structure is known as a member of the structure.

Unlike an array, a structure can contain many different data types (int, float, char, etc.).

Create a Structure
You can create a structure by using the struct keyword and declare each of its members inside curly braces:


*/

struct Student{
    int id;
    char name[50];
    int age;
};

int main(){

    struct Student s1;
    s1.id = 1;
    strcpy(s1.name, "Noel");
    s1.age = 22;
    printf("Student name is: %s, student age is: %d\n", s1.name,s1.age);

    struct Student s2;
    s2.id = 2;
    strcpy(s2.name, "Bansikah");
    s2.age = 24;
    printf("Student name is: %s, student age is: %d\n", s2.name,s2.age);

    return 0;
}
