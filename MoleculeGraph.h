#include "BitGraph.h"
#include "Molecule.h"
#include <vector>

using namespace std;

class MoleculeGraph
{
	public:
	
	MoleculeGraph()
	{
		g = new BitGraph();
	}

	MoleculeGraph(BitGraph x)
	{
		g = new BitGraph(x);
	}

	~MoleculeGraph()
	{
		~g();
	}

	MoleculeGraph::Node* getNode(Molecule m)
	{
		return g.getNode(m.id);
	}

	private:

	BitGraph g;
	
};