#include <stdio.h>


/*
C typedef
The typedef keyword lets you create a new name (an alias) for an existing type. This can make complex declarations easier to read, and your code easier to maintain.

For example, instead of always writing float, we can create a new type called Temperature to make the code clearer:
*/
//typedef struct {
//    int a;
//    int b;
//} MyStruct;
//
//int main() {
//    MyStruct s;
//    return 0;
//}

//typedef float Temperature;
//
//int main(){
//    Temperature today = 25.5;
//    Temperature tomorrow = 28.5;
//
//    printf("Temperature of today is: %2.lf\n", today);
//     printf("Temperature of tomorrow will be: %2.lf", tomorrow);
//
//}

// using typedef with structs

// Define three structs with typedef
typedef struct {
  char firstName[20];
  char lastName[20];
} Owner;

typedef struct {
  char brand[20];
  int year;
  Owner owner;
} Car;

typedef struct {
  char name[30];
  Car featuredCar;
} Dealership;

int main() {
  Owner person = {"John", "Doe"};
  Car car1 = {"Toyota", 2010, person};
  Dealership d = {"City Motors", car1};

  printf("Dealership: %s\n", d.name);
  printf("Featured Car: %s (%d), owned by %s %s\n",
    d.featuredCar.brand,
    d.featuredCar.year,
    d.featuredCar.owner.firstName,
    d.featuredCar.owner.lastName);

  return 0;
}



