#include <stdio.h>
#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()

int main() {
    int secret, guess;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 10
    secret = rand() % 10 + 1;

    printf("=== Guess the Number Game ===\n");
    printf("I'm thinking of a number between 1 and 10.\n");

    // Ask the user to guess
    printf("Enter your guess: ");
    scanf("%d", &guess);

    // Compare guess with secret number
    if (guess == secret) {
        printf(" Congratulations! You guessed it right! The number was %d.\n", secret);
    } else {
        printf(" Sorry, that's not correct. The number was %d.\n", secret);
    }

    return 0;
}
