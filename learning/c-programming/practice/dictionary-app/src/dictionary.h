#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_WORDS 100
#define WORD_LEN 50
#define MEANING_LEN 100

struct Dictionary {
    char word[WORD_LEN];
    char meaning[MEANING_LEN];
};

// Function declarations
void addWord(struct Dictionary dict[], int *count);
void searchWord(struct Dictionary dict[], int count);
void displayAll(struct Dictionary dict[], int count);

#endif
