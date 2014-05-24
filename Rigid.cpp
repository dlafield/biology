#include <cstring>
#include <vector>

#include "Rigid.h"
#include "EdgeAggregator.h"

std::vector<EdgeAggregator> Rigid::Compose(const Molecule& thatMolecule)
{
    std::vector<EdgeAggregator> newMolecules;
    
    
    
    return newMolecules;
}

bool Rigid::Equals(const Molecule&) const
{

    return false;
}

std::ostream& operator<< (std::ostream& os, Rigid& rigid)
{

    return os;
}

std::parse (FILE *f, int id)
{
	// f should be open for reading 
	// id should be the size of the vector
	int x, atomNumber;
	char buffer[500], contactAtomType[10];
	char moleculeName[500], moleculeStats[500], typeOfMolecule[500], moleculeCharge[500], moleculeStatusBits[500], comments[500];
	Atoms thisAtom;
	Bonds thisBond;
	branchType thisBranch;

	/* initialize strings */
	strcpy(moleculeName, "");
	strcpy(moleculeStats, "");
	strcpy(typeOfMolecule, "");
	strcpy(moleculeCharge, "");
	strcpy(moleculeStatusBits, "");
	strcpy(comments, "");

	/* read first line of file */
	fscanf(f, " %[^\n]", buffer);

	/* read name of molecule */
	fscanf(f, " %[^\n]", moleculeName);

	/* read molecule stats line */
	fscanf(f, " %[^\n]", moleculeStats);

	/* read molecule type */
	fscanf(f, " %[^\n]", typeOfMolecule);

	/* read charge type */
	fscanf(f, " %[^\n]", moleculeCharge);

	/* read line into buffer */
	fscanf(f, " %[^\n]", buffer);

	if(buffer[0] != '@')
	{ /* if buffer doesn't start with @ */

		/* copy buffer into status bits */
		strcpy(moleculeStatusBits, buffer);

		/* read line into buffer */
		fscanf(f, " %[^\n]", buffer);

		if(buffer[0] != '@')
		{ /* if buffer doesn't start with @ */

			/* copy buffer into comments */
			strcpy(comments, buffer);

		} /* if buffer doesn't start with @ */

	} /* if buffer doesn't start with @ */

	Parse(moleculeName, moleculeStats, typeOfMolecule, moleculeCharge, moleculeStatusBits, comments);
	this.id = id;

	/* get header for atoms */
	while(!feof(f) && buffer[0] != '@')
		fscanf(f, " %[^\n]", buffer);

	/*** get atoms ***/

	/* read line from file */
	fscanf(f, " %[^\n]", buffer);

	while(!feof(f) && buffer[0] != '@')
	{ /* while not eof and line doesn't start with @ */
				
		/* parse atom */
		thisAtom = new Atom();

		parseAtom(buffer);

		/* add atom to molecule */
		this.atoms.push_back(thisAtom);

		/* read line from file */
		fscanf(f, " %[^\n]", buffer);
			
	} /* while not eof and line doesn't start with @ */

	/*** get bonds ***/

	/* read line from file */
	fscanf(f, " %[^\n]", buffer);

	while(!feof(fromFile) && strstr(buffer, "END") == NULL)
	{ /* while not eof and line doesn't have "END" */

		/* parse bond */
		thisBond = new Bond();
		Parse(buffer);
		
		/* add bond to molecule */
		this.bonds.push_back(thisBond);

		/* read line from file */
		fscanf(f, " %[^\n]", buffer);

	} /* while not eof and line doesn't have "END" */

	/*** get rules ***/

	/* we deliberately skip the ATOMTYPES section 
		because the atomtypes are already determined */

	/* get to the start of rules */
	while(!feof(fromFile) && strstr(buffer, "BRANCH ") == NULL)
		fscanf(f, " %[^\n]", buffer);

	/* read line from file */
	fscanf(f, " %[^\n]", buffer);

	while(!feof(fromFile) && strstr(buffer, "$") == NULL)
	{ /* for each branch */

		sscanf(buffer, "%d %s", &atomNumber, contactAtomType);
		thisBranch.id = atomNumber;
		strcpy(thisBranch.atomType, contactAtomType);
		this.branches.push_back(thisBranch);

		/* read line from file */
		fscanf(f, " %[^\n]", buffer);

	} /* for each branch */

} /* parse */
