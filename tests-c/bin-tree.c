#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////
typedef struct _Node{
	int value;
	struct _Node *left, *right;
} Node;

static Node *newNode(int value);

void btree_insert(Node *cell, int value);
void btree_print(Node *cell);
void btree_clear(Node *cell);
////////////////////////////

static Node *root = NULL;

static Node *newNode(int value){
	Node *temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->left  = NULL;
	temp->right = NULL;

	return temp;
}

void btree_insert(Node *cell, int value){
	if(root == NULL){
		root = newNode(value);
		return;
	}

	if(cell->value > value){
		if(cell->left == NULL){
			cell->left = newNode(value);
			return;
		}
		btree_insert(cell->left, value);
		return;
	}

	if(cell->right == NULL){
		cell->right = newNode(value);
		return;
	}
	btree_insert(cell->right, value);
}

void btree_print(Node *cell){
	if(cell == NULL) return;

	btree_print(cell->left);
	printf("  %d  ", cell->value);
	btree_print(cell->right);
}

void btree_clear(Node *cell){
	if(cell->left != NULL)
		btree_clear(cell->left);
	if(cell->right != NULL)
		btree_clear(cell->right);
	free(cell);
}

int main(int argc, char *argv[]){
	srand(time(NULL));

	btree_insert(root, 50);
	for(short i = 0; i < 5 + rand() % 6; i++)
		btree_insert(root, rand() % 100);
	
	btree_print(root);
	printf("\n\n");

	btree_clear(root);

	return 0;
}
