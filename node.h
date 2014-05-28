#ifndef _STDIO_H_
#define _STDIO_H_ 1
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#define _STDLIB_H_ 1
#include <stdlib.h>
#endif

#ifndef _AVL_TYPE_H_
#define _AVL_TYPE_H_ 1
#include "avl.h"
#endif

typedef struct
{
    int id;
	void *dataPtr;
	AVL_TREE *forwardEdges;
	AVL_TREE *backwardEdges;
	void (*destroyPtr)(void *dataPtr);
	int mark;
}NodeType;

/*************************************************************************/

/* prototypes */
int NodeAddBackwardEdge(NodeType *hNode, EdgeType *edge);
int NodeAddForwardEdge(NodeType *hNode, EdgeType *edge);
int NodeCreate(void *data, int id, NodeType *n, void (*destroyPtr)(void *dataPtr));
void NodeDestroy(NodeType *n);