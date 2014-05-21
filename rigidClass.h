#include <vector>
#include <iostream>

using namespace std;

#include moleculeClass.h

extern "C"
{
	typedef struct
	{
		int id;
		string typeOfAtom;
	} branchPair;
}


class RigidClass: public MoleculeClass 
{
	public:
		addBranch(int id, string typeOfAtom)
		{
			branchPair x;
			x.id = id;
			x.typeOfAtom = typeOfAtom;
			branches.push_back(x);
		}
	private:
		vector<branchPair> branches;
} 