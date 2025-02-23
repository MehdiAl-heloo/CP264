/*
--------------------------------------------------
Project: a3q1
File:    mystring.c
Author:  Mehdi Al-heloo
Version: 2025-01-31
--------------------------------------------------
*/

#include <stdio.h>
#include <ctype.h>

/**
 * Count the number words of a given simple string. A word starts with an English character 
 * and ends with a character of space, tab, comma, or period.
 *
 * @param s - char pointer to a string
 * @return - return the number of words.
 */
int str_words(char *s) {

    int count = 0;
    int word = 0;
    
    while (*s) {

        if ((isalpha(*s) && !word)) {
            word = 1;
            count++;
        }
        if ((*s == ' ' || *s == '\t' || *s == ',' || *s == '.') && word) {
            word = 0;
        }
        s++;
    }

    return count;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {

    int count = 0;

    while (*s) {

        if (isupper(*s)) {
            *s = tolower(*s);
            count++;
        }
        s++;
    }

    return count;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s) {

    char *d = s;  
    int space = 0;

    while (*s) {

        if (!isspace(*s)) {
            if (space) {
                *d++ = ' ';  
                space = 0;
            }
            *d++ = *s;  
        } 
        else {

            if (!space) {
                space = 1;  
            }
        }
        s++;
    }
    
    if (d > s && isspace(*(d - 1))) {  
        d--;
    }
    
    *d = '\0'; 
}