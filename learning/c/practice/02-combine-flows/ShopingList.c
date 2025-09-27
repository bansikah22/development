#include <stdio.h>

/*
Once you are comfortable, try slightly bigger projects that combine loops, conditions, and arrays:

  - Create a small shopping list program (store items and print them)
  - Guess a Number Game
  - Calculate a Student's Average
*/


int main()
{
// Create a small shopping list program (store items and print them)
    char items[10][100] = {
        "apple", "banana", "orange", "grape", "mango",
        "watermelon", "strawberry", "pineapple", "peach", "cherry"
    };

    printf("The items in the list are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, items[i]);
    }

//  Guess a Number Game


//  Calculate a Student's Average'

}