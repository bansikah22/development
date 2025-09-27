#include <stdio.h>
#include <string.h>

int main() {
    printf("🎯 WELCOME TO ARRAYS IN C! 🎯\n");
    printf("================================\n\n");

    // 📚 BASIC ARRAY CREATION (Like organizing books on a shelf)
    printf("📚 1. CREATING ARRAYS (Like organizing books)\n");
    printf("--------------------------------------------\n");

    // Method 1: Create empty array, fill later
    int myNumbers[5];
    myNumbers[0] = 10;
    myNumbers[1] = 20;
    myNumbers[2] = 30;
    myNumbers[3] = 40;
    myNumbers[4] = 50;

    // Method 2: Create and fill at same time
    int testScores[4] = {85, 92, 78, 90};

    // Method 3: Let C count the size
    int ages[] = {12, 15, 18, 21, 25};

    printf("My numbers: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", myNumbers[i]);
    }
    printf("\n");

    printf("Test scores: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", testScores[i]);
    }
    printf("\n\n");

    // 🔍 ACCESSING ARRAY ELEMENTS (Like finding specific books)
    printf("🔍 2. ACCESSING ELEMENTS (Finding specific items)\n");
    printf("-----------------------------------------------\n");

    printf("First test score: %d\n", testScores[0]);
    printf("Last test score: %d\n", testScores[3]);
    printf("Third age: %d\n", ages[2]);

    // Remember: Arrays start counting at 0, not 1!
    printf("\n📝 Remember: Arrays start counting at 0!\n");
    printf("Position 0 = first item, Position 1 = second item, etc.\n\n");

    // 🧮 ARRAY CALCULATIONS (Like counting your toys)
    printf("🧮 3. ARRAY CALCULATIONS (Math with arrays)\n");
    printf("------------------------------------------\n");

    // Find the sum of all test scores
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        sum = sum + testScores[i];  // Add each score to total
    }
    float average = (float)sum / 4;

    printf("All test scores: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", testScores[i]);
    }
    printf("\n");
    printf("Sum of all scores: %d\n", sum);
    printf("Average score: %.1f\n\n", average);

    // 🏆 FINDING THE BIGGEST AND SMALLEST (Like finding tallest friend)
    printf("🏆 4. FINDING BIGGEST & SMALLEST\n");
    printf("-------------------------------\n");

    int numbers[] = {45, 78, 23, 89, 56, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int biggest = numbers[0];    // Start with first number
    int smallest = numbers[0];   // Start with first number

    for(int i = 1; i < size; i++) {
        if(numbers[i] > biggest) {
            biggest = numbers[i];
        }
        if(numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    printf("Numbers: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Biggest number: %d\n", biggest);
    printf("Smallest number: %d\n\n", smallest);

    // 📝 STRING ARRAYS (Like writing your name letter by letter)
    printf("📝 5. STRING ARRAYS (Words made of letters)\n");
    printf("------------------------------------------\n");

    char myName[] = "Alice";
    char friendName[20] = "Bob";
    char petName[] = {'M', 'a', 'x', '\0'};  // Manual way with \0

    printf("My name: %s (length: %lu letters)\n", myName, strlen(myName));
    printf("Friend's name: %s\n", friendName);
    printf("Pet's name: %s\n", petName);

    // Copying strings (like copying homework)
    char copiedName[20];
    strcpy(copiedName, myName);
    printf("Copied name: %s\n\n", copiedName);

    // 🏢 2D ARRAYS (Like apartment building with floors and rooms)
    printf("🏢 6. 2D ARRAYS (Like apartment buildings)\n");
    printf("----------------------------------------\n");

    int apartments[3][3] = {
        {101, 102, 103},  // Floor 1
        {201, 202, 203},  // Floor 2
        {301, 302, 303}   // Floor 3
    };

    printf("Apartment Building Layout:\n");
    for(int floor = 0; floor < 3; floor++) {
        printf("Floor %d: ", floor + 1);
        for(int room = 0; room < 3; room++) {
            printf("Room-%d ", apartments[floor][room]);
        }
        printf("\n");
    }
    printf("Room on floor 2, position 1: %d\n\n", apartments[1][0]);

    // 👥 ARRAY OF NAMES (Like class roster)
    printf("👥 7. ARRAY OF NAMES (Class roster)\n");
    printf("---------------------------------\n");

    char students[4][20] = {"Alice", "Bob", "Charlie", "Diana"};
    int numStudents = 4;

    printf("Class Roster:\n");
    for(int i = 0; i < numStudents; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }
    printf("\n");

    // 🔎 SEARCHING IN ARRAYS (Like finding your favorite toy)
    printf("🔎 8. SEARCHING IN ARRAYS (Finding items)\n");
    printf("---------------------------------------\n");

    int searchNumbers[] = {10, 25, 30, 45, 50};
    int searchSize = 5;
    int lookingFor = 30;
    int found = -1;  // -1 means "not found"

    printf("Looking for number %d in: ", lookingFor);
    for(int i = 0; i < searchSize; i++) {
        printf("%d ", searchNumbers[i]);
        if(searchNumbers[i] == lookingFor) {
            found = i;  // Remember where we found it!
        }
    }
    printf("\n");

    if(found != -1) {
        printf("Found %d at position %d! 🎉\n", lookingFor, found);
    } else {
        printf("Number %d not found 😞\n", lookingFor);
    }
    printf("\n");

    // 📊 GRADEBOOK EXAMPLE (Real-world usage)
    printf("📊 9. GRADEBOOK EXAMPLE (Real-world usage)\n");
    printf("----------------------------------------\n");

    char subjects[3][15] = {"Math", "Science", "English"};
    int grades[3] = {88, 92, 85};

    printf("Report Card:\n");
    printf("------------\n");
    for(int i = 0; i < 3; i++) {
        printf("%-10s: %d%%", subjects[i], grades[i]);

        // Add letter grade
        if(grades[i] >= 90) printf(" (A)");
        else if(grades[i] >= 80) printf(" (B)");
        else if(grades[i] >= 70) printf(" (C)");
        else printf(" (F)");
        printf("\n");
    }

    // Calculate GPA
    int totalGrades = 0;
    for(int i = 0; i < 3; i++) {
        totalGrades += grades[i];
    }
    float gpa = (float)totalGrades / 3;
    printf("\nOverall Average: %.1f%%\n", gpa);
    printf("\n");

    // 🚨 COMMON MISTAKES TO AVOID
    printf("🚨 10. REMEMBER THESE IMPORTANT RULES!\n");
    printf("------------------------------------\n");
    printf("✅ Arrays start at position 0, not 1\n");
    printf("✅ Don't go past the last position (causes crash!)\n");
    printf("✅ All items in array must be same type\n");
    printf("✅ Strings need \\0 at the end\n");
    printf("✅ Use loops to work with many items easily\n");
    printf("\n");

    printf("🎉 Great job learning arrays! 🎉\n");
    printf("Arrays help you organize lots of data easily!\n");

    return 0;
}
