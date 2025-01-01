#ifndef __B_3__
#define __B_3__

#define bool  char
#define false 0
#define true  1

typedef struct b3_Node{
	int id;
	short height;
	void *content;
	bool is_copy;
	struct b3_Node *left, *right;
}b3_Node;

b3_Node* b3_create(int id, void *content, bool copy_content);
bool b3_add_node(b3_Node **root, int id, void *content, bool copy_content);

static b3_Node* insert_node(b3_Node *node);
static short update_node_height(b3_Node *node);

b3_Node* b3_get_node(b3_Node *root, int id);
b3_Node* b3_copy_tree(b3_Node *root, bool copy_content);
void b3_invert_tree(b3_Node *root);
void b3_info_list(b3_Node *root);
void b3_free_tree(b3_Node *root);

static void free_node(b3_Node *node);

bool b3_remove_node(b3_Node **root, int id);

static bool remove_root_child(b3_Node **root);
static void set_new_position_to_orphan(b3_Node *node, b3_Node *orphan);
static bool remove_from_branch_node(b3_Node *mom, b3_Node *son, int id);
static bool no_children_remotion(b3_Node *mom, b3_Node *son);
static bool single_child_remotion(b3_Node *mom, b3_Node *son, b3_Node *niece);
static bool double_children_remotion(b3_Node *mom, b3_Node *son);

#endif
