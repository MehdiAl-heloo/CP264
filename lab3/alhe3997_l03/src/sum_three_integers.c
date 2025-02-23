/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
#include <stdio.h>

int sum_three_integers(void) {
    int a, b, c, result;
    char input[100];
    
    while (1) {
        printf("Enter three comma-separated integers: ");
        if (fgets(input, sizeof(input), stdin) &&
            sscanf(input, "%d,%d,%d", &a, &b, &c) == 3) {
            result = a + b + c;
            break;
        } else {
            printf("The integers were not properly entered.\n");
        }
    }
    return result;
}
