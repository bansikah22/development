#include <stdio.h>

/*
C Enums
An enum is a special type that represents a group of constants (unchangeable values).

To create an enum, use the enum keyword, followed by the name of the enum, and separate the enum items with a comma:

enum Level {
  LOW,
  MEDIUM,
  HIGH
};
*/

// Online C compiler to run C program online


enum Level{
    LOW = 1,
    MEDIUM = 2,
    HIGHT = 3
};

int main() {
 enum Level mylevel = MEDIUM;

 switch(mylevel){
     case 1:
     printf("Height level 1");
     break;
     case 2:
     printf("Height level 2");
     break;
     case 3:
     printf("Height level 1");
     break;
     default:
     printf("Height not found");

 }
 return 0;

}


