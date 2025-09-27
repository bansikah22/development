#include <stdio.h>
#include <stdlib.h>

// Function declarations for later examples
void swap(int *a, int *b);
void doubleValue(int *num);
void printArray(int *arr, int size);

int main() {
    printf("🎯 WELCOME TO POINTERS IN C! 🎯\n");
    printf("===============================\n\n");

    // 📮 WHAT ARE POINTERS? (Like house addresses)
    printf("📮 1. WHAT ARE POINTERS? (Like house addresses)\n");
    printf("----------------------------------------------\n");

    int age = 25;           // This is like John living at a house
    int *agePtr = &age;     // This is like knowing John's address

    printf("John (age) lives at house and is %d years old\n", age);
    printf("John's address is: %p\n", (void*)&age);
    printf("I have John's address written down: %p\n", (void*)agePtr);
    printf("If I go to that address, I find: %d years old\n", *agePtr);
    printf("\n");

    // 🔍 THE TWO MAGIC SYMBOLS (& and *)
    printf("🔍 2. THE TWO MAGIC SYMBOLS\n");
    printf("-------------------------\n");

    int score = 100;

    printf("Score value: %d\n", score);
    printf("& gives ADDRESS: %p\n", (void*)&score);

    int *scorePtr = &score;
    printf("Pointer holds address: %p\n", (void*)scorePtr);
    printf("* gets VALUE at address: %d\n", *scorePtr);
    printf("\n");

    // 🎮 CHANGING VALUES WITH POINTERS (Like remote control)
    printf("🎮 3. CHANGING VALUES WITH POINTERS (Like remote control)\n");
    printf("--------------------------------------------------------\n");

    int tvVolume = 10;
    int *remote = &tvVolume;

    printf("TV volume before using remote: %d\n", tvVolume);

    *remote = 25;  // Use the remote to change TV!
    printf("After using remote, TV volume: %d\n", tvVolume);

    // Increase volume through remote
    *remote = *remote + 5;
    printf("After turning up volume: %d\n", tvVolume);
    printf("\n");

    // 🏃‍♂️ POINTER ARITHMETIC (Moving through memory)
    printf("🏃‍♂️ 4. POINTER ARITHMETIC (Moving through houses)\n");
    printf("-----------------------------------------------\n");

    int houses[] = {101, 102, 103, 104, 105};  // House numbers on a street
    int *mailman = houses;  // Mailman starts at first house

    printf("Street addresses: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", houses[i]);
    }
    printf("\n");

    printf("Mailman is at house: %d\n", *mailman);

    mailman++;  // Move to next house
    printf("Mailman moves to next house: %d\n", *mailman);

    mailman += 2;  // Skip 2 houses ahead
    printf("Mailman skips 2 houses ahead: %d\n", *mailman);

    mailman--;  // Go back one house
    printf("Mailman goes back one: %d\n", *mailman);
    printf("\n");

    // 🔄 POINTERS AND FUNCTIONS (Giving someone your house key)
    printf("🔄 5. POINTERS AND FUNCTIONS (Giving house keys)\n");
    printf("----------------------------------------------\n");

    int myNumber = 5;
    printf("My number before doubling: %d\n", myNumber);

    doubleValue(&myNumber);  // Give function my address (house key)
    printf("My number after doubling: %d\n", myNumber);
    printf("\n");

    // 🔀 SWAPPING VALUES (Trading toys)
    printf("🔀 6. SWAPPING VALUES (Trading toys)\n");
    printf("---------------------------------\n");

    int toy1 = 10, toy2 = 20;
    printf("Before trading: toy1=%d, toy2=%d\n", toy1, toy2);

    swap(&toy1, &toy2);  // Trade toys using their addresses
    printf("After trading: toy1=%d, toy2=%d\n", toy1, toy2);
    printf("\n");

    // 📊 ARRAYS AND POINTERS (Secret connection!)
    printf("📊 7. ARRAYS AND POINTERS (Secret connection!)\n");
    printf("---------------------------------------------\n");

    int numbers[] = {10, 20, 30, 40, 50};

    printf("Using normal array way:\n");
    printf("numbers[0] = %d, numbers[2] = %d\n", numbers[0], numbers[2]);

    printf("Using pointer way (same result!):\n");
    printf("*numbers = %d, *(numbers+2) = %d\n", *numbers, *(numbers+2));

    // Print array using pointer
    printf("Printing array with pointer: ");
    printArray(numbers, 5);
    printf("\n");

    // 🏗️ DYNAMIC MEMORY (Building houses while running)
    printf("🏗️ 8. DYNAMIC MEMORY (Building houses while running)\n");
    printf("--------------------------------------------------\n");

    int howMany;
    printf("How many numbers do you want to store? ");
    scanf("%d", &howMany);

    // Build exactly the right number of houses!
    int *dynamicArray = (int*)malloc(howMany * sizeof(int));

    if (dynamicArray != NULL) {
        printf("Built %d houses! Filling them with numbers...\n", howMany);

        // Fill the houses with numbers
        for(int i = 0; i < howMany; i++) {
            dynamicArray[i] = (i + 1) * 10;
        }

        // Show what's in each house
        printf("Houses contain: ");
        for(int i = 0; i < howMany; i++) {
            printf("%d ", dynamicArray[i]);
        }
        printf("\n");

        // Give the houses back when done (very important!)
        free(dynamicArray);
        dynamicArray = NULL;
        printf("Houses returned to the city! 🏠➡️🏛️\n");
    } else {
        printf("Sorry, no houses available! 😞\n");
    }
    printf("\n");

    // ⭕ NULL POINTERS (Empty addresses)
    printf("⭕ 9. NULL POINTERS (Empty addresses)\n");
    printf("----------------------------------\n");

    int *emptyAddress = NULL;
    printf("Empty address contains: %p\n", (void*)emptyAddress);

    // Always check before using!
    if (emptyAddress != NULL) {
        printf("Safe to visit: %d\n", *emptyAddress);
    } else {
        printf("Address is empty - can't visit! 🚫\n");
    }
    printf("\n");

    // 🧠 POINTER ANALOGIES (Easy ways to remember)
    printf("🧠 10. POINTER ANALOGIES (Easy ways to remember)\n");
    printf("----------------------------------------------\n");

    int temperature = 72;
    int *thermostat = &temperature;

    printf("🌡️  THERMOSTAT ANALOGY:\n");
    printf("   Room temperature: %d°F\n", temperature);
    printf("   Thermostat points to room at address: %p\n", (void*)thermostat);
    printf("   Using thermostat to check temp: %d°F\n", *thermostat);

    *thermostat = 75;  // Change temperature with thermostat
    printf("   After adjusting thermostat: %d°F\n", temperature);
    printf("\n");

    // 📚 LIBRARY BOOK ANALOGY
    printf("📚 LIBRARY ANALOGY:\n");
    int bookPages = 250;
    int *callNumber = &bookPages;

    printf("   Book has %d pages\n", bookPages);
    printf("   Call number (address): %p\n", (void*)callNumber);
    printf("   Following call number finds book with: %d pages\n", *callNumber);
    printf("\n");

    // 🚨 COMMON MISTAKES TO AVOID
    printf("🚨 11. COMMON MISTAKES TO AVOID\n");
    printf("------------------------------\n");

    printf("❌ DON'T DO THESE:\n");
    printf("   int *badPtr;           // Uninitialized pointer!\n");
    printf("   *badPtr = 10;          // CRASH! 💥\n");
    printf("\n");

    printf("✅ DO THIS INSTEAD:\n");
    int safeNumber = 0;
    int *goodPtr = &safeNumber;  // Always point to something real!
    *goodPtr = 10;
    printf("   Safe pointer usage: %d\n", *goodPtr);
    printf("\n");

    // 🎯 REAL WORLD EXAMPLE (Student grades)
    printf("🎯 12. REAL WORLD EXAMPLE (Student grade manager)\n");
    printf("-----------------------------------------------\n");

    int studentGrade = 85;
    int *gradePtr = &studentGrade;

    printf("Student's original grade: %d\n", *gradePtr);

    // Teacher adds 5 bonus points
    *gradePtr += 5;
    printf("After bonus points: %d\n", studentGrade);

    // Check if passing (using pointer)
    if (*gradePtr >= 70) {
        printf("Student is PASSING! 🎉\n");
    } else {
        printf("Student needs help 📚\n");
    }
    printf("\n");

    // 🎓 SUMMARY
    printf("🎓 REMEMBER THESE KEY POINTS:\n");
    printf("============================\n");
    printf("• & = 'Address of' (where something lives)\n");
    printf("• * = 'Value at' (go to address and look inside)\n");
    printf("• Always initialize pointers before using\n");
    printf("• Check for NULL before dereferencing\n");
    printf("• Free malloc'd memory when done\n");
    printf("• Pointers are like addresses to houses! 🏠\n");
    printf("\n");

    printf("🎉 Great job learning pointers! 🎉\n");
    printf("Pointers help you efficiently manage memory and change values!\n");

    return 0;
}

// 🔄 Function to double a value using pointer
void doubleValue(int *num) {
    printf("  Function received address: %p\n", (void*)num);
    printf("  Value at that address: %d\n", *num);

    *num = *num * 2;  // Change the original value!

    printf("  Doubled the value to: %d\n", *num);
}

// 🔀 Function to swap two values using pointers
void swap(int *a, int *b) {
    printf("  Swapping values at addresses %p and %p\n", (void*)a, (void*)b);

    int temp = *a;    // Save first value in temporary box
    *a = *b;          // Put second value in first box
    *b = temp;        // Put saved value in second box

    printf("  Swap complete!\n");
}

// 📊 Function to print array using pointer
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));  // Use pointer arithmetic!
    }
    printf("\n");
}
