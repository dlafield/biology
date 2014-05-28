#include <vector>
#include <iostream>
#include <openbabel/mol.h>

using namespace std;

class MoleculeClass
{
	public:
		MoleculeClass()
		{
			m = new OBMol();
		}

		~MoleculeClass(){}

	protected:
		OBMol m;
		vector<MoleculeEdge> bonds;
};
