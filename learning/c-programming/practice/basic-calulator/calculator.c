#include <stdio.h>

int main() {
    int num1, num2;
    char operator;
       
    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);
        
    printf("Which operation will you like to perform (+, -, *, /): ");
    scanf(" %c", &operator);  

    switch(operator) {
        case '+':
            printf("The sum of %d + %d is: %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("The difference of %d - %d is: %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("The product of %d * %d is: %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Division by zero not possible\n");
            } else {
                printf("The division of %d / %d is: %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Please enter a valid operator (+, -, *, /)\n");
    }

    return 0;
}
