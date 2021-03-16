#ifndef DEF_COMPORTEMENTGREGAIRE
#define DEF_COMPORTEMENTGREGAIRE

#include <vector>
#include <iostream>
#include "IComportement.h"
#include "Bestiole.h"

class ComportementGregaire : public IComportement {
	public :
	ComportementGregaire();
	std::tuple<vector<double, double>, double> calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee);
};

#endif