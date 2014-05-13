#include <stdio.h>

#define SWAP(a, b, c) do{(c) = (b); (b) = (a); (a) = (c);}while(0)

void quick_sort(int list[], int left, int right)
{
	int i = left, j = right+1, tmp = 0x00;
	int pivot = list[left];

	if (left < right){
		do{
			do{
				i++;
			}while((i <= right) && (list[i] < pivot));

			
			do{
				j--;
			}while((j >= left) && (list[j] > pivot));

			if (i < j){
				/*printf("i, j : %d, %d\n", list[i], list[j]);*/
				SWAP(list[i], list[j], tmp);
			}
		}while(i < j);
		/*printf("left, j : %d, %d\n", list[left], list[j]);*/
		SWAP(list[left], list[j], tmp);
		quick_sort(list, left, j-1);
		quick_sort(list, j+1, right);
	}
	
	return;
}


int main(void)
{
	int list[] = {26, 5, 37, 1, 61, 67 , 59, 15, 48, 19};
	int size = sizeof(list)/sizeof(int);

	quick_sort(list, 0, size-1);

	int idx = 0x00;
	for (; idx < size; idx++)
		printf("%d ", list[idx]);

	return 0x00;
}

