#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS (200)

#define HEAP_FULL(n) ((n) == (MAX_ELEMENTS-1))
#define HEAP_EMPTY(n) (!(n))


typedef struct maxheap* MaxHeap;
typedef struct entry*   Entry;

struct entry{
	unsigned int key;
};

struct maxheap{
	Entry        head;
	unsigned int size;
	int     (*insert)(MaxHeap , Entry );
    int     (*del)(MaxHeap heap, Entry entry);
};	

#endif
