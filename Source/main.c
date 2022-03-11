/// This file is a bit of a mess, but the bulk of it is just keeping track of memory
/// which is something you'd have to do anyway in a quick find or quick union algorithm.
/// The problem is that this is C, so I have to do memory management manually.

//// Therefore, look in the DataTypes.h and DataTypes.c files for the actual algorithm


#include <stdio.h>
#include "../Headers/DataTypes.h"

#define MAX_NODE_COUNT 13
#define MAX_GROUP_COUNT 3

int main() {
	srand(4);

	// Arrays so that the memory can be freed and accessed
	NODE* nodeArray[MAX_NODE_COUNT];
	CENTER* centerArray[MAX_GROUP_COUNT];

	// Create 3 groups
	for (int i = 0; i < MAX_GROUP_COUNT; i++) {
		nodeArray[i] = newGroup();
		centerArray[i] = (*nodeArray[i]).parent;
	}

	// Create the children
	for (int i = MAX_GROUP_COUNT; i < MAX_NODE_COUNT; i++) {
		// "Randomly" distribute the children
		NODE* root = (*centerArray[rand() % MAX_GROUP_COUNT]).root;

		// generate random data to add to the node
		nodeArray[i] = newChild(root, rand());
	}

	printf("Do these nodes exist in the same group? %s\n", findNode(*nodeArray[3], *nodeArray[6]) ? "YES!" : "no :C");

	unionNodes(*nodeArray[3], *nodeArray[6]);

	printf("Now do these nodes exist in the same group? %s\n", findNode(*nodeArray[3], *nodeArray[6]) ? "YES!" : "no :C");

	// Free the memory
	for (int i=0;i<MAX_NODE_COUNT;i++) {
		free(nodeArray[i]);
	}
	for (int i=0;i<MAX_GROUP_COUNT;i++) {
		free(centerArray[i]);
	}
	return 0;
}