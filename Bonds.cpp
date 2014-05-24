#include <cstring>
#include <vector>

#include "Bonds.h"

void Atoms::SetValues(int id_p, int originAtom_p, int targetAtom_p, char bondType_p[],  char statusBit_p[])
{
	/* set literal values */
	this.id = id_p;
	this.originAtomID = originAtom_p;
	this.targetAtomID = targetAtom_p;
	this.fSource = fSource;
	
	/* Because the bondType is a string with only 8 possible values, I'll store it as an integer */
	if(strcmp(bondType_p, "1") == 0)
		this.typeOfBond = 1;
	if(strcmp(bondType_p, "2") == 0)
		this.typeOfBond = 2;
	if(strcmp(bondType_p, "3") == 0)
		this.typeOfBond = 3;
	if(strcmp(bondType_p, "am") == 0)
		this.typeOfBond = am;
	if(strcmp(bondType_p, "ar") == 0)
		this.typeOfBond = ar;
	if(strcmp(bondType_p, "du") == 0)
		this.typeOfBond = du;
	if(strcmp(bondType_p, "un") == 0)
		this.typeOfBond = un;
	if(strcmp(bondType_p, "nc") == 0)
		this.typeOfBond = nc;
	
	/* Because the statusBit is a string with only 6 possible values, I'll store it as an integer */
	this.statusBit = UNASSIGNED;	/* the default value, if the status bit is unassigned */
	if(strcmp(statusBit_p, "TYPECOL") == 0)
		this.statusBit = TYPECOL;
	if(strcmp(statusBit_p, "GROUP") == 0)
		this.statusBit = GROUP;
	if(strcmp(statusBit_p, "CAP") == 0)
		this.statusBit = CAP;
	if(strcmp(statusBit_p, "BACKBONE") == 0)
		this.statusBit = BACKBONE;
	if(strcmp(statusBit_p, "DICT") == 0)
		this.statusBit = DICT;
	if(strcmp(statusBit_p, "INTERRES") == 0)
		this.statusBit = INTERRES;
}

/****************************************************************************************/

int Atoms::Parse(char buffer[])
{
	int index = 0;
	int endOfString;
	char temp[500];
	int tempLength;
	int id, subst_id;
	char name[100], typeOfAtom[10], subst_name[100], statusBit[100];
	float x, y, z, charge;

	/* initialization*/
	subst_id = -1;
	strcpy(subst_name, "");
	charge = 0.0;
	strcpy(statusBit, "");

	/* get id */
	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	id = buffer[index] - '0';
	index++;

	while(buffer[index] != ' ' && buffer[index] != '\t' && buffer[index] != '\n' && buffer[index] != '\0')
	{ /* parse number */

		id *= 10;
		id += buffer[index] - '0';
		index++;
	} /* parse number */

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	/* get name */
	sscanf(buffer + index, " %s", name);
	index += strlen(name);

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	/* get x */
	sscanf(buffer + index, " %f", &x);
	while(buffer[index] != ' ' && buffer[index] != '\t')		//get past non-white space
		index++;

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	/* get y */
	sscanf(buffer + index, " %f", &y);
	while(buffer[index] != ' ' && buffer[index] != '\t')		//get past non-white space
		index++;

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	/* get z */
	sscanf(buffer + index, " %f", &z);
	while(buffer[index] != ' ' && buffer[index] != '\t')		//get past non-white space
		index++;

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	/* get type of item */
	sscanf(buffer + index, " %s", typeOfAtom);
	index += strlen(typeOfAtom);

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	if(buffer[index] != '\n' && buffer[index] != '\0')
	{ /* if not end of line */

		/* get subst_id */
		subst_id = buffer[index] - '0';
		index++;

		while(buffer[index] != ' ' && buffer[index] != '\t' && buffer[index] != '\n' && buffer[index] != '\0')
		{ /* parse number */

			subst_id *= 10;
			subst_id += buffer[index] - '0';
			index++;

		} /* parse number */
	} /* if not end of line */

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	if(buffer[index] != '\n' && buffer[index] != '\0')
	{ /* if not end of line */

		/* get subst_name */
		sscanf(buffer + index, " %s", subst_name);
		index += strlen(subst_name);

	} /* if not end of line */

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	if(buffer[index] != '\n' && buffer[index] != '\0')
	{ /* if not end of line */

		/* get charge */
		sscanf(buffer + index, " %f", &charge);
		while(buffer[index] != ' ' && buffer[index] != '\t' && buffer[index] != '\n' && buffer[index] != '\0')		//get past non-white space
			index++;

	} /* if not end of line */

	while(buffer[index] == ' ' || buffer[index] == '\t')		//get past white space
		index++;

	if(buffer[index] != '\n' && buffer[index] != '\0')
	{ /* if not end of line */

		/* get status_bit */
		sscanf(buffer + index, " %s", statusBit);

	} /* if not end of line */

	/* set atom values */
	SetValues(id, name, x, y, z, typeOfAtom, subst_id, subst_name, charge, statusBit);

} /* parseMolecule */

/****************************************************************************************/

bool Bonds::Equals(const Bonds&) const
{
    return false;
}

std::ostream& operator<< (std::ostream& os, Bonds& mol)
{
    os << mol.toString();
    
    return os;
}