#ifndef _MOLECULE_GUARD
#define _MOLECULE_GUARD 1

#include <string>
#include <vector>

class EdgeAggregator;

typedef enum
{
	DSPMOD=1,
	TYPECOL=2,
	CAP=3,
	BACKBONE=4,
	DICT=5,
	ESSENTIAL=6,
	WATER=7,
	DIRECT=8,
	UNASSIGNED=-1
} eStatusBitT;

class Atoms
{
  public:

	int id;
	int subst_id;
	eStatusBitT statusBit;
	std::string name;
	std::string typeOfAtom;
	std::string subst_name;
	float x;
	float y;
	float z;
	float charge;
	int maxNumberOfContacts;	//linkers only
	std::string contactAtomType;	//linkers only
	
    Atoms() {}
    ~Atoms() {}

	int Parse(char buffer[]);
	
    std::string toString() const;
	operator int() {return id;}

  private:
    int nodeID;
	void SetValues(int id_p, char name_p[], float x_p, float y_p, float z_p, char atomType_p[], int subst_id_p, char subst_name_p[], float charge_p, char statusBit_p[]);
};

#endif