#include <stdio.h>
#include <stdlib.h>

#include "b3.h"

static b3_Node* newNode(int id, void *content){
	b3_Node *node;

	node = malloc(sizeof(b3_Node));
	node->left = NULL;
	node->right = NULL;
	node->id = id;
	node->content = content;

	return node;
}

static short addNode(b3_Root *root, int id, void *content){
	if(root->id == id) return 0;

	if(id < root->id){
		if(root->left == NULL){
			root->left = newNode(id, content);
			return 1;
		}
		return addNode(root->left, id, content);
	}

	if(root->right == NULL){
		root->right = newNode(id, content);
		return 1;
	}

	return addNode(root->right, id, content);
}

static short listId(b3_Root *root){
	if(root == NULL) return 0;

	listId(root->left);
	printf("%d  ", root->id);
	listId(root->right);

	return 1;
}

b3_Root* b3_setRoot(int id, void *content){
	return newNode(id, content);
}

short b3_addNode(b3_Root *root, int id, void *content){
	// it is not necessary verify "this" in
	// tree nodes, only root, by cause this
	// i did this function
	if(root == NULL) return 0;

	return addNode(root, id, content);
}

b3_Node* b3_getNode(b3_Root *root, int id){
	if(root == NULL) return NULL;
	if(root->id == id) return root;

	if(id < root->id)
		return b3_getNode(root->left, id);

	return b3_getNode(root->right, id);
}

void* b3_getCont(b3_Root *root, int id){
	return (b3_getNode(root, id))->content;
}

//void b3_rmvNode(b3_Root *root, int id);

void b3_listId(b3_Root *root){
	// for print the values in horizontal and
	// to put a line feed in chain end, and
	// verify root value, i did this function
	if(!listId(root))
		puts("b3_listId: Empty root");
	
	putchar('\n');
}

void b3_excTree(b3_Root *root){
	if(root == NULL) return;

	b3_excTree(root->left);
	b3_excTree(root->right);
	free(root);
}
