#ifndef _AVL_TYPE_H_
#define _AVL_TYPE_H_ 1
#include "avl.h"
#endif

#ifndef _NODE_H_
#define _NODE_H_ 1
#include "node.h"
#endif

#ifndef _EDGE_H_
#define _EDGE_H_ 1
#include "edge.h"
#endif

typedef struct
{
	AVL_TREE *nodes;
	AVL_TREE *edges;
	void (*nodeDestroyer)(void *dataPtr);
	int (*compare) (void *argu1, void *argu2);
}GraphType;

/*************************************************************************/

/* prototypes */
int GraphAddEdge(GraphType h, int sourceNodes[], int sourceNodeCount, int targetNode, EdgeAnnotationType annot);
int GraphAddNode(GraphType h, NodeType *x);
//void GraphBreadthFirstTraverse(GraphType g, void(*process)(void *dataPtr));
int GraphCreate(GraphType g, void (*nodeDestroyer)(void *dataPtr), int (*compare) (void *argu1, void *argu2));
//void GraphDepthFirstTraverse(GraphType g, void(*process)(void *dataPtr));
void GraphDestroy(GraphType g);
void *GraphGetNode(GraphType h, NodeType *x);
int GraphGetNodeFromId(GraphType h, int id, NodeType *n);
int GraphGetNumOfEdges(GraphType h);
int GraphGetNumOfNodes(GraphType h);
int GraphHasEdge(GraphType h, int sourceNodes[], int sourceNodeCount, int targetNode);