#include <string>
#include <vector>

class MoleculeNode
{
	public:
		int getNodeID()
		{
			return this.nodeID;
		}

		void setNodeID(int id)
		{
			this.nodeID = id;
		}

		string getAtomType()
		{
			return this.atomType;
		}

		void setAtomType(string x)
		{
			this.atomType = x;
		}

		/* add connection */

		/* remove connection */

	protected:
		int nodeID;
		string atomType;
};