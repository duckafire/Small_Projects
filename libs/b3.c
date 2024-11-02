#include <stdio.h>
#include <stdlib.h>

#include "b3.h"

static b3_Node* newNode(int id, void *content){
	b3_Node *node;

	node = malloc(sizeof(b3_Node));
	node->id = id;
	node->content = content;
	node->left = NULL;
	node->right = NULL;

	return node;
}

static short addNewNode(b3_Root *root, int id, void *content){
	if(root->id == id) return 0;

	if(id < root->id){
		if(root->left == NULL){
			root->left = newNode(id, content);
			return 1;
		}
		return addNewNode(root->left, id, content);
	}

	if(root->right == NULL){
		root->right = newNode(id, content);
		return 1;
	}

	return addNewNode(root->right, id, content);
}

static void moveNode(b3_Node *node, b3_Node *orphan){
	if(orphan->id < node->id){
		if(node->left == NULL){
			node->left = orphan;
			return;
		}

		moveNode(node->left, orphan);
	}

	if(node->right == NULL){
		node->right = orphan;
		return;
	}

	moveNode(node->right, orphan);
}

static short buildIdList(b3_Root *root){
	if(root == NULL) return 0;

	buildIdList(root->left);
	printf("%d  ", root->id);
	buildIdList(root->right);

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

static short removeAndRealoc(b3_Node *mom, b3_Node *son, short leftNull, short rightNull){
	// two sons
	if(!leftNull && !rightNull){
		b3_Node *heritor, *orphan;

		if(abs(son->id - son->left->id) <= abs(son->id - son->right->id)){
			heritor = son->left;
			orphan = son->right;
		}else{
			heritor = son->right;
			orphan = son->left;
		}

		if(mom->left == son)
			mom->left = heritor;
		else
			mom->right = heritor;

		free(son);
		moveNode(heritor, orphan);
		
		return 1;
	}

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

	return addNewNode(root, id, content);
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

b3_Root* b3_copyAll(b3_Root *src){
	if(src == NULL) return NULL;

	b3_Root *dest;
	dest = newNode(src->id, src->content);

	dest->left = b3_copyAll(src->left);
	dest->right = b3_copyAll(src->right);

	return dest;
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
	if(!leftNull && !rightNull){
		b3_Node *heritor, *orphan;

		if(abs(root->id - root->left->id) <= abs(root->id - root->right->id)){
			heritor = root->left;
			orphan = root->right;
		}else{
			heritor = root->right;
			orphan = root->left;
		}

		free(*p_root);
		*p_root = heritor;
		moveNode(*p_root, orphan);

		return 1;
	}

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
	if(!buildIdList(root))
		puts("b3_listId: Empty root");
	
	putchar('\n');
}

void b3_excTree(b3_Root *root){
	if(root == NULL) return;

	b3_excTree(root->left);
	b3_excTree(root->right);
	free(root);
}
