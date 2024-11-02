#ifndef __B_3__
#define __B_3__

struct __b3__node__{
	struct __b3__node__ *left, *right;
	int id;
	void *content;
};

#define b3_Node struct __b3__node__
#define b3_Root struct __b3__node__

static b3_Node* newNode(int id, void *content);
static short addNewNode(b3_Root *root, int id, void *content);
static void moveNode(b3_Node *node, b3_Node *orphan);
static short buildIdList(b3_Root *root);
static short simpleRemotion(b3_Node *mom, b3_Node *son, int id);
static short removeAndRealoc(b3_Node *mom, b3_Node *son, short leftNull, short rightNull);

b3_Root* b3_setRoot(int id, void *content);
short b3_addNode(b3_Root *root, int id, void *content);
b3_Node* b3_getNode(b3_Root *root, int id);
void* b3_getCont(b3_Root *root, int id);
b3_Root* b3_copyAll(b3_Root *src);
short b3_rmvNode(b3_Root **p_root, int id);
void b3_invTree(b3_Root *root);
void b3_listIds(b3_Root *root);
void b3_excTree(b3_Root *root);

#endif
