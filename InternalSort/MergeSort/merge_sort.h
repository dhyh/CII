#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <stdio.h>

#define MAX_SIZE (10)

void merge_sort(int list[], int n);
void merge_pass(int list[], int sort[], int n, int length);
void merge(int list[], int sort[], int i, int m, int n);

#endif
