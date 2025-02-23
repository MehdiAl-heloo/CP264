/*
--------------------------------------------------
Project: a4q1
File:    mysort.c
Author:  Mehdi Al-heloo
Version: 2025-02-07
--------------------------------------------------
*/
#include "mysort.h"

static void swap(void **a, void **b) {
    void *temp = *a;
    *a = *b;
    *b = temp;
}

static int compare_ascending(void *a, void *b) {
    return (*(int*)a - *(int*)b);
}

static int compare_descending(void *a, void *b) {
    return (*(int*)b - *(int*)a);
}

/**
 * Use selection sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers.
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void select_sort(void *a[], int left, int right) {

    for (int i = left; i < right; i++) {
        int min_idx = i;

        for (int j = i + 1; j <= right; j++) {
            
            if (compare_ascending(a[j], a[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&a[i], &a[min_idx]);
        }
    }
}

/**
 * Use quick sort algorithm to sort array of pointers such that their pointed values 
 * are in increasing order.
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void quick_sort(void *a[], int left, int right) {

    if (left < right) {
        void *pivot = a[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {

            if (compare_ascending(a[j], pivot) < 0) {
                i++;
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[i + 1], &a[right]);
        quick_sort(a, left, i);
        quick_sort(a, i + 2, right);
    }
}
/**
 * Use either selection or quick sort algorithm to sort array of pointers such that their pointed values 
 * are in order defined by the given comparison function
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*)) {

    if (!cmp) {
        cmp = compare_descending; 
    }

    if (left < right) {
        void *pivot = a[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {

            if (cmp(a[j], pivot) < 0) {
                i++;
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[i + 1], &a[right]);
        my_sort(a, left, i, cmp);
        my_sort(a, i + 2, right, cmp);
    }
}