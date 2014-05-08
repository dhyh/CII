#include "seqsearch.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis      顺序查找 (无序的数组里查找关键字）
 *
 * @Param list[]  max length is n
 * @Param searchnum
 * @Param n     length of list[]
 *
 * @Returns   
 */
/* ----------------------------------------------------------------------------*/
int seqsearch(ELEMENT *list, int searchnum, int n)
{
	/*设置哨兵， 当idx等于n时，退出循环*/
    list[n].key = searchnum;

    int idx = 0x00;

    for (; list[idx].key != searchnum; idx++);

    return (idx < n) ?  (idx) : (-1);
}


int main(void)
{
	ELEMENT list[MAX_SIZE+1] = {{9}, {1}, {5}, {7}, {8}, {3}, {4}, {2}, {6}, {0}, {-1}};

	int ret = seqsearch(list, 8, MAX_SIZE);

	printf("ret : %d\n", ret);


	ret = seqsearch(list, 11, MAX_SIZE);

	printf("ret : %d\n", ret);

	return 0x00;
}
