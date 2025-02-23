/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
#include <stdio.h>

int sum_integers(void) {
    int sum = 0, num;
    char input[100];
    
    printf("Enter integers, one per line:\n");
    while (fgets(input, sizeof(input), stdin)) {
        if (sscanf(input, "%d", &num) == 1) {
            sum += num;
        } else {
            break;
        }
    }
    return sum;
}