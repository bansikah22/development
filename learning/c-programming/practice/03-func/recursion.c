#include <stdio.h>
/*
Recursion is the technique of making a function call itself. This technique provides a way to break complicated problems down into simple problems which are easier to solve.

Recursion may be a bit difficult to understand. The best way to figure out how it works is to experiment with it.
*/
/* recursive function is a function that calls itself
Example
Adding two numbers together is easy to do, but adding a range of numbers is more complicated.
In the following example, recursion is used to add a range of numbers together by breaking it down into the simple task of adding two numbers:

*/
#include <stdio.h>

int sum(int k);

int main() {
  int result = sum(10);
  printf("%d", result);
  return 0;
}

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

//output: 55