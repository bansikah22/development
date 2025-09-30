#include <stdio.h>
/*
// Without typedef
enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};
enum Day today = WED;

// With typedef
typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} Day;
Day today = WED;
*/



typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} Day;

int main() {
  Day today = WED;
  if (today == WED) {
    printf("It is Wednesday!\n");
  }
  return 0;
}