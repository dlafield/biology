#ifndef _MOLECULE_GUARD
#define _MOLECULE_GUARD 1

#include <string>
#include <vector>

class EdgeAggregator;

typedef enum
{
	1=1,
	2=2,
	3=3,
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
	
class Bond
{
  public:
	int id;
	int originAtomID;
	int targetAtomID;
	eTypeOfBondT typeOfBond;
	eStatusBitT statusBit;
	
    Bond() {}
    ~Bond() {}

	int Parse(char buffer[]);
	
    std::string toString() const;
	operator int() {return id;}

  private:
    int edgeID;
	void SetValues(int id_p, int originAtom_p, int targetAtom_p, char bondType_p[],  char statusBit_p[]);
};

#endif