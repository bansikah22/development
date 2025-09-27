#include <stdio.h>

/* You can start with very small projects that use simple input and output. For example, write a program that:

   Asks for your name
   Asks for your age
   Prints: Hi <name>! You will turn <age+1> next year.
*/

int age;
char name[100];

int main() {
printf("What is your name? ");
  scanf("%s", name);
  printf("What is your age? ");
  scanf("%d", &age);
  printf("Hi %s! You will turn %d next year.\n", name, age + 1);

  return 0;
}