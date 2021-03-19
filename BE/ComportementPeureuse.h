#ifndef DEF_COMPORTEMENTPEUREUSE
#define DEF_COMPORTEMENTPEUREUSE

#include <iostream>
#include "IComportement.h"
#include <vector>

class ComportementPeureuse : public IComportement {
	private:
	// nb de voisins à partir duquel la bestiole change de direction et vitesse
	int m_seuil;

public:
	ComportementPeureuse(int seuil);
	ComportementPeureuse();
	~ComportementPeureuse();
	std::tuple<vector<double>, double> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
	ComportType getComportementType() { return PEUR; };
	int getSeuil();
};

#endif
