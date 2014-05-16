#include "MaxHeap.h"

MaxHeap init_maxheap(unsigned int size)
{
	MaxHeap mhp = (MaxHeap )malloc(sizeof(struct maxheap));

	if (NULL == mhp)
		return NULL;

	return mhp;
}

MaxHeap create_maxheap(unsigned int size)
{
	return (MaxHeap )malloc(sizeof(struct entry));
}

int main(void)
{
	MaxHeap mhp = init_maxheap(MAX_SIZE);

	if (NULL == mhp)
		return 0x00;


	return 0x00;
}
