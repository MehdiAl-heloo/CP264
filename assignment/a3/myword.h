/*
--------------------------------------------------
Project: a3q2
File:    myword.h
Author:  Mehdi Al-heloo
Version: 2025-01-31
--------------------------------------------------
*/

#ifndef MYWORD_H
#define MYWORD_H
#include <stdio.h>

typedef enum { FALSE, TRUE } BOOLEAN;

typedef struct {
    char word[20];
    int count;
} WORD;

typedef struct {
    int line_count;
    int word_count;
    int keyword_count;
} WORDSTATS;

int create_dictionary(FILE *fp, char *dictionary);
BOOLEAN contain_word(char *dictionary, char *word);
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif