#include "MaxHeap.h"

MaxHeap init_maxheap(unsigned int size)
{
	MaxHeap mhp = (MaxHeap )calloc(1, sizeof(struct maxheap));

	if (NULL == mhp)
		return NULL;

	mhp->head = (Entry )calloc(1, size*sizeof(struct entry));
	if (NULL == mhp->head){
		free(mhp);
		return NULL;
	}

	return mhp;
}

void inline heap_swp(unsigned int *dst, unsigned int *src)
{
	unsigned int tmp = *src;
	*src = *dst;
	*dst = tmp;

	return;
}

int insert_max_heap(MaxHeap heap, Entry entry)
{
	if (HEAP_FULL(heap->size)){
		fprintf(stderr, "heap was full!\n");
		return (-1);
	}

	Entry head = heap->head;
	memcpy((void *)&head[heap->size+1], (const void *)entry, sizeof(*entry));
	unsigned int idx = heap->size+1, parent = idx/2;

	while((idx > 1) && (head[idx].key > head[parent].key)){
		heap_swp(&head[idx].key,  &head[parent].key);
		idx = parent;
		parent = idx/2;
	}

	heap->size++;

	return 0x00;
}

int delete_max_heap(MaxHeap heap, Entry entry)
{
	if (HEAP_EMPTY(heap->size)){
		fprintf(stderr, "heap was empty!\n");
		return (-1);
	}

	Entry head = heap->head;
	memcpy((void *)entry, (const void *)&head[1], sizeof(struct entry));

	/* 把最后一个节点赋值给ROOT节点 */
	memcpy((void *)&head[1], (const void *)&head[heap->size], sizeof(struct entry));
	/* 清空最后一个节点 */
	memset((void *)&head[heap->size], 0x00, sizeof(struct entry));
	heap->size--;

	unsigned int parent = 1, child = 2*parent;
	while((parent < heap->size) && (head[parent].key < head[child].key)){
		heap_swp(&head[parent].key, &head[child].key);
		parent = child;
		child  = 2*parent;
	}

	return 0x00;
}

int main(void)
{
    MaxHeap mheap = init_maxheap(MAX_ELEMENTS);
    if (NULL == mheap){
    	fprintf(stderr, "%d : mheap == NULL", __LINE__);
    	return (-1);
	}

	mheap->insert = insert_max_heap;
	mheap->del    = delete_max_heap;

	struct entry test[] = {{20}, {15}, {2}, {14}, {10}};
	/*struct entry test[] = {{9}, {11}, {2}, {33}, {66}, {8}, {1}, {88}, {5}, {10}, {30}};*/

	unsigned int size = sizeof(test)/sizeof(struct entry);
	unsigned int i = 0x00;
	for (;i < size; i++){
		mheap->insert(mheap, &test[i]);
	}

	printf("---------------- Insert --------------------\n");
	for (i = 1; i < mheap->size+1; i++){
		printf("%d   \n", mheap->head[i].key);
	}
	printf("--------------------------------------------\n");
	printf("\n");

	printf("---------------- Delete --------------------\n");
	struct entry tmp = {0};
	mheap->del(mheap, &tmp);
	printf("root key : %d\n", tmp.key);
	for (i = 1; i < mheap->size+1; i++){
		printf("%d   \n", mheap->head[i].key);
	}
	printf("--------------------------------------------\n");
	printf("\n");

	return 0;
}
