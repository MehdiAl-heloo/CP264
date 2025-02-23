/*
--------------------------------------------------
Project: a5q2
File:    dllist.c
Author:  Mehdi Al-heloo
Version: 2025-02-14
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

/*
 * Create and return a new node using malloc() with passed data value and returns pointer of the node.
*/
NODE *dll_node(char value) {

    NODE *newNode = (NODE *)malloc(sizeof(NODE));

    if (newNode) {
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

/*
 * Insert a given node at the beginning the of a doubly linked list. 
 * @param DLL *dllp -  reference to input DLL variable 
 * @param NODE *np  -  reference of a NODE node to be inserted
*/
void dll_insert_start(DLL *dllp, NODE *np) {

    if (dllp->start == NULL) { 
        dllp->start = dllp->end = np;
        np->prev = np->next = NULL;

    } 
    else { 
        np->next = dllp->start;
        np->prev = NULL;
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
}
/*
 * Insert a node at the end of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable 
 * @param NODE *np  -  reference of a NODE node to be inserted
*/
void dll_insert_end(DLL *dllp, NODE *np) {

    if (dllp->end == NULL) { 
        dllp->start = dllp->end = np;
        np->prev = np->next = NULL;
    } 
    else { 
        np->prev = dllp->end;
        np->next = NULL;
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
}
/*
 * This deletes the first node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable 
*/
void dll_delete_start(DLL *dllp) {

    if (dllp->start == NULL) return;

    NODE *temp = dllp->start;

    if (dllp->start == dllp->end) { 
        dllp->start = dllp->end = NULL;
    } 
    else {
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }
    free(temp);
    dllp->length--;
}
/*
 * Delete the end node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable  
*/
void dll_delete_end(DLL *dllp) {

    if (dllp->end == NULL) return; 

    NODE *temp = dllp->end;

    if (dllp->start == dllp->end) { 
        dllp->start = dllp->end = NULL;
    } 
    else {
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }
    free(temp);
    dllp->length--;
}
/*
 * Clean and free the nodes of a doubly linked list and reset start and length.
 * @param DLL *dllp -  reference to input DLL variable 
*/
void dll_clean(DLL *dllp) {

    NODE *current = dllp->start;

    while (current != NULL) {
        NODE *next = current->next;
        free(current);
        current = next;
    }
    dllp->start = dllp->end = NULL;
    dllp->length = 0;
}