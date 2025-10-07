#include <stdio.h>
#include <string.h>
#include "dictionary.h"

void addWord(struct Dictionary dict[], int *count) {
    if (*count >= MAX_WORDS) {
        printf("Dictionary is full!\n");
        return;
    }
    printf("Enter word: ");
    scanf(" %[^\n]", dict[*count].word);
    printf("Enter meaning: ");
    scanf(" %[^\n]", dict[*count].meaning);
    (*count)++;
    printf("Word added successfully!\n");
}

void searchWord(struct Dictionary dict[], int count) {
    char query[WORD_LEN];
    printf("Enter word to search: ");
    scanf(" %[^\n]", query);

    for (int i = 0; i < count; i++) {
        if (strcmp(dict[i].word, query) == 0) {
            printf("Meaning: %s\n", dict[i].meaning);
            return;
        }
    }
    printf("Word not found!\n");
}

void displayAll(struct Dictionary dict[], int count) {
    if (count == 0) {
        printf("No words in dictionary.\n");
        return;
    }
    printf("\n--- Dictionary Words ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, dict[i].word, dict[i].meaning);
    }
}
