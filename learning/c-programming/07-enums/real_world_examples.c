#include <stdio.h>

// Real-world enum examples
typedef enum {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
} Month;

typedef enum {
    FAILED = 0,
    PASSED = 1,
    EXCELLENT = 2
} Grade;

typedef enum {
    NORTH = 0,
    EAST = 90,
    SOUTH = 180,
    WEST = 270
} Direction;

// Function using enums
const char* getMonthName(Month month) {
    switch(month) {
        case JANUARY: return "January";
        case FEBRUARY: return "February";
        case MARCH: return "March";
        case APRIL: return "April";
        case MAY: return "May";
        case JUNE: return "June";
        case JULY: return "July";
        case AUGUST: return "August";
        case SEPTEMBER: return "September";
        case OCTOBER: return "October";
        case NOVEMBER: return "November";
        case DECEMBER: return "December";
        default: return "Unknown";
    }
}

int main() {
    printf("=== Real-World Enum Examples ===\n\n");

    // Using months enum
    printf("=== Calendar Months ===\n");
    Month currentMonth = OCTOBER;
    Month birthMonth = MARCH;

    printf("Current month: %s (value: %d)\n", getMonthName(currentMonth), currentMonth);
    printf("Birth month: %s (value: %d)\n", getMonthName(birthMonth), birthMonth);

    // Loop through all months
    printf("\nAll months:\n");
    for (Month m = JANUARY; m <= DECEMBER; m++) {
        printf("%2d: %s\n", m, getMonthName(m));
    }

    // Using grade enum
    printf("\n=== Student Grades ===\n");
    int scores[] = {45, 75, 95, 82, 38};
    int numScores = sizeof(scores) / sizeof(scores[0]);

    for (int i = 0; i < numScores; i++) {
        Grade grade;

        if (scores[i] >= 85) {
            grade = EXCELLENT;
        } else if (scores[i] >= 60) {
            grade = PASSED;
        } else {
            grade = FAILED;
        }

        printf("Score %d: ", scores[i]);
        switch(grade) {
            case FAILED:
                printf("FAILED ❌\n");
                break;
            case PASSED:
                printf("PASSED ✅\n");
                break;
            case EXCELLENT:
                printf("EXCELLENT 🌟\n");
                break;
        }
    }

    // Using direction enum
    printf("\n=== Navigation Directions ===\n");
    Direction directions[] = {NORTH, EAST, SOUTH, WEST};
    const char* dirNames[] = {"North", "East", "South", "West"};

    for (int i = 0; i < 4; i++) {
        printf("%s: %d degrees\n", dirNames[i], directions[i]);
    }

    // Enum comparison and logic
    printf("\n=== Enum Logic Examples ===\n");
    Direction facing = NORTH;

    printf("Currently facing: %s\n",
           (facing == NORTH) ? "North" :
           (facing == EAST) ? "East" :
           (facing == SOUTH) ? "South" : "West");

    // Turn right (add 90 degrees)
    Direction newDirection = (facing + 90) % 360;
    if (newDirection == 90) newDirection = EAST;

    printf("After turning right: %s\n",
           (newDirection == EAST) ? "East" : "Unknown");

    // Season determination using month enum
    printf("\n=== Seasons Based on Month ===\n");
    Month testMonths[] = {JANUARY, APRIL, JULY, OCTOBER};

    for (int i = 0; i < 4; i++) {
        Month m = testMonths[i];
        printf("%s is in ", getMonthName(m));

        if (m == DECEMBER || m == JANUARY || m == FEBRUARY) {
            printf("Winter ❄️\n");
        } else if (m >= MARCH && m <= MAY) {
            printf("Spring 🌸\n");
        } else if (m >= JUNE && m <= AUGUST) {
            printf("Summer ☀️\n");
        } else {
            printf("Autumn 🍂\n");
        }
    }

    return 0;
}
