#include <stdio.h>

typedef unsigned long  uint64;
typedef unsigned int   uint32;
typedef unsigned short uint16;
typedef unsigned char  uint8;

static uint8 heap[10] = {0, 19, 26, 35, 7, 8, 34, 21, 32, 43};

uint16 heap_size()
{
    return sizeof(heap)-1;
}

uint32 leaf_number(uint32 len)
{
    uint32 ret = len%2;
    if (0x00 == ret)
        return ret/2;
    return (len+1)/2;
}

uint32 left_child_idx(uint16 idx)
{
    return (2*idx);
}

uint32 right_child_idx(uint16 idx)
{
    return (2*idx + 1);
}

void max_heapify(uint8 *heap, uint16 idx)
{
    uint16 largest = idx;
    uint16 left = left_child_idx(idx);
    uint16 right = right_child_idx(idx);

    printf("left : %d, right : %d\n", left, right);
    if (left <= heap_size()){
        if (heap[left] > heap[idx]){
            largest = left;
        }else{
            largest = idx;
        }
    }

    if (right <= heap_size()){
        if (heap[right] > heap[largest])
            largest = right;
    }

    if (idx != largest){
        uint32 tmp = heap[idx];
        heap[idx] = heap[largest];
        heap[largest] = tmp;
        max_heapify(heap, largest);
    }

    return;
}


void build_max_heap(uint8 *heap)
{
    uint32 length = heap_size();
    uint32 idx = 0x00;

    for (idx = leaf_number(length); idx > 0x00; idx--){
        printf("idx : %d, value : %d, leaf number : %d\n", idx, heap[idx], leaf_number(length));
        max_heapify(heap, idx);
    }

    return;
}

void main(void)
{
    uint32 idx = heap_size();

    printf("heap length : %d\n", heap_size());

    for(idx = 0x01; idx < heap_size()+1; idx++){
        printf("%d ", heap[idx]);
    }

    printf("\n----------------------\n");
    build_max_heap(heap);

    printf("\n----------------------\n");
    for(idx = 0x01; idx < heap_size()+1; idx++){
        printf("%d ", heap[idx]);
    }
    printf("\n----------------------\n");

    return;
}
