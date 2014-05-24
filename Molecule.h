#ifndef _MOLECULE_GUARD
#define _MOLECULE_GUARD 1

#include <string>
#include <vector>

class EdgeAggregator;
class Atoms;
class Bonds;

typedef enum
{
	SMALL=1,
   BIOPOLYMER=2,
   PROTEIN=3,
   NUCLEIC_ACID=4,
   SACCHARIDE=5
} eTypeOfMoleculeT;

typedef enum
{
	NO_CHARGES=1,
   DEL_RE=2,
   GASTEIGER=3,
   GAST_HUCK=4,
   HUCKEL=5,
   PULLMAN=6,
   GAUSS80_CHARGES=7,
   AMPAC_CHARGES=8,
   MULLIKEN_CHARGES=9,
   DICT_CHARGES=10,
   MMFF94_CHARGES=11,
   USER_CHARGES=12
} eTypeOfChargeT;

typedef enum
{
	SYSTEM=1,
   INVALID_CHARGES=2,
   ANALYZED=3,
   SUBSTITUTED=4,
   ALTERED=5,
   REF_ANGLE=6
} eStatusBitT;

class Molecule
{
  public:
    int id;
    int numAtoms;
    int numBonds;
    int numSubStructs;
    int numFeatures;
    int numSets;
    eTypeOfMoleculeT typeOfMolecule;
    eTypeOfChargeT chargeType;
    eStatusBitT statusBits;
	 std::string name;
    std::string comments;
	std::vector<Atoms> atoms;
	std::vector<Bonds> bonds;

    Molecule() {}
    ~Molecule() {}

    void setGraphID(int id) { graphID = id; }
    int getGraphID() { return graphID; }
    virtual std::vector<EdgeAggregator> Compose(const Molecule&);
    virtual bool Equals(const Molecule&) const;

    void SetValues(char name_p[], int numAtoms_p, int numBonds_p, int numSubStructs_p, int numFeatures_p, int numSets_p, char moleculeType_p[], char chargeType_p[], char statusBit_p[], char comments_p[]);
    int Parse(char moleculeName[], char moleculeStats[], char typeOfMolecule[], char moleculeCharge[], char moleculeStatusBits[], char comments[]);

    std::string toString() const;
    friend std::ostream& operator<< (std::ostream& os, Molecule& mol);
	operator int() {return id;}

  private:
    int graphID;
};

#endif