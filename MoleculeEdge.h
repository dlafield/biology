#include <string>
#include <vector>

class MoleculeEdge
{
	public:
		int getSourceAtomID()
		{
			return this.sourceAtomID;
		}

		int getTargetAtomID()
		{
			return this.targetAtomID;
		}

		void setSourceAtomID(int id)
		{
			this.sourceAtomID = id;
		}

		void setTargetAtomID(int id)
		{
			this.targetAtomID = id;
		}

		MoleculeEdge(int sourceID, int targetID)
		{
			setSourceAtomID(sourceID);
			setTargetAtomID(targetID);
		}

		~MoleculeEdge(){}

	protected:
		int sourceAtomID;
		int targetAtomID;
};