#include <stdio.h>
#include "dictionary.h"

int main() {
    struct Dictionary dict[MAX_WORDS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Add Word\n");
        printf("2. Search Word\n");
        printf("3. Display All\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWord(dict, &count);
                break;
            case 2:
                searchWord(dict, count);
                break;
            case 3:
                displayAll(dict, count);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
