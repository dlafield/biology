#include <cstring>
#include <vector>

#include "Molecule.h"
#include "Atoms.h"

#include "EdgeAggregator.h"


void Molecule::SetValues(char name_p[], int numAtoms_p, int numBonds_p, int numSubStructs_p, int numFeatures_p, int numSets_p, char moleculeType_p[], char chargeType_p[], char statusBit_p[], char comments_p[])
{
	/* set literal values */
	this->name = name_p;
	this->numAtoms = numAtoms_p;
	this->numBonds = numBonds_p;
	this->numSubStructs = numSubStructs_p;
	this->numFeatures = numFeatures_p;
	this->numSets = numSets_p;
	this->comments, comments_p;

	/* Because the moleculeType is a string with only 5 possible values, I'll store it as an integer */
	this->typeOfMolecule = -1; /* default value, if the moleculeType is unassigned */
	if(strcmp(moleculeType_p, "SMALL") == 0)          this->typeOfMolecule = SMALL;
	if(strcmp(moleculeType_p, "BIOPOLYMER") == 0)     this->typeOfMolecule = BIOPOLYMER;
	if(strcmp(moleculeType_p, "PROTEIN") == 0)        this->typeOfMolecule = PROTEIN;
	if(strcmp(moleculeType_p, "NUCLEIC_ACID") == 0)   this->typeOfMolecule = NUCLEIC_ACID;
	if(strcmp(moleculeType_p, "SACCHARIDE") == 0)     this->typeOfMolecule = SACCHARIDE;

	/* Because the chargeType is a string with only 12 possible values, I'll store it as an integer */
	this->chargeType = -1; /* default value, if the chargeType is unassigned */
	if(strcmp(chargeType_p, "NO_CHARGES") == 0)       this->chargeType = NO_CHARGES;
	if(strcmp(chargeType_p, "DEL_RE") == 0)           this->chargeType = DEL_RE;
	if(strcmp(chargeType_p, "GASTEIGER") == 0)        this->chargeType = GASTEIGER;
	if(strcmp(chargeType_p, "GAST_HUCK") == 0)        this->chargeType = GAST_HUCK;
	if(strcmp(chargeType_p, "HUCKEL") == 0)           this->chargeType = HUCKEL;
	if(strcmp(chargeType_p, "PULLMAN") == 0)          this->chargeType = PULLMAN;
	if(strcmp(chargeType_p, "GAUSS80_CHARGES") == 0)  this->chargeType = GAUSS80_CHARGES;
	if(strcmp(chargeType_p, "AMPAC_CHARGES") == 0)    this->chargeType = AMPAC_CHARGES;
	if(strcmp(chargeType_p, "MULLIKEN_CHARGES") == 0) this->chargeType = MULLIKEN_CHARGES;
	if(strcmp(chargeType_p, "DICT_CHARGES") == 0)     this->chargeType = DICT_CHARGES;
	if(strcmp(chargeType_p, "MMFF94_CHARGES") == 0)   this->chargeType = MMFF94_CHARGES;
	if(strcmp(chargeType_p, "USER_CHARGES") == 0)     this->chargeType = USER_CHARGES;

	/* Because the statusBits is a string with only 6 possible values, I'll store it as an integer */
	this->statusBits = -1; /* default value, if the statusBits is unassigned */
	if(strcmp(statusBit_p, "system") == 0 || strcmp(statusBit_p, "System") == 0 || strcmp(statusBit_p, "SYSTEM") == 0)
		this->statusBits = SYSTEM;
	if(strcmp(statusBit_p, "invalid_charges") == 0 || strcmp(statusBit_p, "Invalid_charges") == 0 || strcmp(statusBit_p, "INVALID_CHARGES") == 0)
		this->statusBits = INVALID_CHARGES;
	if(strcmp(statusBit_p, "analyzed") == 0 || strcmp(statusBit_p, "Analyzed") == 0 || strcmp(statusBit_p, "ANALYZED") == 0)
		this->statusBits = ANALYZED;
	if(strcmp(statusBit_p, "substituted") == 0 || strcmp(statusBit_p, "Substituted") == 0 || strcmp(statusBit_p, "SUBSTITUTED") == 0)
		this->statusBits = SUBSTITUTED;
	if(strcmp(statusBit_p, "altered") == 0 || strcmp(statusBit_p, "Altered") == 0 || strcmp(statusBit_p, "ALTERED") == 0)
		this->statusBits = ALTERED;
	if(strcmp(statusBit_p, "ref_angle") == 0 || strcmp(statusBit_p, "Ref_angle") == 0 || strcmp(statusBit_p, "REF_ANGLE") == 0)
		this->statusBits = REF_ANGLE;

}

/****************************************************************************************/

int Molecule::Parse(char moleculeName[], char moleculeStats[], char typeOfMolecule[], char moleculeCharge[], char moleculeStatusBits[], char comments[])
{
	/*
		Input: line from file, and open file that is currently in a molecule section
		Output: molecule, and the file in the input has advanced to the next section
	*/

	int numAtoms_p; 
	int numBonds_p; 
	int numSubStructs_p; 
	int numFeatures_p; 
	int numSets_p;
	int index = 0;

	/* get number of atoms from stats */
	while(moleculeStats[index] == ' ' || moleculeStats[index] == '\t')	//get past white space
		index++;
	numAtoms_p = moleculeStats[index] - '0';
	index++;
	while(moleculeStats[index] != ' ' && moleculeStats[index] != '\t' && moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
	{ /* parse number */
		numAtoms_p *= 10;
		numAtoms_p += moleculeStats[index] - '0';
		index++;
	} /* parse number */

	while(moleculeStats[index] == ' ' || moleculeStats[index] == '\t')	//get past white space but not newline
		index++;
	
	if(moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
	{ /* if not end of line */

		/* get number of bonds */
		numBonds_p = moleculeStats[index] - '0';
		index++;
		while(moleculeStats[index] != ' ' && moleculeStats[index] != '\t' && moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
		{ /* parse number */
			numBonds_p *= 10;
			numBonds_p += moleculeStats[index] - '0';
			index++;
		} /* parse number */

	} /* if not end of line */

	while(moleculeStats[index] == ' ' || moleculeStats[index] == '\t')	//get past white space but not newline
		index++;

	if(moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
	{ /* if not end of line */

		numSubStructs_p = moleculeStats[index] - '0';
		index++;
		while(moleculeStats[index] != ' ' && moleculeStats[index] != '\t' && moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
		{ /* get num_subst */
			numSubStructs_p *= 10;
			numSubStructs_p += moleculeStats[index] - '0';
			index++;	
		} /* parse number */
	} /* if not end of line */

	while(moleculeStats[index] == ' ' || moleculeStats[index] == '\t')	//get past white space but not newline
		index++;

	if(moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
	{ /* if not end of line */
		
		numFeatures_p = moleculeStats[index] - '0';
		index++;
		while(moleculeStats[index] != ' ' && moleculeStats[index] != '\t' && moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
		{ /* get num_feat */
			numFeatures_p *= 10;
			numFeatures_p += moleculeStats[index] - '0';
			index++;
		} /* parse number */
	} /* if not end of line */

	while(moleculeStats[index] == ' ' || moleculeStats[index] == '\t')	//get past white space but not newline
		index++;

	if(moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
	{ /* if not end of line */
		
		numSets_p = moleculeStats[index] - '0';
		index++;
		while(moleculeStats[index] != ' ' && moleculeStats[index] != '\t' && moleculeStats[index] != '\n' && moleculeStats[index] != '\0')
		{ /* get num_set */
			numSets_p *= 10;
			numSets_p += moleculeStats[index] - '0';
			index++;
		} /* parse number */
	} /* if not end of line */

	/* set molecule values */
	SetValues(moleculeName, numAtoms_p, numBonds_p, numSubStructs_p, numFeatures_p, numSets_p, typeOfMolecule, moleculeCharge, moleculeStatusBits, comments);

} /* parseMolecule */

/****************************************************************************************/

std::vector<EdgeAggregator> Molecule::Compose(const Molecule& thatMolecule, int thisAtomId, int thatAtomId)
{
	int atomOffset;
	int bondOffset;
	int atomIndex, bondIndex;
	Atoms transA;
	Bonds transB, newBond;
    std::vector<EdgeAggregator> newMolecules;
    
	/* set atom offset to size of this molecule's atoms */
	atomOffset = this.atoms.size();

	/* set bond offset to size of this molecule's bonds */
	bondOffset = this.bonds.size();

	for(atomIndex = 0; atomIndex < atomOffset; atomIndex++)
	{ /* for each atom a in that molecule */

		/* add atom offset to a */
		transA = thatMolecule.atoms.at(atomIndex);
		transA.id += atomOffset;
		
		/* ISSUE -- How to handle atom coordinants in that are in that molecule?  What about the angle that the new molecule comes in at? */

		/* push a onto this molecule's atoms */
		this.atoms.push_back(transA);

	} /* for each atom a in that molecule */

	for(bondIndex = 0; bondIndex < bondOffset; bondIndex++)
	{ /* for each bond b in that molecule */

		/* add bond offset to b */
		transB = thatMolecule.bonds.at(bondIndex);
		transB.id += bondOffset;

		/* push b onto this molecule's bonds */
		this.bonds.push_back(transB);

	}/* for each bond b in that molecule */

	/* add new bond to this molecule's bonds */
	newBond = new Bond();
	newBond.id = this.bonds.size();
	newBond.originAtomID = thisAtomId;
	newBond.targetAtomID = thatAtomId;

	/* ISSUE -- what is the typeOfBond for this new bond? */
	/* ISSUE -- what is the statusBit for this new bond? */

	this.bonds.push_back(newBond);

    return newMolecules;
}

bool Molecule::Equals(const Molecule&) const
{
    return false;
}

std::string Molecule::toString() const
{
    return this->name;
}

std::ostream& operator<< (std::ostream& os, Molecule& mol)
{
    os << mol.toString();
    
    return os;
}