#ifndef DEF_COMPORTEMENTKAMIKAZE
#define DEF_COMPORTEMENTKAMIKAZE

#include <iostream>
#include "IComportement.h"
#include "Bestiole.h"
#include <tuple>
#include <vector>

class ComportementKamikaze : public IComportement {
	private :
	double m_coefAttaque;
	public:
	ComportementKamikaze();
	std::tuple<vector<double, double>, double> calculDirection(vector<Bestiole> voisins, Bestiole bestioleAssociee);
};

double calculDistance(int xA, int yA, int xB, int yB);

#endif
