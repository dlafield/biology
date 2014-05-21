#include <vector>
#include <iostream>

using namespace std;

#include moleculeClass.h

extern "C"
{
	typedef struct
	{
		int id, maxNumOfContacts;
	} maxNumOfContactsPair;
}

class LinkerClass: public MoleculeClass 
{
	public:
		addMaxContact(int id, int maxNumOfContacts)
		{
			maxNumOfContactsPair x;
			x.id = id;
			x.maxNumOfContacts = maxNumOfContacts;
			maxNumOfContacts.push_back(x);
		}
	private:
		vector<int> maxNumOfContacts;

} 