#include <iostream>
#include <cstring>
#include <vector>

#include "Atoms.h"

/***************************************************************************************************************/

bool Atoms::addBond (Atoms a)
{ 
	int x;
	bool canConnectToThis, canConnectToA;

	/* determine of both atoms can connect */
	if(!this.getCanConnect())
		return false;

	if(!a.getCanConnect())
		return false;

	/* search for matching connection types */
	canConnectToThis = false;
	for(x = 0; !canConnectToThis && x < this.numberOfConnectionTypes(); x++)
		if(strcmp(this.getConnectionType(x), a.getConnectType())
			canConnectToThis = true;

	if(!canConnectToThis)
		return false;

	canConnectToA = false;
	for(x = 0; !canConnectToA && x < a.numberOfConnectionTypes(); x++)
		if(strcmp(a.getConnectionType(x), this.getConnectType())
			canConnectToA = true;

	if(!canConnectToA)
		return false;

	/* the connection can take place, so connect */
	this.pushBond(a);
	a.pushBond(this);
	return true;

} /* addBond */
