#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree_node *tree_pointer;

typedef struct tree_node{
	int data;
	tree_pointer left_child, right_child, parent;
}TNODE;

#endif
