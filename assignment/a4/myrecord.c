/*
--------------------------------------------------
Project: a4q2
File:    myrecord.c
Author:  Mehdi Al-heloo
Version: 2025-02-07
--------------------------------------------------
*/

#include "myrecord.h"
#include "mysort.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 * Define a structure named RECORD to hold a person's name of 20 characters and 
 * the score of float type.
*/

/*
 * Define a structure named STATS containing fields: int count, float mean, 
 * loat stddev (standard deviation), and float median.
*/

/*
 * Define a structure named GRADE to hold a string letter_grade at most 2 letters. 
*/

/*
 * Convert a percentage grade to letter grade defined by percentage ranges
 * A+=[90, 100], A=[85, 90), A-=[80, 85), B+=[77, 80), B=[73, 77) B=[70, 73),
 * C+=[67, 70), C=[63, 77), C-=[60, 63), D+=[57,60),D=[53,57),D=[50,53), F=[0,50).
 *
 * @param score -  percetage grade.
 *
 * @return - letter grade wrapped in GRADE structure type.
 */
GRADE grade(float score) {

    GRADE result;

    if (score >= 90) strcpy(result.letter_grade, "A+");
    else if (score >= 85) strcpy(result.letter_grade, "A");
    else if (score >= 80) strcpy(result.letter_grade, "A-");
    else if (score >= 77) strcpy(result.letter_grade, "B+");
    else if (score >= 73) strcpy(result.letter_grade, "B");
    else if (score >= 70) strcpy(result.letter_grade, "B-");
    else if (score >= 67) strcpy(result.letter_grade, "C+");
    else if (score >= 63) strcpy(result.letter_grade, "C");
    else if (score >= 60) strcpy(result.letter_grade, "C-");
    else if (score >= 57) strcpy(result.letter_grade, "D+");
    else if (score >= 53) strcpy(result.letter_grade, "D");
    else if (score >= 50) strcpy(result.letter_grade, "D-");
    else strcpy(result.letter_grade, "F");

    return result;
}


/*
 *  Import record data from file and store name and store all record entries
 *  in the RECORD array passed by records, return the number of record count.
 *
 *  @param *fp -  FILE pointer to intput file.
 *  @param dataset - array of RECODR type to store record data.
 *  @return   - number of records
 */
int import_data(FILE *fp, RECORD *dataset) {

    char buffer[256];
    int count = 0;

    while (fgets(buffer, 256, fp) != NULL) {
        sscanf(buffer, "%20[^,],%f", dataset[count].name, &dataset[count].score);
        count++;
    }

    return count;
}

/*
 *  Take the RECORD data array as input, compute the average score, standard deviation,
 *  median of the score values of the record data, and returns the STATS type value.
 *
 *  @param dataset -  input record data array.
 *  @param count -  the number of data record in dataset array.
 *  @return  -  stats value in STATS type.
 */
STATS process_data(RECORD *dataset, int count) {
    
    STATS stats;
    stats.count = count;
    float sum = 0, sum_sq = 0;

    for (int i = 0; i < count; i++) {
        sum += dataset[i].score;
        sum_sq += dataset[i].score * dataset[i].score;
    }

    stats.mean = sum / count;
    stats.stddev = sqrt((sum_sq / count) - (stats.mean * stats.mean));


    if (count % 2 == 0) {
        stats.median = (dataset[(count / 2) - 1].score + dataset[count / 2].score) / 2.0;
    } else {
        stats.median = dataset[count / 2].score;
    }

    return stats;
}

/*
 *  This function takes output file named outfilename, RECORD array records, 
 *  and stats as inputs, prepare and write report of stats and grade to files.
 *  The records in report file are sorted in decreasing of scores.  
 *
 *  @param *fp -  FILE pointer to output file.
 *  @param *dataset - pointer to dataset array.
 *  @param stats - the stats value to be used in report.
 *  @return - returns 1 if successful; 0 if count < 1
 */
int report_data(FILE *fp, RECORD *dataset, STATS stats) {

    if (stats.count < 1) return 0;

    for (int i = 0; i < stats.count - 1; i++) {

        for (int j = 0; j < stats.count - i - 1; j++) {

            if (dataset[j].score < dataset[j + 1].score) {
                RECORD temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }

    fprintf(fp, "stats:value\n");
    fprintf(fp, "count:%d\n", stats.count);
    fprintf(fp, "mean:%.1f\n", stats.mean);
    fprintf(fp, "stddev:%.1f\n", stats.stddev);
    fprintf(fp, "median:%.1f\n\n", stats.median);

    fprintf(fp, "name:score,grade\n"); 

    for (int i = 0; i < stats.count; i++) {
        GRADE g = grade(dataset[i].score);
        fprintf(fp, "%s:%.1f,%s\n", dataset[i].name, dataset[i].score, g.letter_grade);
    }

    return 1;
}