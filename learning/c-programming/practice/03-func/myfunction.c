#include <stdio.h>

//Functions that takes name and age of a person and displays the name and age
void getNameAge(char name[], int age){
    printf("Your name is: %s , and your age is: %d\n", name, age);
}

//Functions to calculate two numbers & with return type int
int calculateSum(int x, int y){
    printf("The sum of %d + %d is: ", x, y);
    return x + y;
}


int main() {
   getNameAge("Noel",22);
   int sum = calculateSum(2,3);
   printf("%d", sum);
    return 0;
}


