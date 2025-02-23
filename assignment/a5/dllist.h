/*
--------------------------------------------------
Project: a5q2
File:    dllist.h
Author:  Mehdi Al-heloo
Version: 2025-02-14
--------------------------------------------------
*/

#ifndef DLLIST_H
#define DLLIST_H

/*
 * Define node structure NODE of a doubly linked list to hold a char data value. 
 */
typedef struct node {
    char data;
    struct node *prev;
    struct node *next;
} NODE;

/* 
 * Define a structure DLL to hold the length, start and end node addresses of a doubly linked list.
 */
typedef struct {
    int length;
    NODE *start;
    NODE *end;
} DLL;

NODE *dll_node(char value);
void dll_insert_start(DLL *dllp, NODE *np);
void dll_insert_end(DLL *dllp, NODE *np);
void dll_delete_start(DLL *dllp);
void dll_delete_end(DLL *dllp);
void dll_clean(DLL *dllp);

#endif