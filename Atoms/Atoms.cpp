#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

#include "Atoms.h"

/***************************************************************************************************************/

void Atoms::pushBond(int x)
{
	this->bonds.push_back(x);
	if(this->bonds.size() == maxConnect)
		this->canConnect = false;
}

void Atoms::pushConnectionType(std::string x)
{
	this->connectionType.push_back(x);
}

bool Atoms::addBond (Atoms a)
{ 
	int x;
	bool canConnectToThis, canConnectToA;
	std::string s1;
	std::string s2;

	/* determine of both atoms can connect */
	if(!(this->getCanConnect()))
		return false;

	if(!a.getCanConnect())
		return false;

	/* search for matching connection types */
	canConnectToThis = false;
	for(x = 0; !canConnectToThis && x < this->numberOfConnectionTypes(); x++)
	{
		if(this->getConnectionType(x) == a.getConnectType())
		//if(strcmp(this->getConnectionType(x), a.getConnectType()) == 0)
		//if(this->getConnectionType(x).compare(a.getConnectType()) == 0)
			/*
		s1 = new std::string(this->getConnectionType(x));
		s2 = new std::string(a.getConnectType());
		if(s1.compare(s2) == 0)
		*/
			canConnectToThis = true;
	}

	if(!canConnectToThis)
		return false;

	canConnectToA = false;
	for(x = 0; !canConnectToA && x < a.numberOfConnectionTypes(); x++)
		if(a.getConnectionType(x) == this->getConnectType())
			canConnectToA = true;

	if(!canConnectToA)
		return false;

	/* the connection can take place, so connect */
	this->pushBond(a.getAtomID());
	a.pushBond(this->getAtomID());
	return true;

} /* addBond */

