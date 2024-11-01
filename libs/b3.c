#include <stdio.h>
#include <stdlib.h>

#include "b3.h"

// functions prefixed by "b3_" are global,
// the other are for internal use

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

static short listIds(b3_Root *root){
	if(root == NULL) return 0;

	listIds(root->left);
	printf("%d  ", root->id);
	listIds(root->right);

	return 1;
}

static short simpleRemotion(b3_Node *mom, b3_Node *son, int id){
	if(mom == NULL || son == NULL) return 0;

	// it is not this...
	if(id != son->id){
		if(id < son->id)
			return simpleRemotion(son, son->left, id);

		return simpleRemotion(son, son->right, id);
	}

	short leftNull = (son->left == NULL);
	short rightNull = (son->right == NULL);

	// less sons
	if(leftNull && rightNull){
		b3_Node *oldSon;
		oldSon = son;

		if(mom->left == son)
			mom->left = NULL;
		else
			mom->right = NULL;

		free(oldSon);
		return 1;
	}

	return removeAndRealoc(mom, son, leftNull, rightNull);
}

static short removeAndRealoc(b3_Node *mom, b3_Node *son,
							short leftNull, short rightNull){
	// two sons
	if(!leftNull && !rightNull)
		return 0; // TODO

	// one son
	b3_Node *node;

	if(!leftNull)
		node = son->left;
	else
		node = son->right;

	if(mom->left == son)
		mom->left = node;
	else
		mom->right = node;

	free(son);
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

short b3_rmvNode(b3_Root **p_root, int id){
	// treatment to root
	if(*p_root == NULL) return 0;

	b3_Root *root;
	root = *p_root;

	// the node that will be removed
	// is not the root
	if(id != root->id){
		if(id < root->id)
			return simpleRemotion(root, root->left, id);

		return simpleRemotion(root, root->right, id);
	}

	short leftNull = (root->left == NULL);
	short rightNull = (root->right == NULL);

	// less soons
	if(leftNull && rightNull){
		free(*p_root);
		*p_root = NULL;
		return 1;
	}

	// two sons
	if(!leftNull && !rightNull)
		return 0; // TODO

	// one son
	b3_Node *node;
	
	if(!leftNull)
		node = root->left;
	else
		node = root->right;

	free(*p_root);
	*p_root = node;
	
	return 1;
}

void b3_invTree(b3_Root *root){
	if(root == NULL) return;

	b3_Node *leftBackup;
	leftBackup = root->left;
	root->left = root->right;
	root->right = leftBackup;

	b3_invTree(root->left);
	b3_invTree(root->right);
}

void b3_listIds(b3_Root *root){
	// for print the values in horizontal and
	// to put a line feed in chain end, and
	// verify root value, i did this function
	if(!listIds(root))
		puts("b3_listId: Empty root");
	
	putchar('\n');
}

void b3_excTree(b3_Root *root){
	if(root == NULL) return;

	b3_excTree(root->left);
	b3_excTree(root->right);
	free(root);
}
