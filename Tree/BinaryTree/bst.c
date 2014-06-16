#include "bst.h"

tree_pointer search(tree_pointer root, int key)
{
	if (NULL == root)    return NULL;

	if (key > root->data){
		return search(root->right_child, key);
	}else if (key < root->data){
		return search(root->left_child, key);
	}

	return root;
}


tree_pointer search_iterator(tree_pointer root, int key)
{
	if (NULL == root)         return NULL;
    tree_pointer tmp = root;
    do{
    	if (key > tmp->data){
    		tmp = tmp->right_child;
		}else if (key < tmp->data){
			tmp = tmp->left_child;
		}else{
			return tmp;
		}
	}while(NULL != tmp);

	return NULL;
}

int insert(tree_pointer root, int key)
{
    if (NULL == root)     return (-1);
    tree_pointer *tmp = &root;

    do{
    	if (key > (*tmp)->data){
    		tmp = &((*tmp)->right_child);
		}else if (key < (*tmp)->data){
			tmp = &((*tmp)->left_child);
		}else{
			return 0x00;
		}
	}while(NULL != (*tmp));

	tree_pointer entry = (tree_pointer)calloc(1, sizeof(TNODE));
	if (NULL == entry){
		return (-1);
	}

	entry->data = key;
    entry->right_child = NULL;
    entry->left_child  = NULL;

	*tmp = entry;

	return 0x00;
}



void print_inorder(tree_pointer ptr)
{
	if (NULL == ptr)
		return;

	if (NULL != ptr->left_child)
		print_inorder(ptr->left_child);
	
	printf("Data : %d\n", ptr->data);

	if (NULL != ptr->right_child)
		print_inorder(ptr->right_child);
	return;
}

int main(void)
{
	tree_pointer tp = NULL;
	unsigned int num = 10;

    if (NULL == (tp = (tree_pointer)calloc(num, sizeof(TNODE)))){
		return 0x00;
	}
	

	tp[0].data = 30;
	tp[0].left_child = &tp[1];
	tp[0].right_child = &tp[2];

	tp[1].data = 5;
	tp[1].left_child = &tp[3];
	tp[1].right_child = NULL;//&tp[4];

	tp[2].data = 40;
	tp[2].left_child = NULL;//&tp[5];
	tp[2].right_child = &tp[4];

	tp[3].data = 2;
	tp[3].left_child = NULL;
	tp[3].right_child = NULL;//&tp[7];

	tp[4].data = 80;
	tp[4].left_child = NULL;
	tp[4].right_child = NULL;

	if (NULL == search_iterator(tp, 88)){
		printf("search return NULL\n");
	}else{
		printf("search return OK!\n");
	}

	if (NULL == search_iterator(tp, 2)){
		printf("search return NULL\n");
	}else{
		printf("search return OK!\n");
	}

   /* tp[5].data = 78;*/
	/*tp[5].left_child = NULL;*/
	/*tp[5].right_child = &tp[9];*/

	/*tp[6].data = 123;*/
	/*tp[6].left_child = NULL;*/
	/*tp[6].right_child = NULL;*/

	/*tp[7].data = 239;*/
	/*tp[7].left_child = NULL;*/
	/*tp[7].right_child = NULL;*/

	/*tp[8].data = 29;*/
	/*tp[8].left_child = NULL;*/
	/*tp[8].right_child = NULL;*/

	/*tp[9].data = 18;*/
	/*tp[9].left_child = NULL;*/
	/*tp[9].right_child = NULL;*/


    print_inorder(tp);
	printf("=============================================\n");
	insert(tp, 90);
    print_inorder(tp);
	printf("=============================================\n");
	insert(tp, 35);
    print_inorder(tp);
	printf("=============================================\n");

	return 0x00;
}


