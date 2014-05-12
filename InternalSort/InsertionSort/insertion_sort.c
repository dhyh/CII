#include "insertion_sort.h"


void insertion_sort(int list[], int n)
{
	int num = 0x00;

	int i, j;

	for (i = 1; i < n; i++){
		num = list[i];
		for (j = i-1; j >= 0 && num < list[j]; j--){
			list[j+1] = list[j];
		}
		list[j+1] = num;
	}

	return;
}


int main(void)
{
	int list[5] = {9, 5, 3, 2, 8};
	int size = sizeof(list)/sizeof(int), idx = 0x00;

	insertion_sort(list, size);

	for (; idx < size; idx++){
		printf("%d ", list[idx]);
	}

	return 0;
}
