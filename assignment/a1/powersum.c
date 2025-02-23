/*
--------------------------------------------------
Project: a1q2
File:    powersum.c
Author:  Mehdi Al-heloo
Version: 2025-01-17
--------------------------------------------------
*/
#include "powersum.h"
#include <ctype.h> 
#include <limits.h>

/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n) {
    
    if (n < 0) {
        return 0;
    }
    else if (b == 0){
        return 0;
    }
    else if (n == 0 || b ==1) {
        return 0;
    }
    else {
        int result = 1;
        for (int i = 0; i < n; i++) {
            if (b > 0 && result > INT_MAX / b) { // Check for positive overflow
                return 1;
            }
            if (b < 0 && result < INT_MIN / b) { // Check for negative overflow
                return 1;
            }
            result *= b;
        }
        return 0;
    }

}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n){

    if (power_overflow(b, n)) {
        return 0;  // Overflow detected, return 0
    }
    else {
        int result = 1;
        for (int i = 0; i < n; i++) {
            result *= b;
        }
        return result;
    }

}

/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n) {
    if (n < 0) {
        // Negative exponents do not make sense in the context of this summation
        return 0;
    }

    int sum = 0;
    int current_power;
    for (int i = 0; i <= n; i++) {
        if (power_overflow(b, i)) {
            return 0;  // If overflow is detected in calculating power, return 0
        }
        current_power = mypower(b, i);  // Safe to calculate power if no overflow
        if (sum > INT_MAX - current_power) {  // Check for overflow in the summation
            return 0;
        }
        sum += current_power;
    }
    return sum;

}