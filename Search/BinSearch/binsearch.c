#include "binsearch.h"
#include <limits.h>

int binsearch(element list[], size_t size, size_t key)
{
	size_t middle = 0x00, right = size-1, left = 0x00;

	while(left <= right){
		middle = (right + left)/2;
		if (list[middle].key < key){
			left = middle+1;
		}else if (list[middle].key > key){
			if (0x00 == middle)	break;
			right = middle-1;
		}else if (list[middle].key == key){
			return middle;
		}
	}

	return (-1);
}


element list[MAX_SIZE];

#define LIST_SIZE (0x10)
int main(void)
{
	int idx = 0x00;
	for (; idx < LIST_SIZE; idx++){
		list[idx].key = idx*10+1;
	}

	printf("binsearch index : %d\n", binsearch(list, LIST_SIZE, 91));
	printf("binsearch index : %d\n", binsearch(list, LIST_SIZE, 0));
	printf("binsearch index : %d\n", binsearch(list, LIST_SIZE, -1));

	return 0x00;
}

