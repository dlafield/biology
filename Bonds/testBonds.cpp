#include <vector>
#include <iostream>
#include <cstdio>
#include <string>

#include "Bonds.h"

void displayBond(Bonds *a)
{
	eTypeOfBondT typeOfBond;
	eStatusBitT statusBit;

	typeOfBond = a->gettypeOfBond();
	statusBit = a->getstatusBit();

	/* print id */
	std::cout << "ID = " << a->getbondID() << std::endl;

	/* print origin atom id */
	std::cout << "source id = " << a->getoriginAtomID() << std::endl;

	/* print target atom id */
	std::cout << "target id = " << a->gettargetAtomID() << std::endl;

	/* print type of bond */
	std::cout << "type of bond = ";
	switch(typeOfBond)
	{
		case 1:
			std::cout << "1" << std::endl;
			break;
		case 2:
			std::cout << "2" << std::endl;
			break;
		case 3:
			std::cout << "3" << std::endl;
			break;
		case am:
			std::cout << "am" << std::endl;
			break;
		case ar:
			std::cout << "ar" << std::endl;
			break;
		case du:
			std::cout << "du" << std::endl;
			break;
		case un:
			std::cout << "un" << std::endl;
			break;
		case nc:
			std::cout << "nc" << std::endl;
			break;
		default:
			std::cout << "error:" << std::endl;
			break;
	}

	/* print status bit */
	std::cout << "status bit = ";
	switch(statusBit)
	{
		case TYPECOL:
			std::cout << "TYPECOL" << std::endl;
			break;
		case GROUP:
			std::cout << "GROUP" << std::endl;
			break;
		case CAP:
			std::cout << "CAP" << std::endl;
			break;
		case BACKBONE:
			std::cout << "BACKBONE" << std::endl;
			break;
		case DICT:
			std::cout << "DICT" << std::endl;
			break;
		case INTERRES:
			std::cout << "INTERRES" << std::endl;
			break;
		default:
			std::cout << "error:" << std::endl;
			break;
	}

}

int main()
{
	Bonds *b;


	b = new Bonds(1, 2, 3, nc, BACKBONE);

	displayBond(b);

	std::cout << "done" << std::endl;

    return 0;
}
