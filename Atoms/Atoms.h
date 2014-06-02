#include <string>
#include <vector>

class Atoms
{
  private:
    int atomID;
	std::string atomType;
	bool canConnect;
	int maxConnect;
	std::string connectType;
	std::vector<int> bonds;
	std::vector<std::string> connectionType;

  public:
	int getAtomID()
	{
		return this->atomID;
	}

	void setAtomID(int x)
	{
		this->atomID = x;
	}

	std::string getAtomType()
	{
		return this->atomType;
	}

	void setAtomType(std::string x)
	{
		this->atomType = x;
	}

	bool getCanConnect()
	{
		return this->canConnect;
	}

	void setCanConnect(bool x)
	{
		this->canConnect = x;
	}

	int getMaxConnect()
	{
		return this->maxConnect;
	}

	void setMaxConnect(int x)
	{
		this->maxConnect = x;
	}

	std::string getConnectType()
	{
		return this->connectType;
	}

	void setConnectType(std::string x)
	{
		this->connectType = x;
	}

	int getBond(int index)
	{
		return this->bonds.at(index);
	}

	int numberOfBonds()
	{
		return this->bonds.size();
	}

	int numberOfConnectionTypes()
	{
		return this->connectionType.size();
	}
	
	std::string getConnectionType(int index)
	{
		return this->connectionType.at(index);
	}

	Atoms(int id, std::string aType, int maxConn, std::string connType)
	{
		this->atomID = id;
		this->atomType = aType;
		this->maxConnect = maxConn;
		this->canConnect = (maxConn > 0);
		this->connectType = connType;
	}

	bool addBond (Atoms a);
	void pushBond(int x);
	void pushConnectionType(std::string x);

	~Atoms() {}

};