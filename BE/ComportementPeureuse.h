#ifndef DEF_COMPORTEMENTPEUREUSE
#define DEF_COMPORTEMENTPEUREUSE

#include <iostream>
#include "IComportement.h"
#include "Bestiole.h"
#include <tuple>
#include <vector>

class ComportementPeureuse : public IComportement {
	private:
	int m_seuil;

public:
	ComportementPeureuse(int seuil);
	std::tuple<vector<double, double>, double> calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee);
};

#endif
