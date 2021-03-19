#ifndef DEF_COMPORTEMENTGREGAIRE
#define DEF_COMPORTEMENTGREGAIRE

#include <vector>
#include <iostream>
#include "IComportement.h"

class ComportementGregaire : public IComportement {
	public :
	ComportementGregaire();
	~ComportementGregaire();
	std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return GREG; };
};

#endif