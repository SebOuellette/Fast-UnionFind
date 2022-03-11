#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
	void* parent;

	int data;
} NODE;

typedef struct Center {
	NODE* root;
} CENTER;

// General functions
NODE* getRoot(NODE);
NODE* newGroup();
NODE* newChild(NODE*, int);

// Union
void unionNodes(NODE, NODE);

// Find
bool findNode(NODE, NODE);