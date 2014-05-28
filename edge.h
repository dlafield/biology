#ifndef _STDIO_H_
#define _STDIO_H_ 1
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#define _STDLIB_H_ 1
#include <stdlib.h>
#endif

typedef struct
{
    int targetNode;
	int sourceNode;
	int weight;
}EdgeType;

/*************************************************************************/

/* prototypes */
int EdgeCompare(EdgeType a, EdgeType b);
EdgeType EdgeCreateWithWeight(int sourceNodeId, int targetNodeId, int weight);
EdgeType EdgeCreate(int sourceNodeId, int targetNodeId);
void EdgeDestroy(EdgeType *hEdge);
int Edge_equals(EdgeType a, EdgeType b);