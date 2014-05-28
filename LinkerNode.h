#include <string>
#include <vector>

class LinkerNode: public MoleculeNode
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

		int getMaxConnections()
		{
			return this.maxConnections;
		}

		void setMaxConnections(int x)
		{
			this.maxConnections = x;
		}

		int getCurrentNumberOfConnections()
		{
			return this.currentNumberOfConnections;
		}

		void setCurrentNumberOfConnections(int x)
		{
			this.currentNumberOfConnections = x;
		}

		LinkerNode(int id, string atomType, string connectionType, int maxConnections)
		{
			setNodeID(id);
			setAtomType(atomType);
			setConnectionType(connectionType);
			if(maxConnections)
				setCanConnect(true);
			else
				setCanConnect(false);
			setMaxConnections(maxConnections);
			setCurrentNumberOfConnections(0);
		}

		~LinkerNode(){}

	protected:
		bool canConnect;
		string connectionType;
		int maxConnection;
		int currentNumberOfConnections;
};