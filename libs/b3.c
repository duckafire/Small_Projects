#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "b3.h"

static b3_Node *new_node;
static b3_Node *tmp_node;
static bool b3_add_node_status;

b3_Node* b3_create(int id, void *content, bool copy_content){
	new_node = malloc(sizeof(b3_Node));

	new_node->id      = id;
	new_node->height  = 0;
	new_node->is_copy = copy_content;
	new_node->left    = NULL;
	new_node->right   = NULL;

	if(new_node->is_copy){
		size_t size = sizeof(content);

		new_node->content = malloc(size);
		memcpy(new_node->content, content, size);
	}else{
		new_node->content = content;
	}

	return new_node;
}

bool b3_add_node(b3_Node **root, int id, void *content, bool copy_content){
	b3_create(id, content, copy_content);

	b3_add_node_status = false;
	*root = insert_node(*root);

	return b3_add_node_status;
}

static b3_Node* insert_node(b3_Node *node){
	if(node == NULL){
		b3_add_node_status = true;
		return new_node;
	}


	if(new_node->id < node->id){
		node->left = insert_node(node->left);

	}else if(new_node->id > node->id){
		node->right = insert_node(node->right);

	}else{
		free_node(node);
		return NULL;
	}

	if(b3_add_node_status)
		node->height = update_node_height(node);

	return node;
}

static short update_node_height(b3_Node *node){
	if(node == NULL)
		return -1;

	short left  = update_node_height(node->left);
	short right = update_node_height(node->right);

	if(left > right)
		return left + 1;

	return right + 1;
}

b3_Node* b3_get_node(b3_Node *root, int id){
	if(root == NULL)
		return NULL;

	if(id < root->id)
		return b3_get_node(root->left, id);

	if(id > root->id)
		return b3_get_node(root->right, id);

	return root;
}

b3_Node* b3_copy_tree(b3_Node *root, bool copy_content){
	if(root == NULL)
		return NULL;

	b3_Node *_new_node;
	_new_node = b3_create(root->id, root->content, copy_content);

	_new_node->left  = b3_copy_tree(root->left,  copy_content);
	_new_node->right = b3_copy_tree(root->right, copy_content);

	return _new_node;
}

void b3_invert_tree(b3_Node *root){
	if(root == NULL)
		return;

	b3_invert_tree(root->left);
	b3_invert_tree(root->right);

	tmp_node    = root->left;
	root->left  = root->right;
	root->right = tmp_node;
}

void b3_info_list(b3_Node *root){
	if(root == NULL)
		return;

	b3_info_list(root->left);

	printf("id:      %d\n", root->id);
	printf("height:  %d\n", root->height);
	printf("content: %p\n", root->content);
	printf("is_copy: %d\n", root->is_copy);
	printf("left:    %p\n", root->left);
	printf("right:   %p\n", root->right);
	putchar('\n');

	b3_info_list(root->right);
}

void b3_free_tree(b3_Node *node){
	if(node == NULL)
		return;

	b3_free_tree(node->left);
	b3_free_tree(node->right);

	free_node(node);
}

static void free_node(b3_Node *node){
	if(node->is_copy)
		free(node->content);

	free(node);
}

bool b3_remove_node(b3_Node **root, int id){
	if(*root == NULL)
		return false;

	if(id == (*root)->id)
		return remove_root_child(root);

	if(id < (*root)->id)
		return remove_from_branch_node(*root, (*root)->left, id);

	return remove_from_branch_node(*root, (*root)->right, id);
}

#define SET_HERITOR_AND_ORPHAN(n, h, o)                        \
	if(abs(n->id - n->left->id) <= abs(n->id - n->right->id)){ \
		h = n->left;                                           \
		o = n->right;                                          \
	}else{                                                     \
		h = n->right;                                          \
		o = n->left;                                           \
	}
//#enddef

#define UPDATE_SON(m, s, ns) \
	if(m->left == s)         \
		m->left = ns;        \
	else                     \
		m->right = ns


static bool remove_root_child(b3_Node **root){
	const bool noleft  = ((*root)->left == NULL);
	const bool noright = ((*root)->right == NULL);

	// no children
	if(noleft && noright){
		free(*root);
		*root = NULL;
		
		return true;
	}

	// two children
	if(!noleft && !noright){
		b3_Node *heritor, *orphan;

		SET_HERITOR_AND_ORPHAN((*root), heritor, orphan)

		free_node(*root);
		*root = heritor;
		set_new_position_to_orphan(*root, orphan);
		return true;
	}

	// one children
	b3_Node *buf;
	
	if(!noleft)
		buf = (*root)->left;
	else
		buf = (*root)->right;

	free_node(*root);
	*root = buf;
	return true;
}

// from "remove_root_child"
static void set_new_position_to_orphan(b3_Node *node, b3_Node *orphan){
	if(orphan->id < node->id){

		if(node->left == NULL){
			node->left = orphan;
			return;
		}

		set_new_position_to_orphan(node->left, orphan);
		return;
	}

	if(node->right == NULL){
		node->right = orphan;
		return;
	}

	set_new_position_to_orphan(node->right, orphan);
}

static bool remove_from_branch_node(b3_Node *mom, b3_Node *son, int id){
	if(mom == NULL || son == NULL) return false;

	if(id != son->id){
		if(id < son->id)
			return remove_from_branch_node(son, son->left, id);

		return remove_from_branch_node(son, son->right, id);
	}

	const bool noleft  = (son->left == NULL);
	const bool noright = (son->right == NULL);

	if(noleft && noright)
		return no_children_remotion(mom, son);

	if(!noleft && !noright)
		return double_children_remotion(mom, son);

	if(!noleft)
		return single_child_remotion(mom, son, son->left);

	return single_child_remotion(mom, son, son->right);
}

static bool no_children_remotion(b3_Node *mom, b3_Node *son){
	UPDATE_SON(mom, son, NULL);

	free_node(son);
	return true;
}

static bool single_child_remotion(b3_Node *mom, b3_Node *son, b3_Node *niece){
	UPDATE_SON(mom, son, niece);

	free_node(son);
	return true;
}

static bool double_children_remotion(b3_Node *mom, b3_Node *son){
	b3_Node *heritor, *orphan;

	SET_HERITOR_AND_ORPHAN(son, heritor, orphan)
	UPDATE_SON(mom, son, heritor);

	free_node(son);
	set_new_position_to_orphan(heritor, orphan);
	return true;
}
