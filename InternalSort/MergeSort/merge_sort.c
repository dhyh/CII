#include "merge_sort.h"

void merge(int list[], int sort[], int i, int m, int n)
{
	int j, k , t;
	k = i;
	j = m+1;

	while((i <= m) && (j <= n)){
		if (list[i] < list[j]){
			sort[k++] = list[i++];
		}else{
			sort[k++] = list[j++];
		}
	}

	if (i > m){
		for (t = j; t <= n; t++)
			sort[k+t-j] = list[t];
	}else{
		for (t = i; t <= m; t++)
			sort[k+t-i] = list[t];
	}

	return;
}

void merge_pass(int list[], int sort[], int n, int length)
{
	int i = 0x00, j = 0x00;
	
	for (; i <= (n - 2*length); i += 2*length){
		merge(list, sort, i , i+length-1, i+2*length-1);
	}

	if (i+length < n){
		merge(list, sort, i , i+length-1, n-1);
	}else{
		for (j = i; j < n; j++)
			sort[j] = list[j];
	}

	return;
}


void merge_sort(int list[], int n)
{
	int length = 0x01;
	int sort[MAX_SIZE] = {0};

	while (length < n){
        merge_pass(list, sort, n, length);
        length *= 2;
        merge_pass(sort, list, n, length);
        length *= 2;
	}

	return;
}

int main(void)
{
	int list[] = {31, 12, 33, 54, 25, 76, 17, 28, 39, 10};
	int idx = 0x00, size = sizeof(list)/sizeof(int);

	merge_sort(list, size);

	printf("-------- Output -----------\n");
	for (idx = 0x00; idx < size; idx++){
		printf("%d ", list[idx]);
	}
	printf("\n");

	return 0x00;
}

