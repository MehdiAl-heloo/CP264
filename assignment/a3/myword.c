/*
--------------------------------------------------
Project: a3q2
File:    myword.c
Author:  Mehdi Al-heloo
Version: 2025-01-31
--------------------------------------------------
*/

#include "myword.h"
#include "mystring.h"  
#include <string.h>
#include <stdlib.h>

/*
 * Define enumeration type BOOLEAN with value FALSE = 0 and TRUE 1.
 */

/*
 * Define structure type WORD consists of char word[20] to store a word, int count to hold frequency of the word.
 */

/*
 * Define structure type WORDSTATS consisting of int line_count, int word_count, and int keyword_count to represent
 * to represent the number of lines, number of all words, and the number of different non-common-word in text data.
 */


/*
 * Load word data from file, and insert words a directory represented by char array.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictionary) {

    char buffer[1024];
    int count = 0;
    dictionary[0] = '\0'; 

    while (fgets(buffer, sizeof(buffer), fp)) {
        str_trim(buffer);
        str_lower(buffer);
        char *token = strtok(buffer, " \n\t\r.,;");

        while (token != NULL) {
            char temp[1024];
            sprintf(temp, " %s ", dictionary);
            char search[50];
            sprintf(search, " %s ", token);

            if (!strstr(temp, search)) { 
                
                if (strlen(dictionary) > 0) {
                    strcat(dictionary, " ");
                }
                strcat(dictionary, token);
                count++;
            }
            token = strtok(NULL, " \n\t\r.,;");
        }
    }
    return count;
}

/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word) {

    char search[1024];
    sprintf(search, " %s ", word);  

    char temp[2048];
    sprintf(temp, " %s ", dictionary); 

    return strstr(temp, search) ? TRUE : FALSE;
}
/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {

    WORDSTATS stats = {0, 0, 0};
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp)) {
        stats.line_count++;
        str_trim(buffer);  
        str_lower(buffer); 
        char *token = strtok(buffer, " \n\t\r.,;");

        while (token) {
            stats.word_count++;

            if (!contain_word(dictionary, token)) {
                int found = FALSE;

                for (int i = 0; i < stats.keyword_count; i++) {

                    if (strcmp(words[i].word, token) == 0) {
                        words[i].count++;
                        found = TRUE;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[stats.keyword_count].word, token);
                    words[stats.keyword_count].count = 1;
                    stats.keyword_count++;
                }
            }
            token = strtok(NULL, " \n\t\r.,;");
        }
    }
    
    return stats;
}