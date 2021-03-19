#ifndef DEF_COMPORTEMENTKAMIKAZE
#define DEF_COMPORTEMENTKAMIKAZE

#include <iostream>
#include "IComportement.h"
#include <vector>

class ComportementKamikaze : public IComportement {
	private :
	static const int m_coefAttaque;
	public:
	ComportementKamikaze();
	~ComportementKamikaze();
	std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return KAMIK; };
};

double calculDistance(int xA, int yA, int xB, int yB);

#endif
