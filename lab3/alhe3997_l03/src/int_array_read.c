/**
 * -------------------------------------
 * @file  int_array_read.c
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

void int_array_read(int *array, int size) {
    char input[100];
    int num, index = 0;
    
    printf("Enter %d values for an array of int.\n", size);
    while (index < size) {
        printf("Value for index %d: ", index);
        if (fgets(input, sizeof(input), stdin) &&
            sscanf(input, "%d", &num) == 1) {
            array[index++] = num;
        } else {
            printf("Not a valid integer\n");
        }
    }
}
