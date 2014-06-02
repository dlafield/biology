#include <string>
#include <vector>

class Atoms
{
  public:
	int getAtomID()
	{
		return this.atomID;
	}

	void setAtomID(int x)
	{
		this.atomID = x;
	}

	string getAtomType()
	{
		return this.atomType;
	}

	void setAtomType(string x)
	{
		this.atomType = x;
	}

	bool getCanConnect()
	{
		return this.canConnect;
	}

	void setCanConnect(bool x)
	{
		this.canConnect = x;
	}

	int getMaxConnect()
	{
		return this.maxConnect;
	}

	void setMaxConnect(int x)
	{
		this.maxConnect = x;
	}

	string getConnectType()
	{
		return this.connectType;
	}

	void setConnectType(string x)
	{
		this.connectType = x;
	}

	int getBond(int index)
	{
		return this.bonds.at(index);
	}

	void pushBond(int x)
	{
		this.bonds.push_back(x);
		if(this.bonds.size() >= maxConnect)
			this.canConnect = false;
	}

	int numberOfBonds()
	{
		return this.bonds.size();
	}

	int numberOfConnectionTypes()
	{
		return this.connectionType.size();
	}
	
	string getConnectionType(int index)
	{
		return this.connectionType.at(index);
	}

	void pushConnectionType(string x)
	{
		this.connectionType.push_back(x);
	}

	Atoms(int id, string aType, int maxConn, string connType)
	{
		this.atomID = id;
		strcpy(this.atomType, aType);
		this.maxConnect = maxConn;
		this.canConnect = (maxConn > 0);
		strcpy(this.connectType, connType);
	}

	~Atoms() {}

  private:
    int atomID;
	std::string atomType;
	bool canConnect;
	int maxConnect;
	std::string connectType;
	vector<int> bonds;
	vector<string> connectionType;
};

#endif