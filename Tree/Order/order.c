#include "../tree.h"

void inorder(tree_pointer ptr)
{
	if (NULL == ptr)
		return;

	if (NULL != ptr->left_child)
		inorder(ptr->left_child);
	
	printf("Data : %d\n", ptr->data);

	if (NULL != ptr->right_child)
		inorder(ptr->right_child);
	return;
}


void preorder(tree_pointer ptr)
{
	if (NULL == ptr)
		return;

	printf("Data : %d\n", ptr->data);

	if (NULL != ptr->left_child)
		preorder(ptr->left_child);

	if (NULL != ptr->right_child)
		preorder(ptr->right_child);

	return;
}

void postorder(tree_pointer ptr)
{
	if (NULL == ptr)
		return;

	if (NULL != ptr->left_child)
		postorder(ptr->left_child);

	if (NULL != ptr->right_child)
		postorder(ptr->right_child);

	printf("Data : %d\n", ptr->data);

	return;
}

int main(void)
{
	tree_pointer tp = NULL;
	unsigned int num = 10;

    if (NULL == (tp = (tree_pointer)calloc(num, sizeof(TNODE)))){
		return 0x00;
	}
	

	tp[0].data = 9;
	tp[0].left_child = &tp[1];
	tp[0].right_child = &tp[2];

	tp[1].data = 12;
	tp[1].left_child = &tp[3];
	tp[1].right_child = &tp[4];

	tp[2].data = 58;
	tp[2].left_child = &tp[5];
	tp[2].right_child = &tp[6];

	tp[3].data = 39;
	tp[3].left_child = NULL;
	tp[3].right_child = &tp[7];

	tp[4].data = 90;
	tp[4].left_child = &tp[8];
	tp[4].right_child = NULL;

	tp[5].data = 78;
	tp[5].left_child = NULL;
	tp[5].right_child = &tp[9];

	tp[6].data = 123;
	tp[6].left_child = NULL;
	tp[6].right_child = NULL;

	tp[7].data = 239;
	tp[7].left_child = NULL;
	tp[7].right_child = NULL;

	tp[8].data = 29;
	tp[8].left_child = NULL;
	tp[8].right_child = NULL;

	tp[9].data = 18;
	tp[9].left_child = NULL;
	tp[9].right_child = NULL;


	printf("-----------In Order----------------\n");
	inorder(tp);
	printf("-----------------------------------\n\n");

	printf("-----------Pre Order----------------\n");
	preorder(tp);
	printf("-----------------------------------\n\n");

	printf("-----------Post Order----------------\n");
	postorder(tp);
	printf("-----------------------------------\n\n");

	return 0x00;
}
