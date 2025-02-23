/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Mehdi Al-heloo, 169063997, alhe3997@mylaurier.ca
 *
 * @version 2025-02-07
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {

    for (int i = 0; i < data->lines; i++) {

        if (strstr(data->strings[i], substr)) {
            printf("%s\n", data->strings[i]);  
        }
    }
}
