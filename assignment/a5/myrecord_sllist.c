/*
--------------------------------------------------
Project: a5q1
File:    myrecord_sllist.c
Author:  Mehdi Al-heloo
Version: 2025-02-14
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

  
  /**
   * Search singly linked list by the key name.
   * 
   * @param SLL *sllp - provides the address of a singly linked list structure.
   * @param char *name - key to search
   * @return Pointer to found node if found; otherwise NULL
   */
  NODE *sll_search(SLL *sllp, char *name) {

    NODE *current = sllp->start;

    while (current != NULL) {

        if (strcmp(current->data.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
  /**
   * Insert a new record to linked list at the position sorted by record name field.
   *
   * @param SLL *sllp - provides the address of a singly linked list structure.
   * @param char *name - name field of the new record.
   * @param float score - the score data of the new record.
   */
  void sll_insert(SLL *sllp, char *name, float score) {

    NODE *newNode = malloc(sizeof(NODE));

    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->data.name, name);
    newNode->data.score = score;
    newNode->next = NULL;

    NODE **tracer = &sllp->start;

    while (*tracer && strcmp((*tracer)->data.name, name) < 0) {
        tracer = &(*tracer)->next;
    }

    newNode->next = *tracer;
    *tracer = newNode;
    sllp->length++;
}
  /**
   * Delete a node of record matched by the name key from linked list.
   * 
   * @param SLL *sllp provides the address of a singly linked list structure.
   * @param name - key used to find the node for deletion. 
   * @return 1 if deleted a matched node, 0 otherwise. 
   */
  int sll_delete(SLL *sllp, char *name) {

    NODE **tracer = &sllp->start;

    while (*tracer) {

        if (strcmp((*tracer)->data.name, name) == 0) {
            NODE *temp = *tracer;
            *tracer = (*tracer)->next;
            free(temp);
            sllp->length--;
            
            return 1;
        }
        tracer = &(*tracer)->next;
    }
    return 0;
}
  /**
   * Clean singly linked list, delete all nodes. 
   * @param @param SLL *sllp provides the address of a singly linked list structure.
   */
  void sll_clean(SLL *sllp) {

    NODE *current = sllp->start;

    while (current) {
        NODE *next = current->next;
        free(current);
        current = next;
    }

    sllp->start = NULL;
    sllp->length = 0;
}