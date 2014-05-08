#include "binsearch.h"

int COMPARE(int a, int b)
{
	if (a < b)
		return -1;
	else if (a == b)
		return 0;
	return 1;
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis        折半查找，在list有序的前提下
 *
 * @Param list[]
 * @Param searchnum
 * @Param n
 *
 * @Returns   
 */
/* ----------------------------------------------------------------------------*/
int binsearch(int list[], int searchnum, int n)
{
	int middle = 0x00, left = 0x00, right = n-1;

	while (left < right){
		middle = (left + right)/2;
		switch(COMPARE(list[middle], searchnum)){
			case -1:
				left = middle + 1;
				break;
			case 0:
				return middle;
			case 1:
				right = middle - 1;
				break;
		}
	}

	return -1;
}


int main(void)
{
	int list[] = {1, 2, 3, 4, 5, 6 , 7, 8, 9, 10};

	int ret = binsearch(list, 5, sizeof(list)/sizeof(int));
	printf("ret : %d\n", ret);

	ret = binsearch(list, 0, sizeof(list)/sizeof(int));
	printf("ret : %d\n", ret);

	return 0x00;
}



