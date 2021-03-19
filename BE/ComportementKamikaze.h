#ifndef DEF_COMPORTEMENTKAMIKAZE
#define DEF_COMPORTEMENTKAMIKAZE

#include <iostream>
#include "IComportement.h"
#include <vector>

class ComportementKamikaze : public IComportement {
	private :
	// coefficient multiplicateur de la vitesse pour attaquer une bestiole
	static const int m_coefAttaque;
	public:
	ComportementKamikaze();
	~ComportementKamikaze();
	std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return KAMIK; };
};

// ajout d'une fonction pour calculer la distance entre deux points
double calculDistance(int xA, int yA, int xB, int yB);

#endif
