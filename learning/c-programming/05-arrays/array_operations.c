#include <stdio.h>

int main() {
    printf("=== Array Operations - Practical Examples ===\n\n");

    // Array for student grades
    int grades[] = {78, 85, 92, 67, 89, 95, 73, 88};
    int numStudents = sizeof(grades) / sizeof(grades[0]);

    printf("Class grades: ");
    for (int i = 0; i < numStudents; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");

    // 1. Find the highest grade
    int highest = grades[0];
    int highestIndex = 0;

    for (int i = 1; i < numStudents; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
            highestIndex = i;
        }
    }

    printf("\nHighest grade: %d (Student #%d)\n", highest, highestIndex + 1);

    // 2. Find the lowest grade
    int lowest = grades[0];
    int lowestIndex = 0;

    for (int i = 1; i < numStudents; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
            lowestIndex = i;
        }
    }

    printf("Lowest grade: %d (Student #%d)\n", lowest, lowestIndex + 1);

    // 3. Calculate average
    int sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += grades[i];
    }
    float average = (float)sum / numStudents;

    printf("Class average: %.2f\n", average);

    // 4. Count students who passed (grade >= 70)
    int passCount = 0;
    for (int i = 0; i < numStudents; i++) {
        if (grades[i] >= 70) {
            passCount++;
        }
    }

    printf("Students who passed: %d out of %d\n", passCount, numStudents);

    // 5. Search for a specific grade
    int searchGrade = 85;
    int found = -1;

    for (int i = 0; i < numStudents; i++) {
        if (grades[i] == searchGrade) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Grade %d found at position %d (Student #%d)\n",
               searchGrade, found, found + 1);
    } else {
        printf("Grade %d not found in the class\n", searchGrade);
    }

    return 0;
}
