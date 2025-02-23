/*
--------------------------------------------------
Project: a4q2
File:    myrecord.h
Author:  Mehdi Al-heloo
Version: 2025-02-07
--------------------------------------------------
*/

#ifndef MYRECORD_H
#define MYRECORD_H
#include <stdio.h>

typedef struct RECORD {
    char name[21];
    float score; 
} RECORD;

typedef struct STATS {
    int count;
    float mean; 
    float stddev;
    float median; 
} STATS;

typedef struct GRADE {
    char letter_grade[3]; 
} GRADE;

GRADE grade(float score);
int import_data(FILE *fp, RECORD *dataset);
STATS process_data(RECORD *dataset, int count);
int report_data(FILE *fp, RECORD *dataset, STATS stats);

#endif