#include <string>
#include <vector>

typedef enum 
{
	/*1=1,
	2=2,
	3=3,*/
	am=4,
	ar=5,
	du=6,
	un=7,
	nc=8
} eTypeOfBondT;
	
typedef enum 
{
	UNASSIGNED=-1,
	TYPECOL=1,
	GROUP=2,
	CAP=3,
	BACKBONE=4,
	DICT=5,
	INTERRES=6
} eStatusBitT;

class Bonds
{
  private:
    int bondID;
	int originAtomID;
	int targetAtomID;
	eTypeOfBondT typeOfBond;
	eStatusBitT statusBit;

  public:
	int getbondID()
	{
		return this->bondID;
	}

	void setbondID(int x)
	{
		this->bondID = x;
	}

	int getoriginAtomID()
	{
		return this->originAtomID;
	}

	void setoriginAtomID(int x)
	{
		this->originAtomID = x;
	}

	int gettargetAtomID()
	{
		return this->targetAtomID;
	}

	void settargetAtomID(int x)
	{
		this->targetAtomID = x;
	}

	eTypeOfBondT gettypeOfBond()
	{
		return this->typeOfBond;
	}

	void settypeOfBond(eTypeOfBondT x)
	{
		this->typeOfBond = x;
	}

	eStatusBitT getstatusBit()
	{
		return this->statusBit;
	}

	void setstatusBit(eStatusBitT x)
	{
		this->statusBit = x;
	}

	Bonds(int id, int origin, int target, eTypeOfBondT b, eStatusBitT s)
	{
		this->bondID = id;
		this->originAtomID = origin;
		this->targetAtomID = target;
		this->typeOfBond = b;
		this->statusBit = s;
	}

	~Bonds() {}

};