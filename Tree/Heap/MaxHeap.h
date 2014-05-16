#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (20)


typedef struct maxheap* MaxHeap;
typedef struct entry*   Entry;

struct entry{
	unsigned int key;
};

struct maxheap{
	MaxHeap create(unsigned int );
	int     heapfull(MaxHeap , unsigned int);
	int     heapempty(MaxHeap );
	MaxHeap insert(MaxHeap , Entry , unsigned int);
	Entry   delet(MaxHeap , unsigned int);
};	

#endif
