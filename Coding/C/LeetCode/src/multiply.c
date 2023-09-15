/***
 * TODO:
 * Write an emebdded C function to multiply numbers quickly
 * without the use of time consuming multiplication or divison operators
*/
#include <stdlib.h>
#include <stdio.h>
#include "test.h"


// Multiply the given integer without using * by 9
// Answer: Using a bitwise shift, we can mutiply the number by 8, then add it to itself again.
//         The end result is the number becoming multiplied by 9.
// Runtime: O(1) - Constant operation no matter the size of int
int multiply(int x) {
    int flip = 0;
    if (x < 0) {
        flip = 1;
        x = ~x + 1; // two's compliment
    }
    x = (x << 3) + x;

    // If we flipped the sign originally, we now need to unflip it
    if (flip) {
        return ~x + 1;
    } else {
        return x;
    }
}

// Instead of only multiplying by 9, multiply by a given factor,
// without using '*', '%' or '/' in the fastest manner possible.
// Answer: If the factor is not constant, then the number of operations we do 
//         will scale with the factor.
// Runtime: O(factor) - The loop is as long as the factor argument
int multiplyBy(int x, int factor){
    if (factor == 0) {
        return 0;
    }

    // If the signs are negative, we need to make them positive for the calculation
    int flip = 0;
    if (x < 0) {
        flip = ~flip;
        x = ~x + 1; // two's compliment
    }
    if (factor < 0) {
        flip = ~flip;
        factor = ~factor + 1; // two's compliment
    }

    // The "multiplication" is handled by performing repeated addition
    int sum = 0;
    for (int i = 0; i < factor; i++) {
        sum = sum + x;
    }

    // If we flipped the sign originally, we now need to unflip it
    if (flip) {
        return ~sum + 1;
    } else {
        return sum;
    }
}


int main() {
    // Tests for multiply (by 9)
    assertEquals(multiply(3), 27);
    assertEquals(multiply(1), 9);
    assertEquals(multiply(0), 0);
    assertEquals(multiply(9), 81);
    assertEquals(multiply(-3), -27);
    assertEquals(multiply(-9), -81);
    assertEquals(multiply(-1), -9);

    // Tests for multiplyBy
    assertEquals(multiplyBy(3, 3), 9);
    assertEquals(multiplyBy(3, 1), 3);
    assertEquals(multiplyBy(3, 0), 0);
    assertEquals(multiplyBy(3, 2), 6);
    assertEquals(multiplyBy(-3, 2), -6);
    assertEquals(multiplyBy(3, -1), -3);
    assertEquals(multiplyBy(-3, -2), 6);
    assertEquals(multiplyBy(-1, -1), 1);
}
