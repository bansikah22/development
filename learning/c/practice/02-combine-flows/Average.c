#include <stdio.h>

int main() {
    /*
    ==============================
      PROGRAM: Student Average
    ==============================
    Steps:
    1. Declare variables to store marks and the average.
    2. Ask the user how many subjects.
    3. Loop through each subject and read the mark.
    4. Add up all the marks.
    5. Divide by the number of subjects to find the average.
    6. Print the average result.
    */

    int numSubjects;
    float mark, sum = 0, average;

    // Step 2: Ask user how many subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    // Step 3: Loop through each subject
    for (int i = 1; i <= numSubjects; i++) {
        printf("Enter mark for subject %d: ", i);
        scanf("%f", &mark);
        sum += mark;  // Step 4: Add mark to total
    }

    // Step 5: Calculate average
    average = sum / numSubjects;

    // Step 6: Print result
    printf("\nTotal Marks = %.2f\n", sum);
    printf("Average Marks = %.2f\n", average);

    // Optional: Print grade
    if (average >= 70)
        printf("Grade: A\n");
    else if (average >= 60)
        printf("Grade: B\n");
    else if (average >= 50)
        printf("Grade: C\n");
    else if (average >= 40)
        printf("Grade: D\n");
    else
        printf("Grade: F\n");

    return 0;
}


