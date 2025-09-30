#include <stdio.h>
#include <math.h>

/*
Math Functions
There is also a list of math functions available, that allows you to perform mathematical tasks on numbers.

To use them, you must include the math.h header file in your program:

#include <math.h>

Square Root
To find the square root of a number, use the sqrt() function:

Example
printf("%f", sqrt(16));

//Output: 4.000000

Round a Number
The ceil() function rounds a number upwards to its nearest integer, and the floor() method rounds a number downwards to its nearest integer, and returns the result:

Example
printf("%f", ceil(1.4));
printf("%f", floor(1.4));

Power
The pow() function returns the value of x to the power of y (xy):

Example
printf("%f", pow(4, 3));
*/

int main() {
//Square Root
printf("%f\n", sqrt(16));

//Round a Number
printf("%f\n", ceil(1.4));
printf("%f\n", floor(1.4));

//Power
printf("%f\n", pow(4, 3));

}
