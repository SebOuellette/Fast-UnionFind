#include "../Headers/DataTypes.h"

// Get the true root of a node, bypassing the center
NODE* getRoot(NODE node) {
	return (*(CENTER*)node.parent).root;
}

// Returns the parent node
NODE* newGroup() {
	NODE* newRoot = (NODE*)malloc(sizeof(NODE));

	// Create a center pointer
	(*newRoot).parent = (CENTER*)malloc(sizeof(CENTER));

	// Set the center's parent to the new root
	(*(CENTER*)(*newRoot).parent).root = newRoot;

	return newRoot;
}

// Add a child to a group
NODE* newChild(NODE* parent, int newData) {
	NODE* newChild = (NODE*)malloc(sizeof(NODE));

	// Set the data
	(*newChild).data = newData;

	// Set the "parent" to the center node of the group
	(*newChild).parent = (*parent).parent;

	return newChild;
}

// Union O(1)
void unionNodes(NODE node1, NODE node2) {
	// Join node1 into node2
	(*(CENTER*)node1.parent).root = getRoot(node2);
}

// Find O(1)
bool findNode(NODE node1, NODE node2) {
	return getRoot(node1) == getRoot(node2);
}