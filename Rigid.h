#ifndef _RIGID_GUARD
#define _RIGID_GUARD 1

#include <vector>

#include "EdgeAggregator.h"
#include "Molecule.h"

typedef struct
{
	int id;
	std::string atomType;
}branchType;

class Rigid : public Molecule
{
  public:
    Rigid() {}
    ~Rigid() {}

	std::vector<branchType> branches;

    std::vector<EdgeAggregator> Compose(const Molecule&);
    bool Equals(const Molecule&) const;

  private:

};

#endif