#include <stdio.h>

void merge_sort(int list[], int sort[], int i, int m, int n)
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
		for (t = j; t < n; t++)
			sort[k+t-j] = list[t];
	}else{
		for (t = i; t < m; t++)
			sort[k+t-i] = list[t];
	}

	return;
}

int main(void)
{
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int sort[10];

	merge_sort(list, sort, 0, 5, 10);


	int idx = 0x00, size = sizeof(sort)/sizeof(int);

	for (; idx < size; idx++){
		printf("%d ", sort[idx]);
	}

	return 0x00;
}

