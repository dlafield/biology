#include <cstring>
#include <vector>

#include "Atoms.h"

void Atoms::SetValues(int id_p, std::string name_p, float x_p, float y_p, float z_p, std::string atomType_p, int subst_id_p, std::string subst_name_p, float charge_p, std::string statusBit_p)
{
	/* set literal values */
	this.id = id_p;
	strcpy(this.name, name_p);
	this.x = x_p;
	this.y = y_p;
	this.z = z_p;
	strcpy(this.typeOfAtom, atomType_p);
	this.subst_id = subst_id_p;
	strcpy(this.subst_name, subst_name_p);
	this.charge = charge_p;
	
	/* Because the statusBit is a string with only 8 possible values, I'll store it as an integer */
	this.statusBit = UNASSIGNED;	/* the default value, if the status bit is unassigned */
	if(strcmp(statusBit_p, "DSPMOD") == 0)
		this.statusBit = DSPMOD;
	if(strcmp(statusBit_p, "TYPECOL") == 0)
		this.statusBit = TYPECOL;
	if(strcmp(statusBit_p, "CAP") == 0)
		this.statusBit = CAP;
	if(strcmp(statusBit_p, "BACKBONE") == 0)
		this.statusBit = BACKBONE;
	if(strcmp(statusBit_p, "DICT") == 0)
		this.statusBit = DICT;
	if(strcmp(statusBit_p, "ESSENTIAL") == 0)
		this.statusBit = ESSENTIAL;
	if(strcmp(statusBit_p, "WATER") == 0)
		this.statusBit = WATER;
	if(strcmp(statusBit_p, "DIRECT") == 0)
		this.statusBit = DIRECT;
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

bool Atoms::Equals(const Atoms&) const
{
    return false;
}

std::string Atoms::toString() const
{
    return this->name;
}

std::ostream& operator<< (std::ostream& os, Atoms& mol)
{
    os << mol.toString();
    
    return os;
}