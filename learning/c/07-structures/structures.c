#include <stdio.h>
#include <string.h>

// Define a simple structure
struct Student {
    int id;
    char name[50];
    float gpa;
    int age;
};

// Define structure with nested structure
struct Address {
    char street[100];
    char city[50];
    char state[20];
    int zipcode;
};

struct Person {
    char name[50];
    int age;
    struct Address address;  // Nested structure
};

// Function prototypes
void printStudent(struct Student s);
void updateGPA(struct Student *s, float newGPA);

int main() {
    printf("=== BASIC STRUCTURE USAGE ===\n");

    // Different ways to initialize structures
    struct Student student1 = {1001, "Alice Johnson", 3.85, 20};

    struct Student student2;
    student2.id = 1002;
    strcpy(student2.name, "Bob Smith");
    student2.gpa = 3.92;
    student2.age = 19;

    // Print student information
    printf("Student 1:\n");
    printStudent(student1);

    printf("\nStudent 2:\n");
    printStudent(student2);

    // Modify structure members
    printf("\n=== MODIFYING STRUCTURES ===\n");
    printf("Before GPA update:\n");
    printStudent(student1);

    updateGPA(&student1, 3.95);  // Pass by reference to modify

    printf("After GPA update:\n");
    printStudent(student1);

    // Array of structures
    printf("\n=== ARRAY OF STRUCTURES ===\n");
    struct Student classroom[3] = {
        {1003, "Charlie Brown", 3.75, 21},
        {1004, "Diana Prince", 3.88, 20},
        {1005, "Eve Adams", 3.67, 19}
    };

    printf("Classroom roster:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. ", i + 1);
        printStudent(classroom[i]);
    }

    // Find highest GPA
    float highest_gpa = classroom[0].gpa;
    int top_student = 0;
    for (int i = 1; i < 3; i++) {
        if (classroom[i].gpa > highest_gpa) {
            highest_gpa = classroom[i].gpa;
            top_student = i;
        }
    }
    printf("\nTop student: %s with GPA %.2f\n",
           classroom[top_student].name, highest_gpa);

    // Nested structures
    printf("\n=== NESTED STRUCTURES ===\n");
    struct Person person1;
    strcpy(person1.name, "John Doe");
    person1.age = 30;
    strcpy(person1.address.street, "123 Main St");
    strcpy(person1.address.city, "Springfield");
    strcpy(person1.address.state, "IL");
    person1.address.zipcode = 62701;

    printf("Person Information:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address: %s, %s, %s %d\n",
           person1.address.street,
           person1.address.city,
           person1.address.state,
           person1.address.zipcode);

    // Pointers to structures
    printf("\n=== POINTERS TO STRUCTURES ===\n");
    struct Student *ptr = &student1;

    // Two ways to access members through pointer
    printf("Using (*ptr).member: ID = %d, Name = %s\n",
           (*ptr).id, (*ptr).name);
    printf("Using ptr->member: ID = %d, Name = %s\n",
           ptr->id, ptr->name);

    // Modify through pointer
    ptr->age = 21;
    printf("Updated age through pointer: %d\n", ptr->age);

    // Structure comparison (manual)
    printf("\n=== STRUCTURE COMPARISON ===\n");
    struct Student temp = student1;

    if (temp.id == student1.id &&
        strcmp(temp.name, student1.name) == 0 &&
        temp.gpa == student1.gpa &&
        temp.age == student1.age) {
        printf("Structures are identical\n");
    } else {
        printf("Structures are different\n");
    }

    return 0;
}

// Function to print student information
void printStudent(struct Student s) {
    printf("ID: %d, Name: %s, GPA: %.2f, Age: %d\n",
           s.id, s.name, s.gpa, s.age);
}

// Function to update GPA using pointer
void updateGPA(struct Student *s, float newGPA) {
    s->gpa = newGPA;
    printf("GPA updated to %.2f for student %s\n", newGPA, s->name);
}
