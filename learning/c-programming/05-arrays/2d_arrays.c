#include <stdio.h>

int main() {
    printf("=== 2D Arrays - Like a Building with Floors and Rooms ===\n\n");

    // 2D array representing apartment building
    // 3 floors, 4 rooms per floor
    int building[3][4] = {
        {101, 102, 103, 104},  // Floor 1 rooms (index 0)
        {201, 202, 203, 204},  // Floor 2 rooms (index 1)
        {301, 302, 303, 304}   // Floor 3 rooms (index 2)
    };

    printf("Building Layout:\n");
    for (int floor = 0; floor < 3; floor++) {
        printf("Floor %d: ", floor + 1);
        for (int room = 0; room < 4; room++) {
            printf("Room %d  ", building[floor][room]);
        }
        printf("\n");
    }

    // Accessing specific rooms
    printf("\nSpecific Room Access:\n");
    printf("Ground floor, first room: %d\n", building[0][0]);  // 101
    printf("Second floor, last room: %d\n", building[1][3]);   // 204
    printf("Top floor, third room: %d\n", building[2][2]);     // 303

    // Student grades for different subjects
    printf("\n=== Student Grades (5 students, 3 subjects) ===\n");
    int grades[5][3] = {
        {85, 78, 92},  // Student 1: Math, Science, English
        {90, 88, 85},  // Student 2
        {76, 82, 89},  // Student 3
        {95, 91, 94},  // Student 4
        {68, 74, 71}   // Student 5
    };

    char subjects[3][10] = {"Math", "Science", "English"};

    // Print all grades
    printf("     ");
    for (int s = 0; s < 3; s++) {
        printf("%-8s ", subjects[s]);
    }
    printf("\n");

    for (int student = 0; student < 5; student++) {
        printf("St%d: ", student + 1);
        for (int subject = 0; subject < 3; subject++) {
            printf("%-8d ", grades[student][subject]);
        }
        printf("\n");
    }

    // Calculate averages
    printf("\n=== Calculating Averages ===\n");

    // Average for each student
    for (int student = 0; student < 5; student++) {
        int sum = 0;
        for (int subject = 0; subject < 3; subject++) {
            sum += grades[student][subject];
        }
        float average = sum / 3.0;
        printf("Student %d average: %.2f\n", student + 1, average);
    }

    // Average for each subject
    printf("\nSubject averages:\n");
    for (int subject = 0; subject < 3; subject++) {
        int sum = 0;
        for (int student = 0; student < 5; student++) {
            sum += grades[student][subject];
        }
        float average = sum / 5.0;
        printf("%s average: %.2f\n", subjects[subject], average);
    }

    return 0;
}
