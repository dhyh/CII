#include "bst.h"

static tree_pointer search_max(tree_pointer root);
static tree_pointer search_min(tree_pointer root);

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

int delete(tree_pointer root, int key)
{
    if (NULL == root)     return (-1);
    tree_pointer *tmp = &root;

    do{
    	if (key > (*tmp)->data){
    		tmp = &((*tmp)->right_child);
		}else if (key < (*tmp)->data){
			tmp = &((*tmp)->left_child);
		}else if (key == (*tmp)->data){
			break;
		}
	}while(NULL != (*tmp));

	/* 删除节点为叶子节点 */
	if ((NULL == (*tmp)->left_child) && (NULL == (*tmp)->right_child)){
		if ((*tmp) == (*tmp)->parent->right_child){
			(*tmp)->parent->right_child = NULL;
		}else{
			(*tmp)->parent->left_child = NULL;
		}
		return 0x00;
	}

	/* 在坐子树中找最大元素 */
    tree_pointer entry = search_max((*tmp)->left_child);
	if (entry->parent == (*tmp)){ /* 只有左子树的单支 */
		(*tmp)->left_child = entry->left_child;
		if (NULL != entry->left_child){
		    entry->left_child->parent = (*tmp);
		}
	}else { /* 度为1或0的最大元素 */
		if (NULL != entry->left_child){
			entry->parent->right_child = entry->left_child;
		}else{
			entry->parent->right_child = NULL;
		}
	}

	entry->left_child = (*tmp)->left_child;
	entry->right_child = (*tmp)->right_child;
	if ((*tmp) == (*tmp)->parent->right_child){
		(*tmp)->parent->right_child = entry;
	}else{
		(*tmp)->parent->left_child = entry;
	}

	if (NULL != (*tmp)->right_child){
		(*tmp)->right_child->parent = entry;
	}
	if (NULL != (*tmp)->left_child){
		(*tmp)->left_child->parent = entry;
	}

	return 0x00;
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

static tree_pointer search_max(tree_pointer root)
{
    if (NULL == root)     return NULL;

	tree_pointer tmp = root;

	while(NULL != tmp){
		if (NULL == tmp->right_child){
			break;
		}
		tmp  = tmp->right_child;
	};
	
	return tmp;
}

static tree_pointer search_min(tree_pointer root)
{
    if (NULL == root)     return NULL;

	tree_pointer tmp = root;

	while(NULL != tmp){
		if (NULL == tmp->left_child){
			break;
		}
		tmp  = tmp->left_child;
	};
	
	return tmp;
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
	

	tp[0].data = 40;
	tp[0].left_child = &tp[1];
	tp[0].right_child = &tp[2];
	tp[0].parent = NULL;

	tp[1].data = 20;
	tp[1].left_child = &tp[3];
	tp[1].right_child = &tp[4];
	tp[1].parent = &tp[0];

	tp[2].data = 60;
	tp[2].left_child = &tp[5];
	tp[2].right_child = &tp[6];
	tp[2].parent = &tp[0];

	tp[3].data = 10;
	tp[3].left_child = &tp[7];
	tp[3].right_child = NULL;//&tp[7];
	tp[3].parent = &tp[1];

	tp[4].data = 30;
	tp[4].left_child = NULL;
	tp[4].right_child = NULL;
	tp[4].parent = &tp[1];

	tp[5].data = 50;
	tp[5].left_child = &tp[8];
	tp[5].right_child = &tp[9];
	tp[5].parent = &tp[2];


	tp[6].data = 70;
	tp[6].left_child = NULL;
	tp[6].right_child = NULL;
	tp[6].parent = &tp[2];

	tp[7].data = 9;
	tp[7].left_child = NULL;
	tp[7].right_child = NULL;
	tp[7].parent = &tp[3];


	tp[8].data = 45;
	tp[8].left_child = NULL;
	tp[8].right_child = NULL;
	tp[8].parent = &tp[5];

	tp[9].data = 55;
	tp[9].left_child = &tp[10];
	tp[9].right_child = NULL;
	tp[9].parent = &tp[5];


	tp[10].data = 52;
	tp[10].left_child = NULL;
	tp[10].right_child = NULL;
	tp[10].parent = &tp[9];


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
	delete(tp, 60);
    print_inorder(tp);
	printf("=============================================\n");
	delete(tp, 9);
    print_inorder(tp);
	printf("=============================================\n");

	return 0x00;
}


