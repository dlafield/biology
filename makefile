parse.exe: look.c avl.o atomType.o bondType.o moleculeType.o HyperNode.o HyperEdge.o HyperGraph.o PebblerHyperEdge.o PebblerHyperNode.o PebblerHyperGraph.o
	gcc -g look.c avl.o atomType.o bondType.o moleculeType.o HyperNode.o HyperEdge.o HyperGraph.o PebblerHyperEdge.o PebblerHyperNode.o PebblerHyperGraph.o -o parse.exe

atomType.o: atomType.c atomType.h
	gcc -g -c atomType.c -o atomType.o

bondType.o: bondType.c bondType.h
	gcc -g -c bondType.c -o bondType.o

moleculeType.o: moleculeType.c moleculeType.h
	gcc -g -c moleculeType.c -o moleculeType.o

PebblerHyperGraph.o: PebblerHyperGraph.c avl.o PebblerHyperGraph.h HyperEdge.o HyperNode.o HyperGraph.o PebblerHyperEdge.o PebblerHyperNode.o
	gcc -g -c PebblerHyperGraph.c avl.o HyperEdge.o HyperNode.o HyperGraph.o PebblerHyperEdge.o PebblerHyperNode.o -o PebblerHyperGraph.o

PebblerHyperNode.o: PebblerHyperNode.h PebblerHyperNode.c PebblerHyperEdge.o avl.o
	gcc -g -c PebblerHyperNode.c PebblerHyperEdge.o avl.o -o PebblerHyperNode.o

PebblerHyperEdge.o: PebblerHyperEdge.h PebblerHyperEdge.c AnnotationType.h
	gcc -g -c PebblerHyperEdge.c -o PebblerHyperEdge.o

HyperGraph.o: HyperGraph.h HyperGraph.c HyperEdge.o HyperNode.o avl.o
	gcc -g -c HyperGraph.c HyperNode.o HyperEdge.o avl.o -o HyperGraph.o

HyperNode.o: HyperNode.h HyperNode.c HyperEdge.o avl.o
	gcc -g -c HyperNode.c HyperEdge.o avl.o -o HyperNode.o

HyperEdge.o: HyperEdge.h HyperEdge.c 
	gcc -g -c HyperEdge.c -o HyperEdge.o

avl.o: avl.c avl.h
	gcc -g -c avl.c -o avl.o

