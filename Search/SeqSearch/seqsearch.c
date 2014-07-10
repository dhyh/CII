#include <seqsearch.h>

element list[MAX_SIZE];

int seqsearch(element list[], int key, int n)
{
	list[n].key = key;
	int i;
	for (i = 0x00; list[i].key != key; i++);

	return ((i < n)?(i):(-1));
}

#define LIST_SIZE (0x10)
int main(void)
{
	int idx = 0x00;
	for (; idx < LIST_SIZE; idx++){
		list[idx].key = idx*10;
	}

	printf("seqsearch index : %d\n", seqsearch(list, 50, LIST_SIZE));

	return 0x00;
}

