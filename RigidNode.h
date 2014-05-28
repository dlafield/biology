#include <string>
#include <vector>

class RigidNode: public MoleculeNode
{
	public:
		
		bool getCanConnect()
		{
			return this.canConnect;
		}

		void setCanConnect(bool x)
		{
			this.canConnect = x;
		}

		string getConnectionType()
		{
			return this.connectionType;
		}

		void setConnectionType(string x)
		{
			this.connectionType = x;
		}

		RigidNode(int id, string atomType, string connectionType, bool canConnect)
		{
			setNodeID(id);
			setAtomType(atomType);
			setConnectionType(connectionType);
			setCanConnect(canConnect);
		}

		~RigidNode(){}

		

	protected:
		bool canConnect;
		string connectionType;
};