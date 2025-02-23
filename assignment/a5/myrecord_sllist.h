/*
--------------------------------------------------
Project: a5q1
File:    myrecord_sllist.h
Author:  Mehdi Al-heloo
Version: 2025-02-14
--------------------------------------------------
*/

#ifndef MYRECORD_SLLIST_H
#define MYRECORD_SLLIST_H

/**
 * RECORD structure
 * name  - char array for person's name
 * score - float score of record
 */
typedef struct {
    char name[20];
    float score;
  } RECORD;
  
  /**
   * NODE structure
   * data  - RECORD data
   * next  - pointer pointing to the next node of singly linked list
   */
  typedef struct node {
    RECORD data;
    struct node *next;
  } NODE;
  
  /**
   * Singly linked list structure
   * int length  - the number of nodes of the linked list
   * NODE *start - pointer pointing to the first node of the linked list
   */
  typedef struct sllist {
    int length;
    NODE *start;
  } SLL;
  

NODE *sll_search(SLL *sllp, char *name);
void sll_insert(SLL *sllp, char *name, float score);
int sll_delete(SLL *sllp, char *name);
void sll_clean(SLL *sllp);

#endif