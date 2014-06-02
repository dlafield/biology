#include <vector>
#include <iostream>
#include <cstdio>
#include <string>

#include "Atoms.h"

void displayAtom(Atoms *a)
{
	int x;

	//printf("ID = %d\ntype = %s\ncanConnect = ", a->getAtomID(), a->getAtomType());
	std::cout << "ID = " << a->getAtomID() << std::endl;
	std::cout << "atom type = " << a->getAtomType() << std::endl;
	std::cout << "canConnect ";

	if(a->getCanConnect())
		//printf("yes\n");
		std::cout << "yes" << std::endl;
	else
		//printf("no\n");
		std::cout << "no" << std::endl;

	//printf("max connect = %d\nconnect type = %d\nnumber of bonds = %d\nnumber of connection types = %d\n", a->getMaxConnect(), a->getConnectType(), a->numberOfBonds(), a->numberOfConnectionTypes());
	std::cout << "max connect = " << a->getMaxConnect() << std::endl;
	std::cout << "connect type = " << a->getConnectType() << std::endl;
	std::cout << "number of bonds = " << a->numberOfBonds() << std::endl;
	std::cout << "number of connection types = " << a->numberOfConnectionTypes() << std::endl;

	if(a->numberOfBonds())
	{
		//printf("Bonds:\n");
		std::cout << "Bonds:" << std::endl;
		for(x = 0; x < a->numberOfBonds(); x++)
			//printf("\t\tbond %d = %d\n", x, a->getBond(x));
			std::cout << "\t\tbond " << x << " = " << a->getBond(x) << std::endl;
	}

	if(a->numberOfConnectionTypes())
	{
		//printf("Connection types:\n");
		std::cout << "Connection types:" << std::endl;
		for(x = 0; x < a->numberOfConnectionTypes(); x++)
			//printf("\t\tconnection type %d = %s\n", x, a->getConnectionType(x));
			std::cout << "\t\tconnection type " << x << " = " << a->getConnectionType(x) << std::endl;
	}

}

int main()
{
	Atoms *cantConnect, *carbonLikesOxygen, *oxygenLikesCarbon, *oxygenLikesCarbon2, *nitrogenLotsOfBonds;
	int x;

	cantConnect = new Atoms(1, "C.3", 0, "C.3");

	carbonLikesOxygen = new Atoms(2, "C.3", 1, "C.3");
	carbonLikesOxygen->pushConnectionType("O.3");

	oxygenLikesCarbon = new Atoms(3, "O.3", 1, "O.3");
	oxygenLikesCarbon->pushConnectionType("C.3");

	oxygenLikesCarbon2 = new Atoms(3, "O.3", 1, "O.3");
	oxygenLikesCarbon2->pushConnectionType("C.3");

	nitrogenLotsOfBonds = new Atoms(4, "N.3", 900, "N.3");
	nitrogenLotsOfBonds->pushConnectionType("O.3");

	/* display cant connect */
	//printf("cantConnect\n");
	std::cout << "cantConnect" << std::endl;
	displayAtom(cantConnect);
	//printf("\n");
	std::cout << std::endl;

	/* display cLo */
	//printf("carbon likes oxygen\n");
	std::cout << "carbon likes oxygen" << std::endl;
	displayAtom(carbonLikesOxygen);
	//printf("\n");
	std::cout << std::endl;

	/* display oLc */
	//printf("oxygen likes carbon 1\n");
	std::cout << "oxygen likes carbon 1" << std::endl;
	displayAtom(oxygenLikesCarbon);
	//printf("\n");
	std::cout << std::endl;

	/* display oLc2 */
	//printf("oxygen likes carbon 2\n");
	std::cout << "oxygen likes carbon 2" << std::endl;
	displayAtom(oxygenLikesCarbon2);
	//printf("\n");
	std::cout << std::endl;

	/* display nitrogen */
	//printf("nitrogen\n");
	std::cout << "nitrogen" << std::endl;
	displayAtom(nitrogenLotsOfBonds);
	//printf("\n");
	std::cout << std::endl;

	/* try to connect cant connect (maxBond is zero, should fail) */
	if(cantConnect->addBond(*carbonLikesOxygen))
		//printf("BAD, cantConnect was successfully connected\n");
		std::cout << "BAD, cantConnect was successfully connected" << std::endl;
	else
		//printf("GOOD, cantConnect\n");
		std::cout << "GOOD, cantConnect" << std::endl;

	/* try to connect oxygen to nitrogen (oxygen doesn't like nitrogen, this atom fail) */
	if(oxygenLikesCarbon->addBond(*nitrogenLotsOfBonds))
		//printf("BAD, oxygen could connect to nitrogen, even though oxygen doesn't like nitrogen\n");
		std::cout << "BAD, oxygen could connect to nitrogen, even though oxygen doesn't like nitrogen" << std::endl;
	else
		//printf("GOOD, oxygen-nitrogen fail\n");
		std::cout << "GOOD, oxygen-nitrogen fail" << std::endl;

	/* try to connect nitrogen to oxygen (oxygen doesn't like nitrogen, foreign atom fail) */
	if(nitrogenLotsOfBonds->addBond(*oxygenLikesCarbon))
		//printf("BAD, nitrogen could connect to oxygen, even though oxygen doesn't like nitrogen\n");
		std::cout << "BAD, nitrogen could connect to oxygen, even though oxygen doesn't like nitrogen" << std::endl;
	else
		//printf("GOOD, nitrogen-oxygen fail\n");
		std::cout << "GOOD, nitrogen-oxygen fail" << std::endl;

	/* connect carbon to oxygen (success, but maxBond is met) */
	if(carbonLikesOxygen->addBond(*oxygenLikesCarbon))
		//printf("GOOD, carbon-oxygen bond successful\n");
		std::cout << "GOOD, carbon-oxygen bond successful" << std::endl;
	else
		//printf("BAD, carbon-oxygen bond failed dispite carbon and oxygen liking eachotehr\n");
		std::cout << "BAD, carbon-oxygen bond failed dispite carbon and oxygen liking eachotehr" << std::endl;

	/* try to connect carbon to oxygen 2 (fails because carbon's maxBond was met in last test) */
	if(carbonLikesOxygen->addBond(*oxygenLikesCarbon2))
		//printf("BAD, carbon-oxygen bond succeeded, even though carbon was maxed out\n");
		std::cout << "BAD, carbon-oxygen bond succeeded, even though carbon was maxed out" << std::endl;
	else
		//printf("GOOD, carbon-oxygen bond failed because carbon was maxed out\n");
		std::cout << "GOOD, carbon-oxygen bond failed because carbon was maxed out" << std::endl;

	/* display cant connect */
	//printf("cantConnect\n");
	std::cout << "cantConnect" << std::endl;
	displayAtom(cantConnect);
	//printf("\n");
	std::cout << std::endl;

	/* display cLo */
	//printf("carbon likes oxygen\n");
	std::cout << "carbon likes oxygen" << std::endl;
	displayAtom(carbonLikesOxygen);
	//printf("\n");
	std::cout << std::endl;

	/* display oLc */
	//printf("oxygen likes carbon 1\n");
	std::cout << "oxygen likes carbon 1" << std::endl;
	displayAtom(oxygenLikesCarbon);
	//printf("\n");
	std::cout << std::endl;

	/* display oLc2 */
	//printf("oxygen likes carbon 2\n");
	std::cout << "oxygen likes carbon 2" << std::endl;
	displayAtom(oxygenLikesCarbon2);
	//printf("\n");
	std::cout << std::endl;

	/* display nitrogen */
	//printf("nitrogen\n");
	std::cout << "nitrogen" << std::endl;
	displayAtom(nitrogenLotsOfBonds);
	//printf("\n");
	std::cout << std::endl;

	//printf("done\n");
	std::cout << "done" << std::endl;

    return 0;
}
